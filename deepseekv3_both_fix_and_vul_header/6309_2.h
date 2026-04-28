#include <string.h>
#include <stdlib.h>

#define OIDC_DISC_OP_PARAM "op"
#define OIDC_DISC_USER_PARAM "user"
#define OIDC_DISC_RT_PARAM "target_link_uri"
#define OIDC_DISC_LH_PARAM "login_hint"
#define OIDC_DISC_SC_PARAM "scopes"
#define OIDC_DISC_AR_PARAM "auth_request_params"
#define OIDC_CSRF_NAME "csrf"
#define OIDCDefaultURL "default_url"
#define OIDC_STR_AT "@"
#define OIDC_CHAR_FORWARD_SLASH '/'

#define FALSE 0
#define TRUE 1
#define HTTP_INTERNAL_SERVER_ERROR 500
#define HTTP_UNAUTHORIZED 401
#define HTTP_NOT_FOUND 404

typedef struct request_rec {
    void *pool;
} request_rec;

typedef struct oidc_cfg {
    char *default_sso_url;
    char *error_template;
    char *metadata_dir;
    struct {
        char *issuer;
    } provider;
} oidc_cfg;

typedef struct oidc_provider_t {
    char *issuer;
} oidc_provider_t;

char* oidc_util_get_request_parameter(request_rec *r, const char *param, char **value);
char* oidc_util_get_cookie(request_rec *r, const char *name);
void oidc_util_set_cookie(request_rec *r, const char *name, const char *value, int expires, int flags);
int apr_strnatcmp(const char *a, const char *b);
void oidc_warn(request_rec *r, const char *msg);
void oidc_debug(request_rec *r, const char *fmt, ...);
int oidc_util_html_send_error(request_rec *r, const char *template, const char *title, const char *msg, int status);
int oidc_target_link_uri_matches_configuration(request_rec *r, oidc_cfg *c, const char *uri);
int oidc_provider_static_config(request_rec *r, oidc_cfg *c, oidc_provider_t **provider);
char* apr_pstrdup(void *pool, const char *s);
char* apr_psprintf(void *pool, const char *fmt, ...);
int oidc_authenticate_user(request_rec *r, oidc_cfg *c, oidc_provider_t *provider, const char *target_link_uri, const char *login_hint, void *session, void *jwks, const char *auth_request_params, const char *path_scopes);
int oidc_proto_url_based_discovery(request_rec *r, oidc_cfg *c, const char *user, char **issuer);
int oidc_proto_account_based_discovery(request_rec *r, oidc_cfg *c, const char *account, char **issuer);
int oidc_metadata_get(request_rec *r, oidc_cfg *c, const char *issuer, oidc_provider_t **provider, int allow_discovery);
int OIDC_COOKIE_EXT_SAME_SITE_NONE(request_rec *r);