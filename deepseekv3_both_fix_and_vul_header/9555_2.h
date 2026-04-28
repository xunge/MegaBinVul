#include <stdlib.h>
#include <string.h>

#define UNSERIALIZE_PARAMETER const unsigned char **p, const unsigned char *max, void *var_hash
#define TSRMLS_CC
#define ALLOC_INIT_ZVAL(z) do { z = malloc(sizeof(zval)); memset(z, 0, sizeof(zval)); } while (0)
#define FREE_ZVAL(z) free(z)
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

typedef struct _HashTable {
    void *buckets;
} HashTable;

static inline void zval_dtor(zval *z) {}
static inline int php_var_unserialize(zval **rval, const unsigned char **p, const unsigned char *max, void *var_hash) { return 0; }
static inline void var_push_dtor(void *var_hash, zval **old_data) {}
static inline void convert_to_string(zval *op) {}
static inline int zend_hash_index_find(HashTable *ht, long h, void **pData) { return 0; }
static inline int zend_hash_index_update(HashTable *ht, long h, void *pData, size_t nDataSize, void **pDest) { return 0; }
static inline int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData) { return 0; }
static inline int zend_symtable_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, size_t nDataSize, void **pDest) { return 0; }
static inline int zend_hash_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, size_t nDataSize, void **pDest) { return 0; }