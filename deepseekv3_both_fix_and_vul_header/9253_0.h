#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _zval_struct zval;
typedef struct _zend_object_store zend_object_store;
typedef struct _zend_object_store_bucket zend_object_store_bucket;
typedef struct _HashTable HashTable;
typedef struct _spl_array_object spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(x) (x)
#define BP_VAR_R 0
#define BP_VAR_W 1
#define BP_VAR_RW 2
#define BP_VAR_UNSET 3
#define BP_VAR_IS 4
#define IS_NULL 0
#define IS_STRING 1
#define IS_RESOURCE 2
#define IS_DOUBLE 3
#define IS_BOOL 4
#define IS_LONG 5
#define FAILURE -1
#define E_WARNING 1
#define E_NOTICE 2
#define E_STRICT 3

#define Z_TYPE_P(zval_ptr) (zval_ptr)->type
#define Z_STRVAL_P(zval_ptr) (zval_ptr)->value.str.val
#define Z_STRLEN_P(zval_ptr) (zval_ptr)->value.str.len
#define Z_LVAL_P(zval_ptr) (zval_ptr)->value.lval
#define Z_DVAL_P(zval_ptr) (zval_ptr)->value.dval

extern zval *uninitialized_zval_ptr;
extern zval *error_zval_ptr;

struct _zval_struct {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
};

struct _HashTable {
    int nApplyCount;
};

void *zend_object_store_get_object(zval *object TSRMLS_DC);
HashTable *spl_array_get_hash_table(spl_array_object *intern, int check_inherited TSRMLS_DC);
int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData);
int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData);
int zend_symtable_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData, unsigned int pDataSize, void **pDest);
int zend_hash_index_update(HashTable *ht, unsigned long h, void **pData, unsigned int pDataSize, void **pDest);
void ALLOC_INIT_ZVAL(zval *value);
void zend_error(int type, const char *format, ...);