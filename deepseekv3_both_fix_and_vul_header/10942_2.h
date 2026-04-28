#include <stdbool.h>
#include <stddef.h>

typedef unsigned long l2_pgentry_t;
typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

struct page_info {
    unsigned long partial_flags;
    unsigned int nr_validated_ptes;
};

struct domain {
    // dummy structure
};

struct arch_vcpu {
    struct page_info *old_guest_table;
    void *old_guest_ptpg;
    bool old_guest_table_partial;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) ((mfn_t)(mfn))
#define page_to_mfn(pg) ((mfn_t)((unsigned long)(pg)))
#define L2_PAGETABLE_ENTRIES 512
#define _PAGE_PRESENT (1UL << 0)
#define PGT_pae_xen_l2 (1UL << 0)
#define XENLOG_WARNING 1
#define EINTR 4
#define ERESTART 512
#define EINVAL 22

static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline l2_pgentry_t *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline bool is_guest_l2_slot(struct domain *d, unsigned long type, unsigned int i) { return false; }
static inline unsigned long l2e_get_flags(l2_pgentry_t l2e) { return 0; }
static inline bool pv_l1tf_check_l2e(struct domain *d, l2_pgentry_t l2e) { return false; }
static inline int get_page_from_l2e(l2_pgentry_t l2e, pfn_t pfn, struct domain *d, unsigned long flags) { return 0; }
static inline l2_pgentry_t adjust_guest_l2e(l2_pgentry_t l2e, struct domain *d) { return 0; }
static inline void init_xen_pae_l2_slots(l2_pgentry_t *pl2e, struct domain *d) {}
static inline bool hypercall_preempt_check(void) { return false; }
#define ASSERT(cond) ((void)0)
#define gdprintk(lvl, fmt, ...) ((void)0)