#include <stdatomic.h>
#include <stddef.h>

struct agp_bridge_data {
    atomic_int current_memory_agp;
};

extern struct agp_bridge_data *agp_bridge;

struct page {
    unsigned long flags;
};

#define GFP_KERNEL 0
#define GFP_DMA32 0
#define __GFP_ZERO 0

struct page *alloc_page(unsigned int flags);
void map_page_into_agp(struct page *page);
void get_page(struct page *page);
void *page_address(struct page *page);
void atomic_inc(atomic_int *v);