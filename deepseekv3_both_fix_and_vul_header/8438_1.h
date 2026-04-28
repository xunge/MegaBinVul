#include <stdint.h>

typedef intptr_t zend_long;
typedef uintptr_t zend_ulong;

typedef struct _zval_struct zval;
typedef struct _zend_object_handlers zend_object_handlers;
typedef struct _zend_object_store_bucket zend_object_store_bucket;
typedef struct _zend_objects_store zend_objects_store;
typedef unsigned int zend_object_handle;

struct _zend_object_handlers {
    // 这里只需要声明结构体存在，具体成员不重要
};

struct _zend_object_store_bucket {
    union {
        struct {
            zend_object_handlers *handlers;
        } obj;
    } bucket;
    unsigned int destructor_called;
};

struct _zend_objects_store {
    zend_object_store_bucket *object_buckets;
};

#define ZEND_API
#define TSRMLS_DC
#define EG(e) (executor_globals.e)
#define Z_OBJ_HANDLE_P(z) (0)
#define Z_OBJ_HT_P(z) (0)

extern struct {
    zend_objects_store objects_store;
} executor_globals;