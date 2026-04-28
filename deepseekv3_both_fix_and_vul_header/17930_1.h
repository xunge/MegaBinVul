#include <string.h>

#define PAGE_CACHE_SHIFT 12
#define PAGE_CACHE_SIZE (1 << PAGE_CACHE_SHIFT)
#define PAGE_CACHE_MASK (~(PAGE_CACHE_SIZE - 1))

enum km_type {
    KM_USER0,
    KM_TYPE_NR
};

struct page {
    unsigned long flags;
};

void *kmap_atomic(struct page *page, enum km_type type);
void kunmap_atomic(void *addr, enum km_type type);