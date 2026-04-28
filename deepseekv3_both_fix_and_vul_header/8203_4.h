#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <strings.h>

typedef enum {
    SAPI_HEADER_SET_STATUS,
    SAPI_HEADER_ADD,
    SAPI_HEADER_REPLACE,
    SAPI_HEADER_DELETE,
    SAPI_HEADER_DELETE_ALL
} sapi_header_op_enum;

typedef struct _sapi_header_struct {
    char *header;
    unsigned int header_len;
} sapi_header_struct;

typedef struct _sapi_header_line {
    char *line;
    unsigned int line_len;
    int response_code;
} sapi_header_line;

typedef intptr_t zend_intptr_t;
typedef unsigned int uint;

#define SAPI_API
#define TSRMLS_DC
#define TSRMLS_C
#define TSRMLS_CC
#define FAILURE (-1)
#define SUCCESS 0
#define E_WARNING 2

#define STRCASECMP strcasecmp

#define PHP_INI_USER 1
#define PHP_INI_STAGE_RUNTIME 4

struct _sapi_headers_struct {
    char *http_status_line;
    char *mimetype;
    int send_default_content_type;
    int http_response_code;
    struct {
        void *headers;
    } headers;
};

struct _request_info {
    int no_headers;
    int proto_num;
    char *request_method;
};

struct _sapi_globals_struct {
    int headers_sent;
    struct _request_info request_info;
    struct _sapi_headers_struct sapi_headers;
};

extern struct _sapi_globals_struct SG;

struct _sapi_module_struct {
    void (*sapi_error)(int type, const char *format, ...);
    int (*header_handler)(sapi_header_struct *sapi_header, sapi_header_op_enum op, void *arg);
};

extern struct _sapi_module_struct sapi_module;

void sapi_update_response_code(int code);
int sapi_extract_response_code(const char *header_line);
void sapi_remove_header(void *headers, char *header, unsigned int header_len);
void sapi_header_add_op(sapi_header_op_enum op, sapi_header_struct *sapi_header);
char *php_output_get_start_filename(void);
int php_output_get_start_lineno(void);
size_t sapi_apply_default_charset(char **mimetype, size_t len);
void zend_alter_ini_entry(const char *name, unsigned int name_length, const char *new_value, unsigned int new_value_length, int modify_type, int stage);
void zend_llist_clean(void *llist);
char *estrndup(const char *s, size_t length);
void efree(void *ptr);
char *estrdup(const char *s);
void *emalloc(size_t size);

size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);

#define PHP_STRLCPY(dst, src, dst_size, src_size) strlcpy(dst, src, dst_size)

#define SG(v) (SG.v)