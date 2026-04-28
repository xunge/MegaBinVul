#include <stdlib.h>

typedef struct _zend_object_iterator zend_object_iterator;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;
typedef struct _spl_array_it spl_array_it;
typedef struct _spl_array_object spl_array_object;

struct _zend_object_iterator {
    void *data;
    struct _zend_object_iterator_funcs *funcs;
};

struct _zend_object_iterator_funcs {
    /* dummy structure to make compiler happy */
    void *dummy;
};

struct _spl_array_it {
    struct {
        zend_object_iterator it;
        zend_class_entry *ce;
        void *value;
    } intern;
    spl_array_object *object;
};

struct _spl_array_object {
    void *std;
    unsigned long ar_flags;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define SPL_ARRAY_OVERLOADED_CURRENT (1<<0)
#define Z_ADDREF_P(zv) 
#define emalloc(size) malloc(size)
#define zend_error(code, message)
#define zend_object_store_get_object(obj) ((spl_array_object*)0)

struct _zend_object_iterator_funcs spl_array_it_funcs;