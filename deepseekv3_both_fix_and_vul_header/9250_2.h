#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

typedef struct _zend_object {
    void *ce;
} zend_object;

typedef struct _zend_function {
    const char *function_name;
} zend_function;

typedef struct _HashTable {
    unsigned int nApplyCount;
} HashTable;

typedef struct _spl_array_object {
    zend_object std;
    HashTable *array;
    zend_function *fptr_offset_set;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define ALLOC_INIT_ZVAL(z) do { (z) = malloc(sizeof(zval)); } while(0)
#define SEPARATE_ARG_IF_REF(z)
#define Z_OBJCE_P(z) ((zend_object*)(z))->ce
#define Z_ADDREF_P(z)
#define Z_TYPE_P(z) ((zval*)(z))->type
#define Z_STRVAL_P(z) ((zval*)(z))->value.str.val
#define Z_STRLEN_P(z) ((zval*)(z))->value.str.len
#define Z_DVAL_P(z) ((zval*)(z))->value.dval
#define Z_LVAL_P(z) ((zval*)(z))->value.lval

enum {
    IS_NULL,
    IS_LONG,
    IS_DOUBLE,
    IS_STRING,
    IS_ARRAY,
    IS_OBJECT,
    IS_BOOL,
    IS_RESOURCE
};

#define E_WARNING 2

static HashTable* spl_array_get_hash_table(spl_array_object *intern, int flags TSRMLS_DC);
static void zend_error(int type, const char *format, ...);
static void zend_call_method_with_2_params(zval **object, zend_object *ce, zend_function **fptr, const char *function_name, void *retval, zval *arg1, zval *arg2);
static void zend_hash_next_index_insert(HashTable *ht, void **pData, size_t pDataSize, void *dest);
static void zend_symtable_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData, size_t pDataSize, void *dest);
static void zend_hash_index_update(HashTable *ht, unsigned long h, void **pData, size_t pDataSize, void *dest);
static void zval_ptr_dtor(zval **z);