#include <stdlib.h>
#include <stddef.h>

#define MAX_RW_COUNT ((1UL << 31) - 1)
#define GFP_KERNEL_ACCOUNT 0
#define unlikely(x) (x)

static void *kvmalloc(size_t size, int flags) {
    return malloc(size);
}