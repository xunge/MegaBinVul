#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define E_ERROR 1

typedef unsigned int zend_object_handle;
typedef struct _zend_object_value {
    int handle;
    const struct _zend_object_handlers *handlers;
} zend_object_value;

typedef struct _zend_class_entry {
    char *name;
} zend_class_entry;

typedef struct _zend_object {
    zend_class_entry *ce;
} zend_object;

typedef struct _zval {
    zend_object *obj;
} zval;

typedef struct _zend_object_handlers {
    void (*clone)(void *, void *);
} zend_object_handlers;

typedef struct _oth_handler {
    void (*clone)(void *, void *);
} oth_handler;

#define TSRMLS_DC
#define TSRMLS_CC
#define Z_OBJ_HANDLE_P(zobj) (0)

typedef struct _spl_filesystem_object {
    zend_object std;
    int type;
    int flags;
    size_t _path_len;
    char *_path;
    size_t file_name_len;
    char *file_name;
    zend_class_entry *file_class;
    zend_class_entry *info_class;
    void *oth;
    oth_handler *oth_handler;
    union {
        struct {
            int index;
            struct dirent entry;
        } dir;
    } u;
} spl_filesystem_object;

#define SPL_FS_INFO 0
#define SPL_FS_DIR 1
#define SPL_FS_FILE 2
#define SPL_FILE_DIR_SKIPDOTS (1<<0)
#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))

static zend_object *zend_objects_get_address(zval *obj TSRMLS_DC) { return NULL; }
static zend_object_value spl_filesystem_object_new_ex(zend_class_entry *ce, spl_filesystem_object **obj TSRMLS_DC) { return (zend_object_value){0}; }
static void spl_filesystem_dir_open(spl_filesystem_object *intern, const char *path TSRMLS_DC) {}
static void spl_filesystem_dir_read(spl_filesystem_object *intern TSRMLS_DC) {}
static int spl_filesystem_is_dot(const char *d_name) { return 0; }
static void zend_objects_clone_members(zend_object *new_obj, zend_object_value new_obj_val, zend_object *old_obj, zend_object_handle handle TSRMLS_DC) {}
static void php_error_docref(const char *ref TSRMLS_DC, int type, const char *format, ...) {}

char *estrndup(const char *s, size_t length) {
    char *p = malloc(length + 1);
    if (p) {
        memcpy(p, s, length);
        p[length] = '\0';
    }
    return p;
}