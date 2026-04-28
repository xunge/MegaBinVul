#include <stdlib.h>

typedef struct _zend_object {
    // 最小化定义
    void *properties;
    void *handlers;
} zend_object;

typedef struct _HashTable {
    // 最小化定义
    void *arData;
    unsigned int nTableSize;
    unsigned int nNumUsed;
    unsigned int nNumOfElements;
} HashTable;

typedef struct _spl_SplObjectStorage {
    zend_object std;
    HashTable storage;
    HashTable *debug_info;
} spl_SplObjectStorage;

#define TSRMLS_DC
#define TSRMLS_CC

void zend_object_std_dtor(zend_object *object TSRMLS_DC);
void zend_hash_destroy(HashTable *ht);
void efree(void *ptr);