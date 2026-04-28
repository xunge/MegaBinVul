#include <stddef.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

typedef unsigned long xen_pfn_t;

struct arch_domain {
    xen_pfn_t *grant_table_gpfn;
};

struct domain {
    struct arch_domain arch;
};

extern void *alloc_xenheap_pages(unsigned int order, unsigned int memflags);
extern void clear_page(void *page);
extern void *xzalloc_array(size_t size, size_t num);
extern void *xmalloc_array(size_t size, size_t num);

extern size_t max_nr_grant_frames;

#define xzalloc_array(type, num) xzalloc_array(sizeof(type), num)
#define xmalloc_array(type, num) xmalloc_array(sizeof(type), num)