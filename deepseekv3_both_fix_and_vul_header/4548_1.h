#include <stddef.h>
#include <stdint.h>

typedef unsigned char zend_bool;

typedef struct _zend_execute_data zend_execute_data;
typedef struct _zval_struct zval;
typedef struct _zend_function_entry {
    const char *fname;
    void (*handler)(INTERNAL_FUNCTION_PARAMETERS);
    const struct _zend_arg_info *arg_info;
    uint32_t num_args;
    uint32_t flags;
} zend_function_entry;

typedef struct _INTERNAL_FUNCTION_PARAMETERS {
    zend_execute_data *execute_data;
    zval *return_value;
    zval **return_value_ptr;
    zval *this_ptr;
    int return_value_used;
} INTERNAL_FUNCTION_PARAMETERS;

typedef struct _php_stream php_stream;
typedef struct _php_hash_ops {
    size_t context_size;
    size_t digest_size;
    void (*hash_init)(void *context);
    void (*hash_update)(void *context, const unsigned char *data, size_t len);
    void (*hash_final)(unsigned char *digest, void *context);
} php_hash_ops;

#define TSRMLS_CC
#define FAILURE (-1)
#define E_WARNING 2
#define ZEND_NUM_ARGS() 0
#define RETURN_FALSE do { return; } while (0)
#define RETURN_STRINGL(str, len, dup) do { return; } while (0)
#define php_error_docref(a, b, c, ...) do {} while (0)
#define CHECK_NULL_PATH(a, b) 0
#define REPORT_ERRORS 0
#define DEFAULT_CONTEXT NULL

void *emalloc(size_t size);
void efree(void *ptr);
void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
const php_hash_ops *php_hash_fetch_ops(const char *algo, int algo_len);
void php_hash_bin2hex(char *out, const unsigned char *in, size_t len);
php_stream *php_stream_open_wrapper_ex(const char *path, const char *mode, int options, char **opened_path, void *context);
int php_stream_read(php_stream *stream, char *buf, size_t count);
void php_stream_close(php_stream *stream);
int zend_parse_parameters(int num_args, const char *type_spec, ...);