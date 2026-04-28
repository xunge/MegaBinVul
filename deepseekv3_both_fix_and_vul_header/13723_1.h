#include <string.h>

#define FALSE 0
#define TRUE 1
#define APR_SUCCESS 0

typedef struct request_rec {
    void *pool;
} request_rec;

typedef struct apr_uri_t {
    char *hostname;
} apr_uri_t;

typedef unsigned char apr_byte_t;

char *apr_pstrdup(void *pool, const char *str);
char *apr_psprintf(void *pool, const char *fmt, ...);
const char *oidc_get_current_url_host(request_rec *r);
void oidc_error(request_rec *r, const char *fmt, ...);
int apr_uri_parse(void *pool, const char *uri, apr_uri_t *result);
char *apr_uri_unparse(void *pool, apr_uri_t *uri, int flags);