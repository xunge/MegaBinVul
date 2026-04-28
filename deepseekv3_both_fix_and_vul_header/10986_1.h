#include <stddef.h>
#include <string.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define FAILURE (-1)
#define SUCCESS 0
#define EH_THROW 0
#define E_WARNING 2

typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;
typedef struct _zend_error_handling {
    int type;
    zend_class_entry *exception_class;
} zend_error_handling;

typedef long zend_long;

#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))
#define DIT_CTOR_FLAGS (1<<0)
#define DIT_CTOR_GLOB (1<<1)
#define SPL_FILE_DIR_SKIPDOTS (1<<2)
#define SPL_FILE_DIR_UNIXPATHS (1<<3)
#define SPL_FILE_DIR_KEY_AS_PATHNAME (1<<4)
#define SPL_FILE_DIR_CURRENT_AS_FILEINFO (1<<5)
#define SPL_FILE_DIR_CURRENT_AS_SELF (1<<6)

extern zend_class_entry *spl_ce_UnexpectedValueException;
extern zend_class_entry *spl_ce_RuntimeException;
extern zend_class_entry *spl_ce_RecursiveDirectoryIterator;

typedef struct _spl_filesystem_object {
    char *_path;
    zend_long flags;
    union {
        struct {
            int is_recursive;
        } dir;
    } u;
    struct {
        zend_class_entry *ce;
    } std;
} spl_filesystem_object;

#define Z_SPLFILESYSTEM_P(zv) ((spl_filesystem_object*)zend_object_store_get_object(zv))
#define getThis() this_ptr

void zend_replace_error_handling(int type, zend_class_entry *exception_class, zend_error_handling *error_handling);
void zend_restore_error_handling(zend_error_handling *error_handling);
int zend_parse_parameters(int num_args, const char *type_spec, ...);
void zend_throw_exception_ex(zend_class_entry *exception_ce, long code, const char *format, ...);
void php_error_docref(const char *docref, int type, const char *format, ...);
char *spprintf(char **message, size_t max_len, const char *format, ...);
void efree(void *ptr);
int instanceof_function(zend_class_entry *instance_ce, zend_class_entry *ce);
void spl_filesystem_dir_open(spl_filesystem_object *intern, const char *path);
void *zend_object_store_get_object(zval *zv);