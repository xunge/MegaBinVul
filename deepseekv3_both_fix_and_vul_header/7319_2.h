#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

#define MAX_NR_OPTIONS 100
#define MAX_REQUEST_SIZE 4096
#define NBD_NEW_VERSION 1
#define NBD_FLAG_FIXED_NEWSTYLE 1
#define NBD_OPT_EXPORT_NAME 1
#define NBD_OPT_ABORT 2
#define NBD_OPT_STARTTLS 3
#define NBD_OPT_LIST 4
#define NBD_OPT_GO 5
#define NBD_OPT_INFO 6
#define NBD_OPT_STRUCTURED_REPLY 7
#define NBD_OPT_LIST_META_CONTEXT 8
#define NBD_OPT_SET_META_CONTEXT 9
#define NBD_REP_ERR_INVALID 1
#define NBD_REP_ERR_TLS_REQD 2
#define NBD_REP_ACK 3
#define NBD_REP_ERR_UNSUP 4
#define NBD_REP_ERR_POLICY 5
#define NBD_REP_ERR_UNKNOWN 6
#define NBD_REP_INFO 7
#define NBD_REP_META_CONTEXT 8
#define NBD_INFO_EXPORT 0
#define NBD_INFO_NAME 1
#define NBD_INFO_DESCRIPTION 2
#define NBD_FLAG_NO_ZEROES 1

struct nbd_new_option {
    uint64_t version;
    uint32_t option;
    uint32_t optlen;
};

struct nbd_export_name_option_reply {
    uint64_t exportsize;
    uint16_t eflags;
    char zeroes[124];
};

struct backend {
    int i;
    char *default_exportname;
    const char* (*export_description)(struct backend*);
    const char* (*default_export)(struct backend*, bool);
};

struct connection {
    uint32_t cflags;
    uint16_t eflags;
    bool using_tls;
    struct backend *top_context;
    char *exportname_from_set_meta_context;
    char **default_exportname;
    bool structured_replies;
    bool meta_context_base_allocation;
    int (*send)(void *, size_t, int);
    int (*recv)(void *, size_t);
    int sockin;
    int sockout;
};

static struct connection *conn;
static int tls;
static bool no_sr;
static bool read_only;
static uint32_t base_allocation_id;
static struct backend *top;

#define GET_CONN struct connection *conn = get_conn()
#define CLEANUP_FREE __attribute__((cleanup(free_cleanup)))

static inline struct connection *get_conn(void) { return conn; }
static inline void free_cleanup(char **ptr) { free(*ptr); }

/* Function declarations */
static int conn_recv_full(void *buf, size_t len, const char *fmt, ...);
static void nbdkit_error(const char *fmt, ...);
static const char *name_of_nbd_opt(uint32_t option);
static int send_newstyle_option_reply(uint32_t option, uint32_t reply);
static int check_export_name(uint32_t option, const char *data, size_t len, size_t max);
static int finish_newstyle_options(uint64_t *exportsize, const char *data, size_t len);
static void debug(const char *fmt, ...);
static int send_newstyle_option_reply_exportnames(uint32_t option, size_t *nr_options);
static int crypto_negotiate_tls(int sockin, int sockout);
static int backend_finalize(struct backend *b);
static void backend_close(struct backend *b);
static int send_newstyle_option_reply_info_export(uint32_t option, uint32_t reply, uint16_t info, uint64_t exportsize);
static const char *backend_default_export(struct backend *b, bool read_only);
static int send_newstyle_option_reply_info_str(uint32_t option, uint32_t reply, uint16_t info, const char *str, size_t len);
static const char *backend_export_description(struct backend *b);
static const char *name_of_nbd_info(uint16_t info);
static int send_newstyle_option_reply_meta_context(uint32_t option, uint32_t reply, uint32_t context_id, const char *name);
static int check_string(uint32_t option, const char *data, size_t len, size_t max, const char *what);

#define for_each_backend(b) \
    for ((b) = top; (b) != NULL; (b) = NULL)