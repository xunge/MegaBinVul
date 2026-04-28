#include <stddef.h>

typedef struct _zend_literal zend_literal;
typedef struct _zend_function zend_function;
typedef struct _zval_struct zval;

#define TSRMLS_DC
#define TSRMLS_CC

typedef struct _spl_filesystem_object {
    union {
        struct {
            struct {
                char d_name[1];
            } entry;
        } dir;
    } u;
    char *orig_path;
} spl_filesystem_object;

extern void *zend_object_store_get_object(zval *object TSRMLS_DC);
extern struct _zend_object_handlers {
    zend_function *(*get_method)(zval **object_ptr, char *method, int method_len, const zend_literal *key TSRMLS_DC);
} *zend_get_std_object_handlers(void);