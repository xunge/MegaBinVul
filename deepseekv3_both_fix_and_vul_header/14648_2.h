#include <stdlib.h>
#include <string.h>

typedef struct json_t json_t;

typedef struct request_rec {
    char* user;
    struct request_rec *main;
    struct request_rec *prev;
    void *headers_in;
} request_rec;

typedef struct oidc_cfg {
    const char *redirect_uri;
    struct {
        const char *introspection_endpoint_url;
    } oauth;
    const char *claim_prefix;
    const char *claim_delimiter;
} oidc_cfg;

#define OK 0
#define FALSE 0
#define OIDC_CLAIMS_SESSION_KEY "oidc_claims"
#define OIDC_DEFAULT_HEADER_PREFIX "OIDC_"

int ap_is_initial_req(request_rec *r);
int oidc_debug(request_rec *r, const char *fmt, ...);
int oidc_error(request_rec *r, const char *fmt, ...);
int oidc_util_request_matches_url(request_rec *r, const char *url);
int oidc_util_request_has_parameter(request_rec *r, const char *param);
int oidc_handle_jwks(request_rec *r, oidc_cfg *c);
int oidc_oauth_get_bearer_token(request_rec *r, const char **access_token);
int oidc_oauth_return_www_authenticate(request_rec *r, const char *error, const char *description);
int oidc_oauth_resolve_access_token(request_rec *r, oidc_cfg *c, const char *access_token, json_t **token, char **s_token);
int oidc_oauth_validate_jwt_access_token(request_rec *r, oidc_cfg *c, const char *access_token, json_t **token, char **s_token);
void oidc_request_state_set(request_rec *r, const char *key, const char *value);
int oidc_oauth_set_remote_user(request_rec *r, oidc_cfg *c, json_t *token);
char *oidc_cfg_dir_authn_header(request_rec *r);
int oidc_cfg_dir_pass_info_in_headers(request_rec *r);
int oidc_cfg_dir_pass_info_in_envvars(request_rec *r);
void oidc_util_set_app_infos(request_rec *r, json_t *token, const char *prefix, const char *delimiter, int pass_headers, int pass_envvars);
void oidc_util_set_app_info(request_rec *r, const char *key, const char *value, const char *prefix, int pass_headers, int pass_envvars);
void json_decref(json_t *json);
void apr_table_set(void *table, const char *key, const char *val);