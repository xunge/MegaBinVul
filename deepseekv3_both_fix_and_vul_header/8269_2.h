#include <stdlib.h>

typedef struct _zend_object_iterator {
    // 基础迭代器结构
} zend_object_iterator;

typedef struct _spl_filesystem_iterator {
    // 基础迭代器结构
} spl_filesystem_iterator;

typedef struct _spl_filesystem_object {
    union {
        struct {
            int index;
        } dir;
    } u;
    char *file_name;
} spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC

static spl_filesystem_object *spl_filesystem_iterator_to_object(spl_filesystem_iterator *iterator) {
    return (spl_filesystem_object *)iterator;
}

static void spl_filesystem_dir_read(spl_filesystem_object *object TSRMLS_DC) {
    // 空实现
}

static void efree(void *ptr) {
    free(ptr);
}