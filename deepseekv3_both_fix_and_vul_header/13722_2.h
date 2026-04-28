#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OIDC_REDIRECT_URI_REQUEST_LOGOUT "logout_uri"
#define OIDC_CHAR_QUERY '?'
#define OIDC_STR_AMP "&"
#define OIDC_STR_QUERY "?"
#define FALSE 0
#define TRUE 1
#define HTTP_BAD_REQUEST 400
#define HTTP_INTERNAL_SERVER_ERROR 500
#define APR_SUCCESS 0

typedef struct oidc_cfg {
    char *default_slo_url;
    char *error_template;
} oidc_cfg;

typedef struct oidc_session_t oidc_session_t;

typedef struct oidc_provider_t {
    char *end_session_endpoint;
} oidc_provider_t;

typedef struct request_rec {
    void *pool;
} request_rec;

typedef struct apr_uri_t {
    char *hostname;
} apr_uri_t;

extern int apr_strnatcmp(const char *a, const char *b);
extern char *apr_pstrdup(void *p, const char *s);
extern char *apr_psprintf(void *p, const char *fmt, ...);
extern int oidc_is_front_channel_logout(char *url);
extern int oidc_is_back_channel_logout(char *url);
extern int oidc_handle_logout_request(request_rec *r, oidc_cfg *c, oidc_session_t *session, char *url);
extern int oidc_handle_logout_backchannel(request_rec *r, oidc_cfg *c);
extern int oidc_validate_post_logout_url(request_rec *r, char *url, char **error_str, char **error_description);
extern void oidc_debug(request_rec *r, const char *fmt, ...);
extern void oidc_error(request_rec *r, const char *fmt, ...);
extern int oidc_util_html_send_error(request_rec *r, const char *template, const char *error_str, const char *error_description, int status);
extern void oidc_util_get_request_parameter(request_rec *r, const char *name, char **value);
extern const char *oidc_session_get_idtoken(request_rec *r, oidc_session_t *session);
extern void oidc_get_provider_from_session(request_rec *r, oidc_cfg *c, oidc_session_t *session, oidc_provider_t **provider);
extern char *oidc_util_escape_string(request_rec *r, const char *str);
extern const char *oidc_get_current_url_host(request_rec *r);
extern int apr_uri_parse(void *p, const char *uri, apr_uri_t *uptr);
extern char *apr_uri_unparse(void *p, const apr_uri_t *uptr, unsigned flags);