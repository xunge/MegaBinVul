#include <stdint.h>
#include <stddef.h>

typedef uint64_t ut64;

typedef struct RFlagsAtOffset {
    ut64 off;
} RFlagsAtOffset;

typedef struct RFlag {
    void *by_off;
} RFlag;

void* r_skiplist_get_geq(void *list, void *key);
void* r_skiplist_get_leq(void *list, void *key);