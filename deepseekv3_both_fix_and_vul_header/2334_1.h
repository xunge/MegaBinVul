#include <stddef.h>
#include <string.h>

typedef unsigned long mfn_t;

struct arch_domain {
    void *perdomain_l3_pg;
};

struct domain {
    struct arch_domain arch;
};

typedef union {
    unsigned long l4;
} shadow_l4e_t;

typedef union {
    unsigned long l4;
} l4_pgentry_t;

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define shadow_mode_external(d) (0)
#define shadow_mode_translate(d) (0)
#define is_pv_32bit_domain(d) (0)
#define VM_ASSIST(d, flag) (0)
#define ROOT_PAGETABLE_XEN_SLOTS 0
#define ROOT_PAGETABLE_PV_XEN_SLOTS 0
#define ROOT_PAGETABLE_FIRST_XEN_SLOT 0
#define PERDOMAIN_VIRT_START 0
#define SH_LINEAR_PT_VIRT_START 0
#define LINEAR_PT_VIRT_START 0
#define RO_MPT_VIRT_START 0
#define __PAGE_HYPERVISOR_RW 0
#define mfn_x(mfn) (mfn)
#define shadow_l4_table_offset(addr) (0)

extern l4_pgentry_t idle_pg_table[];
extern void *map_domain_page(mfn_t);
extern void unmap_domain_page(void *);
extern mfn_t page_to_mfn(void *);
extern shadow_l4e_t shadow_l4e_from_mfn(mfn_t, unsigned long);
extern shadow_l4e_t shadow_l4e_empty(void);