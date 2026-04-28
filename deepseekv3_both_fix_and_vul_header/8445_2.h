#include <stdint.h>
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

typedef struct _zend_function {
    int type;
} zend_function;

typedef struct _zend_object {
    int type;
} zend_object;

typedef struct _HashTable {
    int dummy;
} HashTable;

typedef struct _spl_array_object {
    zend_object std;
    HashTable *array;
    zend_function *fptr_offset_has;
    zend_function *fptr_offset_get;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define BP_VAR_R 0
#define SEPARATE_ARG_IF_REF(z)
#define zend_object_store_get_object(obj) ((spl_array_object*)(obj))
#define zend_is_true(z) 1
#define zval_ptr_dtor(z)
#define Z_OBJCE_P(z) NULL
#define Z_TYPE_P(z) ((z)->type)
#define Z_STRVAL_P(z) ((z)->value.str.val)
#define Z_STRLEN_P(z) ((z)->value.str.len)
#define Z_DVAL_P(z) ((z)->value.dval)
#define Z_LVAL_P(z) ((z)->value.lval)
#define IS_STRING 1
#define IS_DOUBLE 2
#define IS_RESOURCE 3
#define IS_BOOL 4
#define IS_LONG 5
#define IS_NULL 6
#define FAILURE -1
#define E_WARNING 0

extern zval *spl_array_read_dimension_ex(int check_inherited, zval *object, zval *offset, int type TSRMLS_DC);
extern HashTable *spl_array_get_hash_table(spl_array_object *intern, int check_inherited TSRMLS_DC);
extern int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData);
extern int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData);
extern void zend_error(int type, char *error);
extern void zend_call_method_with_1_params(zval **object, void *obj_ce, zend_function **fn_proxy, char *function_name, zval **retval, zval *param);