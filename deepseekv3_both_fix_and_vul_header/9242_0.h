#include <stddef.h>
#include <stdint.h>

typedef struct _zval_struct zval;
typedef struct _spl_SplObjectStorage spl_SplObjectStorage;

#define TSRMLS_DC
#define TSRMLS_CC
#define FAILURE -1

struct _spl_SplObjectStorage {
    void *storage;
};

int zend_hash_del(void *ht, const char *arKey, unsigned int nKeyLength);
char *spl_object_storage_get_hash(spl_SplObjectStorage *intern, zval *this, zval *obj, int *hash_len TSRMLS_DC);
void spl_object_storage_free_hash(spl_SplObjectStorage *intern, char *hash);