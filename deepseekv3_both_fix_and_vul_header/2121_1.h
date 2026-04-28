#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <strings.h>

typedef enum {
    SAPI_HEADER_SET_STATUS,
    SAPI_HEADER_ADD,
    SAPI_HEADER_REPLACE,
    SAPI_HEADER_DELETE,
    SAPI_HEADER_DELETE_ALL
} sapi_header_op_enum;

typedef struct {
    char *line;
    size_t line_len;
    int response_code;
} sapi_header_line;

typedef struct {
    char *header;
    size_t header_len;
} sapi_header_struct;

typedef struct {
    int headers_sent;
    struct {
        int no_headers;
        char *request_method;
        int proto_num;
    } request_info;
    struct {
        char *http_status_line;
        char *mimetype;
        int send_default_content_type;
        int http_response_code;
        void *headers;
    } sapi_headers;
} sapi_globals_struct;

typedef struct {
    void (*sapi_error)(int, const char *, ...);
    int (*header_handler)(sapi_header_struct *, sapi_header_op_enum, void *);
} sapi_module_struct;

#define SAPI_API
#define TSRMLS_DC
#define TSRMLS_C
#define TSRMLS_CC
#define E_WARNING 0
#define FAILURE 0
#define SUCCESS 1
#define STRCASECMP strcasecmp
#define SG(x) sapi_globals.x
#define php_output_get_start_filename(x) NULL
#define php_output_get_start_lineno(x) 0
#define estrndup(s, l) strndup(s, l)
#define estrdup(s) strdup(s)
#define efree free
#define emalloc malloc
#define zend_llist_clean(x)
#define zend_llist_del_element(x, y, z)
#define sapi_find_matching_header NULL
#define sapi_update_response_code(x)
#define sapi_extract_response_code(x) 0
#define sapi_header_add_op(x, y)
#define sapi_apply_default_charset(x, y) 0
#define zend_alter_ini_entry(a, b, c, d, e, f)
#define PHP_STRLCPY(dst, src, dst_size, src_size) strlcpy(dst, src, dst_size)

static sapi_module_struct sapi_module;
static sapi_globals_struct sapi_globals;