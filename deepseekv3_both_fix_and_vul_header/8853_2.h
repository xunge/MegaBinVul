#include <stdint.h>

#define ZEND_FASTCALL
#define ZEND_FILE_LINE_DC

typedef unsigned int zend_bool;
typedef void (*dtor_func_t)(void *);

typedef struct _zend_array HashTable;
struct _zend_array {
    struct {
        int refcount;
        union {
            int type_info;
        } u;
    } gc;
    uint32_t nTableSize;
    uint32_t nTableMask;
    uint32_t nNumUsed;
    uint32_t nNumOfElements;
    uint32_t nInternalPointer;
    uint32_t nNextFreeElement;
    dtor_func_t pDestructor;
    union {
        struct {
            uint32_t flags;
        } u;
    };
};

#define GC_REFCOUNT(p) ((p)->gc.refcount)
#define GC_TYPE_INFO(p) ((p)->gc.u.type_info)
#define IS_ARRAY 7
#define HASH_FLAG_PERSISTENT (1<<0)
#define HASH_FLAG_APPLY_PROTECTION (1<<1)
#define HASH_FLAG_STATIC_KEYS (1<<2)
#define HT_MIN_MASK ((uint32_t) -2)
#define HT_INVALID_IDX ((uint32_t) -1)
#define HT_SET_DATA_ADDR(ht, ptr) do { } while (0)

static struct {
    int dummy;
} uninitialized_bucket;

static uint32_t zend_hash_check_size(uint32_t nSize) {
    return nSize;
}