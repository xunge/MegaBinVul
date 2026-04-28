#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define OK 0
#define FALSE 0
#define HTTP_BAD_REQUEST 400
#define HTTP_INTERNAL_SERVER_ERROR 500
#define APLOG_ERR 1

typedef struct apr_pool_t apr_pool_t;

typedef struct request_rec {
    apr_pool_t *pool;
    const char *args;
} request_rec;

typedef struct am_dir_cfg_rec {
    const char *discovery_url;
} am_dir_cfg_rec;

typedef struct {
    const char *file;
    int line;
    const char *func;
} APLOG_MARK;

static APLOG_MARK ap_make_log_mark(const char *file, int line, const char *func);

static am_dir_cfg_rec* am_get_dir_cfg(request_rec *r);
static char* am_extract_query_parameter(apr_pool_t *pool, const char *args, const char *param);
static int am_urldecode(char *str);
static int am_get_boolean_query_parameter(request_rec *r, const char *name, int *value, int default_value);
static const char* am_get_idp(request_rec *r);
static int am_start_disco(request_rec *r, const char *return_to);
static int am_send_login_authn_request(request_rec *r, const char *idp, const char *return_to, int is_passive);
static void ap_log_rerror(APLOG_MARK mark, int level, int status, request_rec *r, const char *fmt, ...);

static APLOG_MARK ap_make_log_mark(const char *file, int line, const char *func) {
    APLOG_MARK mark = {file, line, func};
    return mark;
}

#define APLOG_MARK ap_make_log_mark(__FILE__, __LINE__, __func__)