#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct request_rec {
    void *per_dir_config;
    char *protocol;
    char *handler;
    char *path_info;
    int used_path_info;
    struct {
        int filetype;
        int protection;
        time_t mtime;
        char *filename;
    } finfo;
    struct request_rec *main;
    void *subprocess_env;
    void *pool;
    struct {
        void *bucket_alloc;
        int aborted;
    } *connection;
    void *output_filters;
    void *notes;
    int status;
    char *filename;
} request_rec;

typedef struct apr_bucket_brigade apr_bucket_brigade;
typedef struct apr_bucket apr_bucket;
typedef struct apr_table_t apr_table_t;
typedef struct apr_pool_t apr_pool_t;
typedef int apr_status_t;
typedef unsigned int apr_size_t;

typedef struct php_struct {
    request_rec *r;
    apr_bucket_brigade *brigade;
    int request_processed;
} php_struct;

typedef struct {
    void *server_context;
} sapi_globals_struct;
extern sapi_globals_struct sapi_globals;

typedef struct zend_syntax_highlighter_ini {
    /* highlight syntax structure fields */
} zend_syntax_highlighter_ini;

typedef struct zend_file_handle {
    int type;
    char *filename;
    int free_filename;
    char *opened_path;
} zend_file_handle;

#define PHP_MAGIC_TYPE "application/x-httpd-php"
#define PHP_SOURCE_MAGIC_TYPE "application/x-httpd-php-source"
#define PHP_SCRIPT "application/x-httpd-php-script"
#define AP_REQ_REJECT_PATH_INFO 1
#define APR_UEXECUTE 0
#define APR_DIR 1
#define HTTP_NOT_FOUND 404
#define HTTP_FORBIDDEN 403
#define HTTP_OK 200
#define DECLINED -1
#define OK 0
#define SUCCESS 0
#define ZEND_INCLUDE 0
#define ZEND_HANDLE_FILENAME 0
#define APR_SUCCESS 0

#define TSRMLS_FETCH()
#define TSRMLS_CC
#define SG(v) (sapi_globals.v)
#define AP2(name) (*(int *)ap_get_module_config(r->per_dir_config, &php5_module))
#define APR_BRIGADE_INSERT_TAIL(b, e)
#define APR_SIZE_T_FMT "zu"

struct module;
extern struct module php5_module;

void *ap_get_module_config(void *per_dir_config, struct module *mod);
void *apr_pcalloc(void *pool, size_t size);
void apr_pool_cleanup_register(void *pool, void *data, void (*cleanup)(void *), void (*null)());
#define apr_pool_cleanup_null NULL
void ap_add_common_vars(request_rec *r);
void ap_add_cgi_vars(request_rec *r);
void *apr_brigade_create(void *pool, void *alloc);
void zend_bailout(void);
void ap_update_mtime(request_rec *r, time_t mtime);
void ap_set_last_modified(request_rec *r);
void php_get_highlight_struct(zend_syntax_highlighter_ini *syntax_highlighter_ini);
void highlight_file(char *filename, zend_syntax_highlighter_ini *syntax_highlighter_ini);
void php_execute_script(zend_file_handle *zfd);
void zend_execute_scripts(int type, void *dummy, int num, zend_file_handle *zfd);
char *apr_psprintf(void *pool, const char *fmt, ...);
apr_size_t zend_memory_peak_usage(int real_usage);
void php_apache_request_dtor(request_rec *r);
void *apr_bucket_eos_create(void *alloc);
apr_status_t ap_pass_brigade(void *filters, apr_bucket_brigade *brigade);
void apr_brigade_cleanup(apr_bucket_brigade *brigade);
void php_handle_aborted_connection(void);
void php_apache_ini_dtor(request_rec *r, request_rec *parent_req);
void php_server_context_cleanup(void *data);
void apply_config(void *conf);
void php_apache_sapi_log_message_ex(const char *format, request_rec *r);
int php_apache_request_ctor(request_rec *r, php_struct *ctx);
int apr_table_set(void *notes, const char *key, const char *val);

#define zend_first_try if (1)
#define zend_end_try()