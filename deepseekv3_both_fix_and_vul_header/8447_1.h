#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
    int is_ref;
    int refcount;
} zval;

typedef struct _HashTable {
    size_t size;
    void **elements;
} HashTable;

typedef struct _zend_function {
    const char *name;
} zend_function;

typedef struct _spl_array_object {
    void *std;
    HashTable *array;
    zend_function *fptr_offset_has;
    zend_function *fptr_offset_get;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define BP_VAR_R 0
#define SEPARATE_ARG_IF_REF(zv)
#define Z_OBJCE_P(zv) NULL
#define Z_TYPE_P(zv) (zv)->type
#define Z_STRVAL_P(zv) (zv)->value.str.val
#define Z_STRLEN_P(zv) (zv)->value.str.len
#define Z_DVAL_P(zv) (zv)->value.dval
#define Z_LVAL_P(zv) (zv)->value.lval
#define Z_ISREF_P(zv) (zv)->is_ref
#define Z_REFCOUNT_P(zv) (zv)->refcount
#define FAILURE -1
#define IS_STRING 6
#define IS_DOUBLE 5
#define IS_RESOURCE 8
#define IS_BOOL 2
#define IS_LONG 4
#define IS_NULL 0
#define E_WARNING 2

static HashTable *spl_array_get_hash_table(spl_array_object *intern, int check_inherited TSRMLS_DC);
static zval *spl_array_read_dimension_ex(int check_inherited, zval *object, zval *offset, int type TSRMLS_DC);
static int zend_is_true(zval *op);
static void zend_error(int type, const char *format, ...);
static void zend_call_method_with_1_params(zval **object_pp, void *obj_ce, zend_function **fn_proxy, const char *function_name, zval **retval_ptr, zval *param1);
static void zval_ptr_dtor(zval **zval_ptr);
static int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData);
static int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData);
static spl_array_object *zend_object_store_get_object(zval *object TSRMLS_DC);