#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct zval;
typedef struct _hashtable HashTable;

#define UNSERIALIZE_PARAMETER const unsigned char **p, const unsigned char *max, void *var_hash
#define TSRMLS_CC
#define TSRMLS_DC
#define ALLOC_INIT_ZVAL(z) \
    (z) = (zval *)malloc(sizeof(zval)); \
    (z)->type = IS_NULL
#define FREE_ZVAL(z) free(z)
#define Z_TYPE_P(z) (z)->type
#define Z_LVAL_P(z) (z)->value.lval
#define Z_STRVAL_P(z) (z)->value.str.val
#define Z_STRLEN_P(z) (z)->value.str.len
#define IS_LONG 1
#define IS_STRING 2
#define IS_NULL 3
#define SUCCESS 0

typedef union _zvalue_value {
    long lval;
    struct {
        char *val;
        int len;
    } str;
    void *ptr;
} zvalue_value;

struct _zval_struct {
    zvalue_value value;
    unsigned char type;
};

static inline void zval_dtor(zval *z) {}
static inline int php_var_unserialize(zval **rval, const unsigned char **p, const unsigned char *max, void *var_hash) { return 0; }
static inline void var_push_dtor(void *var_hash, zval **old_data) {}
static inline void convert_to_string(zval *op) {}

static inline int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData) { return 0; }
static inline int zend_hash_index_update(HashTable *ht, unsigned long h, void *pData, unsigned int nDataSize, void **pDest) { return 0; }
static inline int zend_symtable_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData) { return 0; }
static inline int zend_symtable_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, unsigned int nDataSize, void **pDest) { return 0; }
static inline int zend_hash_find(HashTable *ht, char *arKey, unsigned int nKeyLength, void **pData) { return 0; }
static inline int zend_hash_update(HashTable *ht, char *arKey, unsigned int nKeyLength, void *pData, unsigned int nDataSize, void **pDest) { return 0; }