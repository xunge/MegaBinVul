#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct zval;
typedef struct _spl_SplObjectStorageElement spl_SplObjectStorageElement;
typedef struct _spl_SplObjectStorage spl_SplObjectStorage;

struct _spl_SplObjectStorageElement {
    zval *obj;
    zval *inf;
};

struct _spl_SplObjectStorage {
    void *storage;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define Z_ADDREF_P(zv)
#define ALLOC_INIT_ZVAL(zv)
#define zval_ptr_dtor(zv)