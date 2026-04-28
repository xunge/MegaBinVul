#include <stdlib.h>
#include <limits.h>

struct page;
struct agp_memory {
    int key;
    struct page **pages;
    unsigned int num_scratch_pages;
};

#define GFP_KERNEL 0

extern int agp_get_key(void);
extern void agp_free_key(int key);
extern void agp_alloc_page_array(unsigned long size, struct agp_memory *mem);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);