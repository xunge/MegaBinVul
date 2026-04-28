#include <stddef.h>
#include <stdatomic.h>
#include <errno.h>

#define GFP_KERNEL 0
#define GFP_DMA32 0
#define __GFP_ZERO 0

struct page {
    void* data;
};

struct agp_bridge_data {
    atomic_int current_memory_agp;
};

struct agp_memory {
    unsigned long *memory;
    unsigned int page_count;
};

extern struct agp_bridge_data *agp_bridge;

static inline struct page* alloc_page(int flags) { return NULL; }
static inline void map_page_into_agp(struct page* page) {}
static inline void get_page(struct page* page) {}
static inline void atomic_inc(atomic_int* v) {}
static inline void* page_address(struct page* page) { return NULL; }
static inline unsigned long virt_to_gart(void* addr) { return 0; }
static inline void set_memory_array_uc(unsigned long* mem, size_t num_pages) {}