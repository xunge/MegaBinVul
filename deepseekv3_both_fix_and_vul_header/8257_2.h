#include <dirent.h>
#include <stdlib.h>
#include <string.h>

typedef void zval;
typedef struct _zend_object_iterator zend_object_iterator;
typedef struct _spl_filesystem_iterator spl_filesystem_iterator;
typedef struct _spl_filesystem_object spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC 
#define zval_ptr_dtor(ptr) free(*(ptr))
#define php_stream_rewinddir(dirp) rewinddir(dirp)

struct _spl_filesystem_object {
    union {
        struct {
            int index;
            DIR *dirp;
            struct dirent entry;
        } dir;
    } u;
};

struct _spl_filesystem_iterator {
    zval *current;
};

spl_filesystem_object *spl_filesystem_iterator_to_object(spl_filesystem_iterator *iterator);
void spl_filesystem_dir_read(spl_filesystem_object *object TSRMLS_DC);
int spl_filesystem_is_dot(const char *d_name);