#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stddef.h>

#define NBD_FLAG_C_FIXED_NEWSTYLE (1 << 0)
#define NBD_FLAG_C_NO_ZEROES (1 << 1)
#define NBD_OPTS_MAGIC 0x49484156454F5054ULL
#define NBD_OPT_STARTTLS 5
#define NBD_OPT_EXPORT_NAME 6
#define NBD_OPT_LIST 3
#define NBD_OPT_ABORT 2
#define NBD_REP_ACK 1
#define NBD_REP_ERR_INVALID 2
#define NBD_REP_ERR_POLICY 3
#define NBD_REP_ERR_TLS_REQD 4
#define NBD_REP_ERR_UNSUP 5

#define EIO 5
#define EINVAL 22

typedef struct NBDClient {
    void *ioc;
    void *sioc;
    void *tlscreds;
    bool no_zeroes;
} NBDClient;

typedef struct QIOChannel QIOChannel;
typedef struct Object Object;

static inline uint32_t be32_to_cpu(uint32_t val) { return val; }
static inline uint64_t be64_to_cpu(uint64_t val) { return val; }
static inline void be32_to_cpus(uint32_t *val) { *val = be32_to_cpu(*val); }
static inline void object_unref(Object *obj) {}
static inline QIOChannel *QIO_CHANNEL(void *p) { return (QIOChannel *)p; }
static inline Object *OBJECT(void *p) { return (Object *)p; }

static int nbd_negotiate_read(void *ioc, void *buf, size_t len) { return 0; }
static QIOChannel *nbd_negotiate_handle_starttls(NBDClient *client, uint32_t length) { return NULL; }
static int nbd_negotiate_handle_list(NBDClient *client, uint32_t length) { return 0; }
static int nbd_negotiate_handle_export_name(NBDClient *client, uint32_t length) { return 0; }
static int nbd_negotiate_drop_sync(void *ioc, uint32_t length) { return 0; }
static int nbd_negotiate_send_rep(void *ioc, uint32_t type, uint32_t option) { return 0; }
static int nbd_negotiate_send_rep_err(void *ioc, uint32_t type, uint32_t option, const char *fmt, ...) { return 0; }

#define LOG(fmt, ...)
#define TRACE(fmt, ...)