#include <stdbool.h>
#include <stddef.h>

struct page_info;
struct vcpu {
    struct {
        unsigned long cr3;
        void *guest_table;
        void *guest_table_user;
        void *old_guest_ptpg;
        void *old_guest_table;
        bool old_guest_table_partial;
    } arch;
    struct domain *domain;
};

struct domain;

typedef struct {
    unsigned long pfn;
} l4_pgentry_t;

#define _mfn(mfn) ((unsigned long)(mfn))
#define l4e_get_pfn(l4e) ((l4e).pfn)
#define l4e_write(l4tab, l4e) (*(l4tab) = (l4e))
#define l4e_empty() ((l4_pgentry_t){0})

#define pagetable_get_pfn(p) (0)
#define pagetable_null() (NULL)
#define put_old_guest_table(v) (0)
#define is_pv_32bit_vcpu(v) (0)
#define paging_mode_refcounts(d) (0)
#define put_page(p) (0)
#define put_page_and_type_preemptible(p) (0)
#define map_domain_page(mfn) (NULL)
#define unmap_domain_page(p) 
#define mfn_to_page(mfn) (NULL)
#define ASSERT(cond)
#define EINTR 4
#define ERESTART 512