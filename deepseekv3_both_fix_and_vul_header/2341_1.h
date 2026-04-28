#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct page_info;
struct domain;
struct arch_vcpu;

typedef uint64_t mfn_t;
typedef uint64_t l4_pgentry_t;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) ((mfn_t)(mfn))
#define L4_PAGETABLE_ENTRIES 512
#define XENLOG_WARNING 0
#define ERESTART 512
#define EINTR 4

struct page_info {
    unsigned int nr_validated_ptes;
    int partial_pte;
};

struct arch_domain {
    struct {
        int nr_l4_pages;
    } pv_domain;
};

struct arch_vcpu {
    struct page_info *old_guest_table;
    void *old_guest_ptpg;
};

struct domain {
    struct arch_domain arch;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline mfn_t page_to_mfn(struct page_info *page) { return 0; }
static inline l4_pgentry_t *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline bool is_guest_l4_slot(struct domain *d, unsigned int i) { return false; }
static inline int get_page_from_l4e(l4_pgentry_t l4e, unsigned long pfn, struct domain *d, int partial) { return 0; }
static inline l4_pgentry_t adjust_guest_l4e(l4_pgentry_t l4e, struct domain *d) { return 0; }
static inline void init_guest_l4_table(l4_pgentry_t *pl4e, struct domain *d, bool b) {}
static inline bool VM_ASSIST(struct domain *d, int type) { return false; }
#define m2p_strict 0
static inline void atomic_inc(int *count) { (*count)++; }
static inline void gdprintk(int level, const char *fmt, ...) {}