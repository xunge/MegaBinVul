#include <dirent.h>
#include <stdlib.h>

typedef struct _zval zval;
typedef struct _zend_object_iterator zend_object_iterator;

struct _zend_object_iterator {
    void *data;
    void *funcs;
};

typedef struct _spl_filesystem_iterator {
    zend_object_iterator intern;
    zval *current;
} spl_filesystem_iterator;

typedef struct _spl_filesystem_object {
    union {
        struct {
            long index;
            struct dirent entry;
        } dir;
    } u;
    char *file_name;
} spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define efree free
#define zval_ptr_dtor(z) free(*(z))

static spl_filesystem_object* spl_filesystem_iterator_to_object(spl_filesystem_iterator *iterator);
static void spl_filesystem_dir_read(spl_filesystem_object *object TSRMLS_DC);
static int spl_filesystem_is_dot(const char *d_name);