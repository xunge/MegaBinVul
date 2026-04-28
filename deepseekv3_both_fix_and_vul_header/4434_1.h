#include <stdlib.h>
#include <string.h>

struct xt_table_info {
    unsigned int size;
};

#define SMP_ALIGN(x) (((x) + 7) & ~7)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_ALLOC_COSTLY_ORDER 3
#define GFP_KERNEL 0
#define __GFP_NOWARN 0
#define __GFP_NORETRY 0

extern unsigned long totalram_pages;

void* kmalloc(size_t size, int flags);
void* vmalloc(size_t size);