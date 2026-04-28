#include <stddef.h>

typedef struct request_rec request_rec;
typedef struct apr_pool_t apr_pool_t;

#define OK 0
#define HTTP_INTERNAL_SERVER_ERROR 500
#define REQUEST_CHUNKED_DECHUNK 1
#define APLOG_MARK __FILE__,__LINE__,__func__
#define APLOG_ERR 1

typedef size_t apr_size_t;

struct request_rec {
    apr_pool_t *pool;
    apr_size_t remaining;
};

int ap_setup_client_block(request_rec *r, int flags);
int ap_should_client_block(request_rec *r);
long ap_get_client_block(request_rec *r, char *buffer, apr_size_t bufsiz);
void ap_log_rerror(const char *file, int line, const char *func, int level, int status, request_rec *r, const char *fmt, ...);
void *apr_palloc(apr_pool_t *p, apr_size_t size);