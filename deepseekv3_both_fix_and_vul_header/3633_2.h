#include <stddef.h>
#include <string.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SHIFT 12
#define GV2M_READ 0

typedef unsigned long vaddr_t;
typedef unsigned long paddr_t;

extern int gvirt_to_maddr(vaddr_t vaddr, paddr_t *paddr, ...);
extern void *map_domain_page(unsigned long mfn);
extern void unmap_domain_page(const void *vaddr);

#define min(a, b) ((a) < (b) ? (a) : (b))
#define __user