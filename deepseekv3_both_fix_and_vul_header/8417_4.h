#include <stdlib.h>
#include <string.h>

#define IS_OBJECT 7
#define IS_STRING 6

typedef struct _HashTable {
    unsigned int nTableSize;
    unsigned int nTableMask;
    unsigned int nNumOfElements;
} HashTable;

typedef struct _zval_struct {
    unsigned char type;
    union {
        long lval;
        struct {
            char *val;
            int len;
        } str;
        struct {
            HashTable *properties;
            struct _zend_class_entry *ce;
        } obj;
    } value;
    unsigned int refcount__gc;
    unsigned char is_ref__gc;
} zval;

typedef struct _zend_class_entry {
    HashTable function_table;
    char *name;
} zend_class_entry;

typedef struct _php_core_globals {
    int serialize_lock;
} php_core_globals;

typedef struct _zend_executor_globals {
    void *exception;
} zend_executor_globals;

typedef struct _php_unserialize_data_t {
    void *data;
} php_unserialize_data_t;

typedef struct _zend_compiler_globals {
    HashTable *function_table;
} zend_compiler_globals;

#define UNSERIALIZE_PARAMETER zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash
#define UNSERIALIZE_PASSTHRU rval, p, max, var_hash
#define TSRMLS_CC
#define TSRMLS_D

extern zend_class_entry *PHP_IC_ENTRY;
extern zend_executor_globals EG;
extern php_core_globals BG;
extern zend_compiler_globals CG;

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_OBJPROP_PP(ppzval) ((*ppzval)->value.obj.properties)
#define Z_OBJCE_PP(ppzval) ((*ppzval)->value.obj.ce)
#define INIT_PZVAL(z) do { (z)->refcount__gc = 1; (z)->is_ref__gc = 0; } while (0)
#define ZVAL_STRINGL(z, s, l, dup) do { \
    (z)->value.str.val = (dup ? strndup((s), (l)) : (char *)(s)); \
    (z)->value.str.len = (l); \
    (z)->type = IS_STRING; \
} while (0)

#define BG(v) (BG.v)
#define EG(v) (EG.v)
#define CG(v) (CG.v)

static inline int process_nested_data(UNSERIALIZE_PARAMETER, HashTable *ht, long elements, int obj) { return 0; }
static inline int finish_nested_data(UNSERIALIZE_PARAMETER) { return 0; }
static inline int zend_hash_exists(HashTable *ht, const char *key, size_t len) { return 0; }
static inline void call_user_function_ex(HashTable *function_table, zval **object, zval *function_name, zval **retval_ptr, int param_count, int no_separation, int check_flags, void *__) {}
static inline void zval_ptr_dtor(zval **zval_ptr) {}