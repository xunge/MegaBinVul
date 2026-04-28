#include <stddef.h>
#include <string.h>
#include <stdbool.h>

struct page_info {
    unsigned int nr_validated_ptes;
    unsigned int partial_flags;
};

struct domain;

typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) ((mfn_t)(mfn))

typedef struct {
    unsigned long val;
} l3_pgentry_t;

#define L3_PAGETABLE_ENTRIES 512

#define _PAGE_PRESENT (1UL << 0)

#define PGT_l2_page_table 0
#define PGT_pae_xen_l2 0

#define PTF_preemptible 0
#define PTF_retain_ref_on_restart 0
#define PTF_partial_set 0

#define EINTR 4
#define EINVAL 22
#define ERESTART 512

struct arch_vcpu {
    void *old_guest_table;
    bool old_guest_table_partial;
    void *old_guest_ptpg;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

#define ASSERT(cond) ((void)0)
#define ASSERT_UNREACHABLE() ((void)0)

static inline l3_pgentry_t l3e_empty(void) { return (l3_pgentry_t){0}; }
static inline unsigned long l3e_get_flags(l3_pgentry_t l3e) { return 0; }
static inline mfn_t l3e_get_mfn(l3_pgentry_t l3e) { return 0; }
static inline void *l3e_get_page(l3_pgentry_t l3e) { return NULL; }
static inline unsigned long l3_disallow_mask(struct domain *d) { return 0; }

static inline bool is_pv_32bit_domain(struct domain *d) { return false; }
static inline bool hypercall_preempt_check(void) { return false; }
static inline bool pv_l1tf_check_l3e(struct domain *d, l3_pgentry_t l3e) { return false; }

static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline mfn_t page_to_mfn(struct page_info *page) { return 0; }

static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}

static inline l3_pgentry_t adjust_guest_l3e(l3_pgentry_t l3e, struct domain *d) { return l3e; }
static inline l3_pgentry_t unadjust_guest_l3e(l3_pgentry_t l3e, struct domain *d) { return l3e; }

static inline bool create_pae_xen_mappings(struct domain *d, l3_pgentry_t *pl3e) { return false; }

static inline int get_page_and_type_from_mfn(mfn_t mfn, unsigned int type, 
                                           struct domain *d, unsigned int flags) { return 0; }
static inline int get_page_from_l3e(l3_pgentry_t l3e, unsigned long pfn, 
                                  struct domain *d, unsigned int flags) { return 0; }

#define XENLOG_WARNING 0
#define gdprintk(level, fmt, ...) ((void)0)