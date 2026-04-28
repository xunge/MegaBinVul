#include <stdlib.h>
#include <string.h>

typedef struct _zend_error_handling {
    int type;
    void *error_reporting;
    void *exception_class;
} zend_error_handling;

typedef struct _zend_class_entry {
    struct _zend_function *constructor;
    void *info_class;
    struct {
        void *scope;
    } common;
} zend_class_entry;

typedef struct _zend_function {
    struct {
        void *scope;
    } common;
} zend_function;

typedef struct _spl_filesystem_object {
    zend_class_entry *info_class;
} spl_filesystem_object;

typedef struct _zval_struct {
    int type;
    union {
        void *obj;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

#define TSRMLS_DC
#define TSRMLS_CC 
#define PHP_WIN32
#define EH_THROW 0
#define IS_OBJECT 7
#define IS_STRING 6

extern zend_class_entry *spl_ce_RuntimeException;
extern zend_class_entry *spl_ce_SplFileInfo;

void efree(void *ptr);
void zend_throw_exception_ex(zend_class_entry *exception_ce, long code TSRMLS_DC, const char *format, ...);
void zend_replace_error_handling(int type, zend_class_entry *exception_class, zend_error_handling *error_handling TSRMLS_CC);
void zend_restore_error_handling(zend_error_handling *error_handling TSRMLS_CC);
void zend_update_class_constants(zend_class_entry *ce TSRMLS_CC);
void zend_call_method_with_1_params(zval **object_pp, zend_class_entry *obj_ce, zend_function **fn_proxy, const char *function_name, zval **retval_ptr, zval *param1);
void zval_ptr_dtor(zval **zval_ptr);
spl_filesystem_object *spl_filesystem_object_new_ex(zend_class_entry *class_type, spl_filesystem_object **obj TSRMLS_CC);
void spl_filesystem_info_set_filename(spl_filesystem_object *intern, char *path, int len, int use_copy TSRMLS_CC);

#define MAKE_STD_ZVAL(z) do { (z) = malloc(sizeof(zval)); } while (0)
#define Z_TYPE_P(z) ((z)->type)
#define ZVAL_STRINGL(z, s, l, dup) do { \
    (z)->type = IS_STRING; \
    if (dup) { \
        (z)->value.str.val = strndup((s), (l)); \
    } else { \
        (z)->value.str.val = (s); \
    } \
    (z)->value.str.len = (l); \
} while (0)