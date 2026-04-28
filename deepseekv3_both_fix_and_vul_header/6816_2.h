#include <stddef.h>

typedef unsigned char zend_uchar;

typedef struct _php_stream {
    void *abstract;
} php_stream;

typedef struct _zend_hash_table {
    /* 简化哈希表结构 */
    void *arData;
} zend_hash_table;

typedef struct _zval_struct {
    zend_hash_table *ht;
    zend_uchar type;
    zend_uchar is_ref__gc;
    zend_uchar refcount__gc;
} zval;

typedef struct _php_stream_temp_data {
    zval *meta;
    struct _php_stream *innerstream;
} php_stream_temp_data;

typedef void (*copy_ctor_func_t)(void *pElement);

#define Z_ARRVAL_P(zval_p) ((zval_p)->ht)
#define TSRMLS_DC
#define PHP_STREAM_OPTION_META_DATA_API 0
#define PHP_STREAM_OPTION_RETURN_OK 0
#define PHP_STREAM_OPTION_RETURN_NOTIMPL 0

int php_stream_set_option(php_stream *stream, int option, int value, void *ptrparam);
void zend_hash_copy(zend_hash_table *target, zend_hash_table *source, copy_ctor_func_t copy_ctor, void *tmp, size_t size);
void zval_add_ref(void *pElement);