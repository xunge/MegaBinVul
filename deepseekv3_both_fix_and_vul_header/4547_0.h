#include <string.h>
#include <stdlib.h>

typedef struct _php_hash_ops {
    size_t context_size;
    size_t block_size;
    size_t digest_size;
    void (*hash_init)(void *context);
    void (*hash_update)(void *context, const unsigned char *input, size_t len);
    void (*hash_final)(unsigned char *digest, void *context);
} php_hash_ops;

typedef struct _php_stream php_stream;
typedef int zend_bool;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define FAILURE (-1)
#define RETURN_FALSE do { ZVAL_BOOL(return_value, 0); return; } while (0)
#define RETURN_STRINGL(str, len, dup) do { ZVAL_STRINGL(return_value, str, len, dup); } while (0)
#define E_WARNING 2
#define REPORT_ERRORS 0
#define DEFAULT_CONTEXT NULL

#define php_error_docref(a, b, c, ...)
#define php_hash_fetch_ops(a, b) NULL
#define php_stream_open_wrapper_ex(a, b, c, d, e) NULL
#define php_stream_read(a, b, c) 0
#define php_stream_close(a)
#define php_hash_bin2hex(a, b, c)
#define safe_emalloc(a, b, c) malloc((a)*(b)+(c))
#define emalloc malloc
#define efree free

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

#define ZVAL_BOOL(z, b) do { (z)->type = 1; (z)->value.lval = (b); } while (0)
#define ZVAL_STRINGL(z, s, l, d) do { (z)->type = 2; (z)->value.str.val = (d ? strndup(s, l) : (s)); (z)->value.str.len = (l); } while (0)