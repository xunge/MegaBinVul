#include <stddef.h>

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        double dval;
        char *strval;
    } value;
} zval;

typedef struct _zend_object {
    int dummy;
} zend_object;

typedef struct _zend_function {
    int dummy;
} zend_function;

typedef struct _HashTable {
    int dummy;
} HashTable;

typedef struct _spl_array_object {
    zend_object std;
    HashTable *array;
    zend_function *fptr_offset_has;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define SEPARATE_ARG_IF_REF(x)
#define zend_object_store_get_object(x) ((spl_array_object*)(x))
#define Z_OBJCE_P(x) NULL
#define Z_TYPE_P(x) ((x)->type)
#define Z_STRVAL_P(x) ((x)->value.strval)
#define Z_STRLEN_P(x) (strlen((x)->value.strval))
#define Z_DVAL_P(x) ((x)->value.dval)
#define Z_LVAL_P(x) ((x)->value.lval)
#define Z_TYPE_PP(x) ((*x)->type)
#define IS_STRING 1
#define IS_DOUBLE 2
#define IS_RESOURCE 3
#define IS_BOOL 4
#define IS_LONG 5
#define IS_NULL 6
#define FAILURE -1
#define E_WARNING 1

static int zend_is_true(zval *z) { return 0; }
static void zend_error(int type, const char *message) {}
static void zval_ptr_dtor(zval **z) {}
static void zend_call_method_with_1_params(zval **object, void *ce, zend_function **fn, const char *name, zval **rv, zval *p1) {}
static HashTable *spl_array_get_hash_table(spl_array_object *intern, int flags) { return NULL; }
static int zend_symtable_find(HashTable *ht, const char *key, unsigned int len, void **result) { return 0; }
static int zend_hash_index_find(HashTable *ht, unsigned long idx, void **result) { return 0; }