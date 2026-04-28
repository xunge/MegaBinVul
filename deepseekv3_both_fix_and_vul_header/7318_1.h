#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>
#include <endian.h>

#define MAX_NR_OPTIONS 100
#define MAX_REQUEST_SIZE (32 * 1024 * 1024)
#define NBD_NEW_VERSION 0x49484156454F5054ULL
#define NBD_FLAG_FIXED_NEWSTYLE (1 << 0)
#define NBD_FLAG_NO_ZEROES (1 << 1)
#define NBD_OPT_EXPORT_NAME 1
#define NBD_OPT_ABORT 2
#define NBD_OPT_LIST 3
#define NBD_OPT_STARTTLS 5
#define NBD_OPT_INFO 6
#define NBD_OPT_GO 7
#define NBD_OPT_STRUCTURED_REPLY 8
#define NBD_OPT_LIST_META_CONTEXT 9
#define NBD_OPT_SET_META_CONTEXT 10
#define NBD_REP_ACK 1
#define NBD_REP_ERR_INVALID 2
#define NBD_REP_ERR_UNSUP 3
#define NBD_REP_ERR_POLICY 4
#define NBD_REP_ERR_TLS_REQD 5
#define NBD_REP_ERR_UNKNOWN 6
#define NBD_REP_INFO 7
#define NBD_REP_META_CONTEXT 8
#define NBD_INFO_EXPORT 0
#define NBD_INFO_NAME 1
#define NBD_INFO_DESCRIPTION 2

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
    const char *(*default_export)(void *top, bool read_only);
    const char *(*export_description)(void *top_context);
    char **default_exportname;
};

struct connection {
    uint32_t cflags;
    uint16_t eflags;
    bool using_tls;
    bool structured_replies;
    bool meta_context_base_allocation;
    char *exportname_from_set_meta_context;
    void *top_context;
    char **default_exportname;
    int (*send)(const void *buf, size_t len, int flags);
    int sockin;
    int sockout;
};

static struct connection *conn;
static int tls;
static bool no_sr;
static void *top;
static bool read_only;
static unsigned base_allocation_id;

#define GET_CONN
#define CLEANUP_FREE
#define for_each_backend(b) for ((b) = NULL; (b) != NULL; (b) = NULL)

static int conn_recv_full(void *buf, size_t len, const char *fmt, ...);
static int send_newstyle_option_reply(uint32_t option, uint32_t reply);
static int send_newstyle_option_reply_exportnames(uint32_t option, size_t *nr_options);
static int send_newstyle_option_reply_info_export(uint32_t option, uint32_t reply, uint16_t info, uint64_t exportsize);
static int send_newstyle_option_reply_info_str(uint32_t option, uint32_t reply, uint16_t info, const char *str, size_t len);
static int send_newstyle_option_reply_meta_context(uint32_t option, uint32_t reply, unsigned context_id, const char *name);
static int check_export_name(uint32_t option, const char *data, size_t len, size_t maxlen);
static int finish_newstyle_options(uint64_t *exportsize, const char *data, size_t len);
static int crypto_negotiate_tls(int sockin, int sockout);
static int backend_finalize(void *top_context);
static void backend_close(void *top_context);
static const char *name_of_nbd_opt(uint32_t option);
static const char *name_of_nbd_info(uint16_t info);
static int check_string(uint32_t option, const char *data, size_t len, size_t maxlen, const char *what);
static void nbdkit_error(const char *fmt, ...);
static void debug(const char *fmt, ...);