#include <stddef.h>

typedef struct _php_stream php_stream;

typedef struct _zend_object_iterator {
    void *dummy;
} zend_object_iterator;

typedef struct _spl_filesystem_object {
    union {
        struct {
            php_stream *dirp;
            size_t index;
        } dir;
    } u;
} spl_filesystem_object;

typedef struct _spl_filesystem_iterator {
    zend_object_iterator intern;
    spl_filesystem_object *object;
} spl_filesystem_iterator;

#define TSRMLS_DC
#define TSRMLS_CC
#define spl_filesystem_iterator_to_object(iter) ((iter)->object)
void php_stream_rewinddir(php_stream *stream);
void spl_filesystem_dir_read(spl_filesystem_object *object, ...);