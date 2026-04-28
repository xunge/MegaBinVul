#include <string.h>
#include <stdint.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define OK 0
#define HTTP_UNAUTHORIZED 401
#define HTTP_INTERNAL_SERVER_ERROR 500

#define OIDC_DEFAULT_HEADER_PREFIX "OIDC_"
#define OIDC_PASS_IDTOKEN_AS_CLAIMS 1
#define OIDC_PASS_IDTOKEN_AS_PAYLOAD 2
#define OIDC_PASS_IDTOKEN_AS_SERIALIZED 4
#define OIDC_SESSION_TYPE_CLIENT_COOKIE 1
#define OIDC_SESSION_TYPE_SERVER_CACHE 2
#define OIDC_IDTOKEN_SESSION_KEY "id_token"
#define OIDC_REFRESHTOKEN_SESSION_KEY "refresh_token"
#define OIDC_ACCESSTOKEN_SESSION_KEY "access_token"
#define OIDC_ACCESSTOKEN_EXPIRES_SESSION_KEY "access_token_expires"

typedef struct request_rec {
    char* user;
} request_rec;

typedef struct oidc_cfg {
    int scrub_request_headers;
    char* claim_prefix;
    int pass_idtoken_as;
    int session_type;
    int session_inactivity_timeout;
} oidc_cfg;

typedef struct oidc_session_t {
    int64_t expiry;
} oidc_session_t;

typedef uint8_t apr_byte_t;
typedef int64_t apr_time_t;

static apr_time_t apr_time_now(void) { return time(NULL) * 1000000; }
static apr_time_t apr_time_from_sec(int sec) { return sec * 1000000; }