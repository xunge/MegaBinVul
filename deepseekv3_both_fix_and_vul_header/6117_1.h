#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct request_rec {
    void *pool;
} request_rec;

static int oidc_debug(request_rec *r, const char *fmt, ...);
static int oidc_util_html_send(request_rec *r, const char *title, const char *script, const char *onload, const char *body, int status);

#define OK 0

char *apr_psprintf(void *pool, const char *fmt, ...);