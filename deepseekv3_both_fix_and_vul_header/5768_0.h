#include <stddef.h>
#include <string.h>

#define AP_DECLARE(type) type
#define OK 0
#define DECLINED -1
#define HTTP_NOT_FOUND 404
#define HTTP_INTERNAL_SERVER_ERROR 500
#define APLOG_MARK __FILE__, __LINE__
#define APLOG_INFO 0
#define APLOG_ERR 0
#define APLOG_TRACE3 0
#define APLOGNO(num) 

typedef enum {
    SATISFY_ALL,
    SATISFY_ANY,
    SATISFY_NOSPEC
} satisfy_t;

typedef struct request_rec request_rec;
typedef struct core_dir_config core_dir_config;
typedef struct conn_rec conn_rec;
typedef struct server_rec server_rec;

struct request_rec {
    request_rec *main;
    request_rec *prev;
    char *filename;
    char *uri;
    struct {
        char *path;
        char *scheme;
    } parsed_uri;
    int proxyreq;
    void *per_dir_config;
    void *log;
    char *user;
    char *ap_auth_type;
    conn_rec *connection;
    server_rec *server;
};

struct core_dir_config {
    int allow_encoded_slashes;
    int decode_encoded_slashes;
    void *log;
};

struct conn_rec {
    void *log;
};

struct server_rec {
    void *lookup_defaults;
};

static int ap_unescape_url_keep2f(char *path, int decode_encoded_slashes) { return 0; }
static int ap_unescape_url(char *path) { return 0; }
static void ap_log_rerror(const char *file, int line, int level, int num, request_rec *r, const char *fmt, ...) {}
static void ap_getparents(char *uri) {}
static int ap_location_walk(request_rec *r) { return 0; }
static int ap_if_walk(request_rec *r) { return 0; }
static core_dir_config *ap_get_core_module_config(void *per_dir_config) { return NULL; }
static int ap_run_translate_name(request_rec *r) { return 0; }
static int decl_die(int status, const char *msg, request_rec *r) { return status; }
static int ap_run_map_to_storage(request_rec *r) { return 0; }
static int ap_run_post_perdir_config(request_rec *r) { return 0; }
static int ap_run_header_parser(request_rec *r) { return 0; }
static satisfy_t ap_satisfies(request_rec *r) { return SATISFY_ALL; }
static int ap_run_access_checker(request_rec *r) { return 0; }
static int ap_run_access_checker_ex(request_rec *r) { return 0; }
static int ap_run_check_user_id(request_rec *r) { return 0; }
static int ap_run_auth_checker(request_rec *r) { return 0; }
static int ap_run_type_checker(request_rec *r) { return 0; }
static int ap_run_fixups(request_rec *r) { return 0; }