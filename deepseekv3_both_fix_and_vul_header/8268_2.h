typedef struct _zend_object_iterator {
    void *dummy;
} zend_object_iterator;

typedef struct _zval {
    void *dummy;
} zval;

typedef struct _spl_filesystem_iterator {
    zend_object_iterator intern;
    zval *current;
} spl_filesystem_iterator;

#define TSRMLS_DC