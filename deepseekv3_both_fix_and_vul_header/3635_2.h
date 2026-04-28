#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SHIFT 12
#define GV2M_WRITE 1

typedef uintptr_t vaddr_t;
typedef uintptr_t paddr_t;

extern int gvirt_to_maddr(vaddr_t vaddr, paddr_t *paddr, ...);
extern void *map_domain_page(unsigned long mfn);
extern void unmap_domain_page(void *va);
extern void clean_xen_dcache_va_range(void *va, unsigned long size);

#define min(a, b) ((a) < (b) ? (a) : (b))