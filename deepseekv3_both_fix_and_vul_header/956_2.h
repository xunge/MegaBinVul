#include <stdlib.h>
#include <string.h>

typedef struct request_rec {
    struct request_rec *main;
    struct request_rec *prev;
    char *user;
    void *headers_in;
} request_rec;

typedef struct oidc_cfg {
    const char *redirect_uri;
} oidc_cfg;

typedef struct oidc_session_t {
    const char *remote_user;
} oidc_session_t;

#define OK 0
#define HTTP_INTERNAL_SERVER_ERROR 500
#define HTTP_GONE 410
#define HTTP_UNAUTHORIZED 401

#define OIDC_IDTOKEN_CLAIMS_SESSION_KEY "id_token_claims"

typedef enum {
    OIDC_UNAUTH_RETURN410,
    OIDC_UNAUTH_RETURN401,
    OIDC_UNAUTH_PASS,
    OIDC_UNAUTH_AUTHENTICATE
} oidc_unauth_action_t;

void *apr_table_get(void *table, const char *key);