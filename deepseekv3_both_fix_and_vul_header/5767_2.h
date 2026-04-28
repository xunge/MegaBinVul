#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define DEFAULT_LIMIT_REQUEST_FIELDS 100

typedef struct request_rec {
    struct {
        int limit_req_fields;
        int limit_req_line;
        void *module_config;
    } *server;
    char *the_request;
    time_t request_time;
    int status;
    int proto_num;
    char *protocol;
    void *pool;
    char *method;
    int method_number;
    int header_only;
    struct {
        char *fragment;
        char *user;
        char *password;
    } parsed_uri;
    int assbackwards;
    struct {
        int keepalive;
    } *connection;
} request_rec;

typedef struct apr_bucket_brigade {
    // Minimal definition
} apr_bucket_brigade;

typedef struct core_server_config {
    int http_conformance;
    int http09_enable;
} core_server_config;

#define AP_HTTP_CONFORMANCE_STRICT 0x1
#define AP_HTTP_CONFORMANCE_LOGONLY 0x2
#define AP_HTTP09_DISABLE 0

#define HTTP_VERSION(major, minor) ((major) * 1000 + (minor))
#define HTTP_REQUEST_URI_TOO_LARGE 414
#define HTTP_REQUEST_TIME_OUT 408
#define HTTP_BAD_REQUEST 400
#define HTTP_VERSION_NOT_SUPPORTED 505
#define HTTP_NOT_IMPLEMENTED 501
#define M_GET 0
#define M_INVALID -1

#define APR_SUCCESS 0
#define APR_ENOSPC 1
#define APR_TIMEUP 2
#define APR_EINVAL 3

#define APR_STATUS_IS_ENOSPC(x) ((x) == APR_ENOSPC)
#define APR_STATUS_IS_TIMEUP(x) ((x) == APR_TIMEUP)
#define APR_STATUS_IS_EINVAL(x) ((x) == APR_EINVAL)

#define APLOGrtrace5(r) 0
#define APLOG_MARK __FILE__, __LINE__
#define APLOG_TRACE5 0
#define APLOG_DEBUG 0
#define APLOGNO(x) ""

#define AP_CONN_CLOSE 0

typedef int apr_status_t;
typedef size_t apr_size_t;
typedef time_t apr_time_t;

static void *ap_get_core_module_config(void *config) { return NULL; }
static int ap_rgetline(char **str, apr_size_t len, apr_size_t *read_len, request_rec *r, int flags, apr_bucket_brigade *bb) { return 0; }
static time_t apr_time_now(void) { return time(NULL); }
static char *apr_pstrdup(void *pool, const char *str) { return strdup(str); }
static char *apr_pstrmemdup(void *pool, const char *str, size_t len) { char *copy = malloc(len+1); memcpy(copy, str, len); copy[len] = '\0'; return copy; }
static void ap_log_rerror(const char *file, int line, int level, int module, request_rec *r, const char *fmt, ...) {}
static char *ap_escape_logitem(void *pool, const char *str) { return strdup(str); }
static char *ap_getword_white(void *pool, const char **str) { return strdup(*str); }
static int ap_method_number_of(const char *method) { return 0; }
static void ap_parse_uri(request_rec *r, const char *uri) {}
static int ap_has_cntrl(const char *str) { return 0; }
static int apr_isdigit(int c) { return isdigit(c); }