#include <stddef.h>

typedef struct _zval {
    struct {
        char *val;
        size_t len;
    } str;
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            size_t len;
        } str;
        void *ptr;
    } value;
} zval;

typedef struct _zend_literal {
    unsigned long hash_value;
} zend_literal;

typedef struct _ze_zip_object {
    void *prop_handler;
} ze_zip_object;

typedef struct _zip_prop_handler {
    int dummy;
} zip_prop_handler;

typedef struct _zend_object_handlers {
    zval **(*get_property_ptr_ptr)(zval *object, zval *member, const zend_literal *key);
} zend_object_handlers;

#define TSRMLS_DC
#define TSRMLS_CC
#define IS_STRING 6
#define FAILURE -1
#define SUCCESS 0

void zval_copy_ctor(zval *zvalue);
void convert_to_string(zval *zvalue);
void zval_dtor(zval *zvalue);
void *zend_objects_get_address(zval *object);
zend_object_handlers *zend_get_std_object_handlers();
int zend_hash_quick_find(void *ht, char *arKey, unsigned int nKeyLength, unsigned long hashval, void **pData);
int zend_hash_find(void *ht, char *arKey, unsigned int nKeyLength, void **pData);

#define Z_STRVAL_P(zval_p) ((zval_p)->value.str.val)
#define Z_STRLEN_P(zval_p) ((zval_p)->value.str.len)