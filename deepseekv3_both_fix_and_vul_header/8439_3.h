#include <stddef.h>

#define IS_OBJECT 7

typedef struct _zval_struct {
    int type;
    void *value;
} zval;

typedef struct _zend_class_entry {
    struct {
        void *function_table;
    } function_table;
} zend_class_entry;

typedef struct _zend_executor_globals {
    int exception;
} zend_executor_globals;

typedef struct _zend_compiler_globals {
    void *function_table;
} zend_compiler_globals;

typedef struct _zend_basic_globals {
    int serialize_lock;
} zend_basic_globals;

#define UNSERIALIZE_PARAMETER zval **rval, zend_class_entry *ce, const unsigned char **p, const unsigned char *max, void *var_hash
#define UNSERIALIZE_PASSTHRU rval, ce, p, max, var_hash

#define Z_TYPE_PP(ppzval) ((*(ppzval))->type)
#define Z_OBJPROP_PP(ppzval) ((*(ppzval))->value)
#define Z_OBJCE_PP(ppzval) ((zend_class_entry *)(*(ppzval))->value)
#define ZVAL_NULL(zval) ((zval)->type = 0, (zval)->value = NULL)
#define INIT_PZVAL(zval) ((void)0)
#define ZVAL_STRINGL(zval, str, len, dup) ((void)0)
#define TSRMLS_CC

#define BG(v) (BG.v)
#define CG(v) (CG.v)
#define EG(v) (EG.v)

extern zend_class_entry *PHP_IC_ENTRY;
extern zend_executor_globals EG;
extern zend_compiler_globals CG;
extern zend_basic_globals BG;

static inline int process_nested_data(UNSERIALIZE_PARAMETER, void *props, long elements, int nested) { return 0; }
static inline int finish_nested_data(UNSERIALIZE_PARAMETER) { return 0; }
static inline int zend_hash_clean(void *ht) { return 0; }
static inline int zend_hash_exists(void *ht, const char *key, size_t key_len) { return 0; }
static inline int call_user_function_ex(void *function_table, void *object, void *function_name, void **retval_ptr, int param_count, int no_separation, int check_flags, void *params) { return 0; }
static inline void zval_ptr_dtor(zval **zval_ptr) {}