#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int apr_status_t;
typedef size_t apr_size_t;
typedef uint8_t apr_byte_t;
typedef enum { APR_BLOCK_READ } apr_read_type_e;

typedef struct apr_bucket {
    void *data;
    void *list;
    struct apr_bucket *next;
} apr_bucket;

typedef struct request_rec {
    void *pool;
} request_rec;

typedef struct ipc_ctx {
    request_rec *request;
} ipc_ctx;

typedef struct fcgid_bucket_ctx {
    apr_bucket *buffer;
    ipc_ctx ipc;
} fcgid_bucket_ctx;

typedef struct FCGI_Header {
    uint8_t version;
    uint8_t type;
    uint8_t requestIdB1;
    uint8_t requestIdB0;
    uint8_t contentLengthB1;
    uint8_t contentLengthB0;
    uint8_t paddingLength;
    uint8_t reserved;
} FCGI_Header;

#define APR_BUCKET_BUFF_SIZE 8192
#define FCGI_STDERR 7
#define FCGI_STDOUT 6
#define FCGI_END_REQUEST 3
#define APR_SUCCESS 0
#define APLOG_MARK __FILE__,__LINE__
#define APLOG_WARNING 4

static apr_size_t fcgid_min(apr_size_t a, apr_size_t b) { return a < b ? a : b; }
static apr_status_t fcgid_feed_data(fcgid_bucket_ctx *ctx, void *list, char **buffer, apr_size_t *len) { return APR_SUCCESS; }
static void fcgid_ignore_bytes(fcgid_bucket_ctx *ctx, apr_size_t len) {}
static void *apr_bucket_alloc(apr_size_t size, void *list) { return malloc(size); }
static void apr_bucket_free(void *buf) { free(buf); }
static void ap_log_rerror(const char *file, int line, int level, request_rec *request, const char *fmt, ...) {}
static void apr_bucket_split(apr_bucket *b, apr_size_t len) {}
#define APR_BUCKET_NEXT(b) ((b)->next)
#define APR_BUCKET_REMOVE(b) do { } while(0)
#define APR_BUCKET_INSERT_AFTER(a,b) do { } while(0)
static apr_bucket *ap_bucket_fcgid_header_create(void *list, fcgid_bucket_ctx *ctx) { return NULL; }
static apr_status_t apr_pool_cleanup_run(void *pool, void *data, void (*cleanup)(void *)) { return APR_SUCCESS; }
static void bucket_ctx_cleanup(void *data) {}
static apr_bucket *apr_bucket_immortal_make(apr_bucket *b, const char *str, apr_size_t len) { return b; }
static apr_status_t apr_bucket_read(apr_bucket *b, const char **str, apr_size_t *len, apr_read_type_e block) { return APR_SUCCESS; }