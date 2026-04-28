#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define OK 0

typedef unsigned char apr_byte_t;

typedef struct oidc_cfg {
    int dummy;
} oidc_cfg;

extern auth_openidc_module;

typedef struct apr_pool_t {
    int dummy;
} apr_pool_t;

typedef struct apr_table_t {
    int dummy;
} apr_table_t;

typedef struct apr_array_header_t {
    void *elts;
    int nelts;
} apr_array_header_t;

typedef struct apr_table_entry_t {
    const char *key;
    const char *val;
} apr_table_entry_t;

typedef struct server_rec {
    void *module_config;
} server_rec;

typedef struct request_rec {
    apr_pool_t *pool;
    server_rec *server;
} request_rec;

#define OIDC_METHOD_FORM_POST "POST"

/* Dummy function declarations */
int oidc_cfg_dir_preserve_post(request_rec *r);
void oidc_debug(request_rec *r, const char *msg);
void *ap_get_module_config(void *conf, void *module);
const char *oidc_original_request_method(request_rec *r, oidc_cfg *cfg, int b);
int apr_strnatcmp(const char *a, const char *b);
apr_table_t *apr_table_make(apr_pool_t *p, int n);
int oidc_util_read_post_params(request_rec *r, apr_table_t *t, int b, void *p);
void oidc_error(request_rec *r, const char *msg);
apr_array_header_t *apr_table_elts(apr_table_t *t);
char *apr_psprintf(apr_pool_t *p, const char *fmt, ...);
char *oidc_util_escape_string(request_rec *r, const char *s);
char *apr_pstrdup(apr_pool_t *p, const char *s);
void oidc_util_html_send(request_rec *r, const char *title, const char *script,
                        const char *onload, const char *body, int status);