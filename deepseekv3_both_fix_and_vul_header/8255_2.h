#include <stddef.h>

typedef struct _zend_object_iterator zend_object_iterator;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;
typedef struct _spl_filesystem_iterator spl_filesystem_iterator;
typedef struct _spl_filesystem_object spl_filesystem_object;

struct _zend_object_iterator {
    void *data;
    const struct _zend_object_iterator_funcs *funcs;
};

struct _zend_object_iterator_funcs {
    /* iterator methods would be defined here */
};

struct _spl_filesystem_iterator {
    zend_object_iterator intern;
    zval *current;
};

struct _spl_filesystem_object {
    void *std;
};

extern void *zend_object_store_get_object(zval *object);
extern spl_filesystem_iterator *spl_filesystem_object_to_iterator(spl_filesystem_object *dir_object);
extern void zval_add_ref(zval **object);
extern void zend_error(int type, const char *format);

#define TSRMLS_DC
#define TSRMLS_CC
#define E_ERROR 0

struct _zend_object_iterator_funcs spl_filesystem_dir_it_funcs;