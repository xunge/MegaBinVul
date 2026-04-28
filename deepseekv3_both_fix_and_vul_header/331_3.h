#include <stdlib.h>
#include <string.h>

typedef struct request_rec {
    void *pool;
    const char *args;
    void *headers_out;
} request_rec;

typedef struct am_dir_cfg_rec {
    int probe_discovery_timeout;
    void *probe_discovery_idp;
} am_dir_cfg_rec;

typedef struct LassoServer {
    void *providers;
} LassoServer;

typedef struct apr_pool_t {} apr_pool_t;
typedef struct apr_table_t {} apr_table_t;
typedef struct apr_array_header_t {
    void *elts;
    int nelts;
} apr_array_header_t;

typedef struct apr_table_entry_t {
    const char *key;
    const char *val;
} apr_table_entry_t;

typedef struct GList {
    void *data;
    struct GList *next;
} GList;

#define OK 0
#define HTTP_OK 200
#define HTTP_BAD_REQUEST 400
#define HTTP_SEE_OTHER 303
#define HTTP_INTERNAL_SERVER_ERROR 500
#define APLOG_MARK 0
#define APLOG_ERR 0
#define APLOG_WARNING 0
#define APLOG_INFO 0

static am_dir_cfg_rec *am_get_dir_cfg(request_rec *r);
static LassoServer *am_get_lasso_server(request_rec *r);
static char *am_extract_query_parameter(apr_pool_t *pool, const char *args, const char *param);
static int am_urldecode(char *str);
static int am_probe_url(request_rec *r, const char *url, int timeout);
static const char *am_first_idp(request_rec *r);
static char *am_urlencode(apr_pool_t *pool, const char *str);
static void ap_log_rerror(int mark, int level, int status, request_rec *r, const char *fmt, ...);
static char *apr_psprintf(apr_pool_t *pool, const char *fmt, ...);
static void apr_table_setn(apr_table_t *t, const char *key, const char *val);
static int apr_is_empty_table(apr_table_t *t);
static apr_array_header_t *apr_table_elts(apr_table_t *t);
static GList *g_hash_table_get_keys(void *hash_table);
static void g_list_free(GList *list);