#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int zend_bool;
typedef struct _zval zval;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _zend_function zend_function;
typedef struct _zend_error_handling zend_error_handling;

struct _zval {
    union {
        struct {
            char *val;
            size_t len;
        } str;
        void *obj;
        long lval;
        double dval;
    } value;
    uint8_t type;
};

struct _zend_class_entry {
    struct {
        zend_class_entry *scope;
    } common;
    zend_function *constructor;
    zend_class_entry *info_class;
    zend_class_entry *file_class;
};

struct _zend_function {
    struct {
        zend_class_entry *scope;
    } common;
};

struct _zend_error_handling {
    int dummy;
};

typedef struct _spl_filesystem_object {
    int type;
    union {
        struct {
            char *open_mode;
            size_t open_mode_len;
            void *zcontext;
        } file;
        struct {
            struct {
                char d_name[256];
            } entry;
        } dir;
    } u;
    char *file_name;
    size_t file_name_len;
    char *_path;
    size_t _path_len;
    zend_class_entry *info_class;
    zend_class_entry *file_class;
} spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define EH_THROW 0
#define FAILURE -1
#define SUCCESS 0
#define IS_OBJECT 8
#define IS_NULL 0
#define IS_STRING 6

#define ZEND_NUM_ARGS() 0
#define Z_TYPE_P(zval_p) ((zval_p)->type)
#define ZVAL_STRINGL(z, s, l, dup) do { \
    (z)->value.str.val = (dup ? estrndup((s), (l)) : (s)); \
    (z)->value.str.len = (l); \
    (z)->type = IS_STRING; \
} while (0)
#define MAKE_STD_ZVAL(zv) do { \
    zv = (zval *)malloc(sizeof(zval)); \
} while (0)

enum {
    SPL_FS_INFO,
    SPL_FS_FILE,
    SPL_FS_DIR
};

extern zend_class_entry *spl_ce_RuntimeException;
extern zend_class_entry *spl_ce_SplFileInfo;
extern zend_class_entry *spl_ce_SplFileObject;

char *estrndup(const char *s, size_t length);
void zend_throw_exception_ex(zend_class_entry *exception_ce, int code, const char *format, ...);
void zend_replace_error_handling(int type, zend_class_entry *exception_ce, zend_error_handling *error_handling);
void zend_restore_error_handling(zend_error_handling *error_handling);
void zend_update_class_constants(zend_class_entry *ce);
spl_filesystem_object *spl_filesystem_object_new_ex(zend_class_entry *ce, spl_filesystem_object **intern);
void spl_filesystem_object_get_file_name(spl_filesystem_object *source);
char *spl_filesystem_object_get_path(spl_filesystem_object *source, size_t *path_len);
int spl_filesystem_file_open(spl_filesystem_object *intern, zend_bool use_include_path, int silent);
void zend_call_method_with_1_params(zval **object_pp, zend_class_entry *obj_ce, zend_function **fn_proxy, const char *function_name, zval **retval_ptr, zval *param1);
void zend_call_method_with_2_params(zval **object_pp, zend_class_entry *obj_ce, zend_function **fn_proxy, const char *function_name, zval **retval_ptr, zval *param1, zval *param2);
void zval_ptr_dtor(zval **zval_ptr);
void zval_dtor(zval *zvalue);
int zend_parse_parameters(int num_args, const char *type_spec, ...);