#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct zval;
typedef struct _hashtable HashTable;
typedef struct _zend_rsrc_list_entry zend_rsrc_list_entry;

#define UNSERIALIZE_PARAMETER const unsigned char **p, size_t max, void *var_hash
#define TSRMLS_CC
#define ALLOC_INIT_ZVAL(z) \
    (z) = (zval *)malloc(sizeof(zval))
#define FREE_ZVAL(z) \
    free(z)
#define Z_TYPE_P(z) (z)->type
#define Z_LVAL_P(z) (z)->value.lval
#define Z_STRVAL_P(z) (z)->value.str.val
#define Z_STRLEN_P(z) (z)->value.str.len
#define IS_LONG 1
#define IS_STRING 2
#define SUCCESS 0

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

void zval_dtor(zval *z);
int php_var_unserialize(zval **rval, const unsigned char **p, const unsigned char *max, void *var_hash);
int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData);
int zend_hash_index_update(HashTable *ht, unsigned long h, void *pData, unsigned int nDataSize, void **pDest);
int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData);
int zend_symtable_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, unsigned int nDataSize, void **pDest);
int zend_hash_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, unsigned int nDataSize, void **pDest);
void var_push_dtor(void *var_hash, zval **old_data);
void convert_to_string(zval *op);