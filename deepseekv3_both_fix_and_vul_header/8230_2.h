#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _zval_struct zval;
typedef struct _php_stream php_stream;

#define PHPAPI
#define ZEND_NUM_ARGS() 0
#define TSRMLS_CC
#define FAILURE (-1)
#define RETURN_FALSE return
#define PHP_STREAM_TO_ZVAL(stream, arg) 
#define E_WARNING 0
#define php_error_docref(a, b, c, ...)
#define IS_STRING 0
#define Z_STRVAL_P(z) ((z)->value.str.val)
#define Z_STRLEN_P(z) ((z)->value.str.len)
#define Z_TYPE_P(z) ((z)->type)

struct _zval_struct {
    union {
        struct {
            char *val;
            size_t len;
        } str;
    } value;
    int type;
};

size_t php_stream_read(php_stream *stream, char *buf, size_t len);
zval *return_value;