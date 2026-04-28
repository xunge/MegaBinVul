#include <stddef.h>
#include <stdint.h>

#define P2M_LIMIT 0
#define PAGE_SIZE 4096
#define PMD_SIZE 0
#define PMDS_PER_MID_PAGE 0
#define XEN_EXTRA_MEM_RATIO 0
#define VM_ALLOC 0
#define CONFIG_XEN_UNPOPULATED_ALLOC 0
#define IS_ENABLED(x) 0
#define __init

typedef uint64_t phys_addr_t;

extern unsigned long xen_max_p2m_pfn;
extern unsigned long xen_p2m_last_pfn;
extern unsigned long *xen_p2m_addr;
extern unsigned long xen_p2m_size;

struct start_info {
    unsigned long nr_pages;
};

extern struct start_info *xen_start_info;

struct vm_struct {
    unsigned long flags;
    unsigned long size;
    void *addr;
};

unsigned long max(unsigned long a, unsigned long b);
unsigned long ALIGN(unsigned long size, unsigned long align);
void vm_area_register_early(struct vm_struct *vm, unsigned long align);
void xen_rebuild_p2m_list(void *addr);
void xen_inv_extra_mem(void);
void pr_notice(const char *fmt, ...);