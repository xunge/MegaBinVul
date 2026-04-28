#include <stddef.h>
#include <string.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

typedef unsigned long vaddr_t;
typedef unsigned long paddr_t;

#define GV2M_WRITE 0

unsigned long gvirt_to_maddr(vaddr_t vaddr, paddr_t *paddr, ...);
void *map_domain_page(unsigned long mfn);
void unmap_domain_page(const void *ptr);

#define min(a, b) ((a) < (b) ? (a) : (b))