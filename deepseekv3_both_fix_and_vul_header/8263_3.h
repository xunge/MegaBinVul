#include <stddef.h>

typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;
typedef struct _zend_object {
    // 最小化的zend_object定义
    void *properties;
    void *handlers;
} zend_object;
typedef struct _zend_object_iterator zend_object_iterator;
typedef struct _spl_filesystem_iterator spl_filesystem_iterator;
typedef struct _spl_filesystem_object spl_filesystem_object;

struct _zend_object_iterator {
    void *data;
    const struct _zend_object_iterator_funcs *funcs;
};

struct _spl_filesystem_iterator {
    zend_object_iterator intern;
};

struct _spl_filesystem_object {
    zend_object std;
};

#define E_ERROR 1

extern void zend_error(int type, const char *format, ...);
extern spl_filesystem_object* zend_object_store_get_object(zval *object);
extern spl_filesystem_iterator* spl_filesystem_object_to_iterator(spl_filesystem_object *dir_object);
extern void zval_add_ref(zval **object);
extern const struct _zend_object_iterator_funcs spl_filesystem_tree_it_funcs;

#define TSRMLS_DC
#define TSRMLS_CC