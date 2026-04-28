#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define UNSERIALIZE_PARAMETER zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash
#define UNSERIALIZE_PASSTHRU rval, p, max, var_hash

#define IS_OBJECT 7
#define IS_STRING 6
#define TSRMLS_CC

typedef struct _zval_struct {
    int type;
    union {
        struct {
            void *properties;
            struct _zend_class_entry *ce;
        } obj;
        struct {
            char *val;
            size_t len;
        } str;
    } value;
    int refcount__gc;
    int is_ref__gc;
} zval;

typedef struct _zend_class_entry {
    struct {
        void *function_table;
    } function_table;
} zend_class_entry;

typedef struct _php_unserialize_data_t {
    void *data;
} php_unserialize_data_t;

struct _zend_compiler_globals {
    void *function_table;
};
struct _zend_executor_globals {
    void *exception;
};
struct _php_core_globals {
    int serialize_lock;
};

extern zend_class_entry *PHP_IC_ENTRY;
extern struct _zend_compiler_globals CG;
extern struct _zend_executor_globals EG;
extern struct _php_core_globals BG;

#define Z_TYPE_PP(ppzval) ((*(ppzval))->type)
#define Z_OBJPROP_PP(ppzval) ((*(ppzval))->value.obj.properties)
#define Z_OBJCE_PP(ppzval) ((*(ppzval))->value.obj.ce)
#define INIT_PZVAL(zv) do { (zv)->refcount__gc = 1; (zv)->is_ref__gc = 0; } while (0)
#define ZVAL_STRINGL(zv, s, l, dup) do { \
    (zv)->value.str.val = (dup ? strndup((s), (l)) : (char*)(s)); \
    (zv)->value.str.len = (l); \
    (zv)->type = IS_STRING; \
} while (0)

#define BG(v) (BG.v)
#define CG(v) (CG.v)
#define EG(v) (EG.v)

static inline int process_nested_data(UNSERIALIZE_PARAMETER, void *properties, long elements, int nested) { return 0; }
static inline int finish_nested_data(UNSERIALIZE_PARAMETER) { return 0; }
static inline int zend_hash_exists(void *ht, const char *arKey, unsigned int nKeyLength) { return 0; }
static inline int call_user_function_ex(void *function_table, zval **object, zval *function_name, zval **retval_ptr, int param_count, int no_separation, int check_flags, void *params) { return 0; }
static inline void zval_ptr_dtor(zval **zval_ptr) {}