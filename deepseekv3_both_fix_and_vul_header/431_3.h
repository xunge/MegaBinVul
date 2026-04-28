#include <string.h>

#define DONE 0

typedef struct oidc_cfg oidc_cfg;
typedef struct oidc_session_t oidc_session_t;
typedef struct apr_uri_t {
    const char *path;
} apr_uri_t;
typedef struct request_rec {
    void *pool;
} request_rec;

extern const char *oidc_session_get_session_state(request_rec *r, oidc_session_t *session);
extern void oidc_debug(request_rec *r, const char *msg);
extern void oidc_warn(request_rec *r, const char *msg);
extern const char *oidc_get_redirect_uri(request_rec *r, oidc_cfg *c);
extern int oidc_util_html_send(request_rec *r, const char *title, const char *html, const char *onload, const char *head_extras, int status);
extern void oidc_util_get_request_parameter(request_rec *r, const char *name, char **value);
extern char *apr_pstrdup(void *pool, const char *str);
extern int apr_uri_parse(void *pool, const char *uri, apr_uri_t *result);
extern char *apr_psprintf(void *pool, const char *fmt, ...);