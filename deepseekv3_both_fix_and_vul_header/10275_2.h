#include <stdlib.h>
#include <string.h>

typedef struct request_rec {
    char *args;
    void *pool;
} request_rec;

typedef struct oidc_cfg {
    const char *error_template;
} oidc_cfg;

typedef struct oidc_session_t oidc_session_t;

#define HTTP_INTERNAL_SERVER_ERROR 500

int apr_strnatcmp(const char *a, const char *b);
char *apr_psprintf(void *pool, const char *fmt, ...);

int oidc_proto_is_redirect_authorization_response(request_rec *r, oidc_cfg *c);
int oidc_handle_redirect_authorization_response(request_rec *r, oidc_cfg *c, oidc_session_t *session);
int oidc_proto_is_post_authorization_response(request_rec *r, oidc_cfg *c);
int oidc_handle_post_authorization_response(request_rec *r, oidc_cfg *c, oidc_session_t *session);
int oidc_is_discovery_response(request_rec *r, oidc_cfg *c);
int oidc_handle_discovery_response(request_rec *r, oidc_cfg *c);
int oidc_util_request_has_parameter(request_rec *r, const char *param);
int oidc_handle_logout(request_rec *r, oidc_cfg *c, oidc_session_t *session);
int oidc_handle_jwks(request_rec *r, oidc_cfg *c);
int oidc_handle_session_management(request_rec *r, oidc_cfg *c, oidc_session_t *session);
int oidc_handle_refresh_token_request(request_rec *r, oidc_cfg *c, oidc_session_t *session);
int oidc_handle_request_uri(request_rec *r, oidc_cfg *c);
int oidc_handle_remove_at_cache(request_rec *r, oidc_cfg *c);
int oidc_proto_javascript_implicit(request_rec *r, oidc_cfg *c);
int oidc_util_html_send_error(request_rec *r, const char *error_template, const char *error, const char *description, int status);