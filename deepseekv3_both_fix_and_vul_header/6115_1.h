#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct oidc_cfg oidc_cfg;
typedef struct request_rec request_rec;
typedef struct apr_pool_t apr_pool_t;

struct request_rec {
    apr_pool_t *pool;
};

void oidc_debug(request_rec *r, const char *msg);
char* oidc_get_redirect_uri(request_rec *r, oidc_cfg *c);
int oidc_util_html_send(request_rec *r, const char *title, const char *html_head, const char *html_body, const char *on_load, int status);
char* apr_psprintf(apr_pool_t *pool, const char *fmt, ...);

#define OK 0