#include <stddef.h>
#include <string.h>
#include <errno.h>

struct page_info;
struct domain;

#define L3_PAGETABLE_ENTRIES 512
#define _PAGE_PRESENT (1UL << 0)
#define XENLOG_WARNING 0
#define PGT_l2_page_table 0
#define PGT_pae_xen_l2 0

typedef struct {
    unsigned long val;
} mfn_t;

typedef struct {
    unsigned long val;
} l3_pgentry_t;

struct page_info {
    int partial_pte;
    unsigned int nr_validated_ptes;
};

struct domain {
    int dummy;
};

struct arch_vcpu {
    void *old_guest_ptpg;
    struct page_info *old_guest_table;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline int is_pv_32bit_domain(struct domain *d) { return 0; }
static inline unsigned long l3e_get_flags(l3_pgentry_t l3e) { return 0; }
static inline unsigned long l3_disallow_mask(struct domain *d) { return 0; }
static inline mfn_t l3e_get_mfn(l3_pgentry_t l3e) { return (mfn_t){0}; }
static inline int get_page_and_type_from_mfn(mfn_t mfn, int type, struct domain *d, int partial, int preemptible) { return 0; }
static inline int get_page_from_l3e(l3_pgentry_t l3e, unsigned long pfn, struct domain *d, int partial) { return 0; }
static inline l3_pgentry_t adjust_guest_l3e(l3_pgentry_t l3e, struct domain *d) { return l3e; }
static inline l3_pgentry_t unadjust_guest_l3e(l3_pgentry_t l3e, struct domain *d) { return l3e; }
static inline int create_pae_xen_mappings(struct domain *d, l3_pgentry_t *pl3e) { return 0; }
static inline void gdprintk(int level, const char *fmt, ...) {}

static inline mfn_t page_to_mfn(struct page_info *page) { return (mfn_t){0}; }
static inline unsigned long mfn_x(mfn_t mfn) { return mfn.val; }
static inline mfn_t _mfn(unsigned long mfn) { return (mfn_t){mfn}; }