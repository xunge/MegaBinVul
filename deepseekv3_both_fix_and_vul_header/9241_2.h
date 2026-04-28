#include <stddef.h>

typedef struct _zval_struct {
    long lval;
    struct {
        void *pDestructor;
    } value;
} zval;

typedef struct _hashtable {
    unsigned int nTableSize;
    unsigned int nTableMask;
    unsigned int nNumOfElements;
    unsigned int nNextFreeElement;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void **arBuckets;
    void *pDestructor;
} HashTable;

typedef struct _Bucket {
    void *pData;
    void *pDataPtr;
    struct _Bucket *pListNext;
    struct _Bucket *pListLast;
    struct _Bucket *pNext;
    struct _Bucket *pLast;
    const char *arKey;
    unsigned int nKeyLength;
    unsigned int h;
} Bucket;

typedef Bucket* HashPosition;

typedef struct _spl_SplObjectStorageElement {
    zval *obj;
    zval *inf;
} spl_SplObjectStorageElement;

typedef struct _spl_SplObjectStorage {
    HashTable storage;
} spl_SplObjectStorage;

typedef struct _zend_object_handlers {
    HashTable* (*get_properties)(zval *object);
} zend_object_handlers;

extern zend_object_handlers std_object_handlers;

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define MAKE_STD_ZVAL(zv) ((zv) = malloc(sizeof(zval)))
#define Z_ARRVAL_P(zv) ((HashTable*)((zv)->value.pDestructor))

void* zend_object_store_get_object(zval *obj);
int zend_hash_find(HashTable *ht, const char *arKey, unsigned int nKeyLength, void **pData);
void zend_hash_clean(HashTable *ht);
void array_init(zval *arg);
int zend_hash_add(HashTable *ht, const char *arKey, unsigned int nKeyLength, void *pData, unsigned int pDataSize, void **pDest);
void zend_hash_internal_pointer_reset_ex(HashTable *ht, HashPosition *pos);
int zend_hash_get_current_data_ex(HashTable *ht, void **pData, HashPosition *pos);
void add_next_index_zval(zval *arg, zval *value);
void zend_hash_move_forward_ex(HashTable *ht, HashPosition *pos);