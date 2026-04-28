#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint64_t pfn_t;
typedef uint64_t mfn_t;

#define pfn_x(pfn) (pfn)
#define mfn_x(mfn) (mfn)
#define PRI_pfn "lx"
#define PRI_mfn "lx"

#define BUG_ON(cond) 
#define unlikely(cond) (cond)
#define VALID_M2P(pfn) (1)
#define SHARED_M2P(pfn) (0)
#define L1_LOGDIRTY_IDX(pfn) (0)
#define L2_LOGDIRTY_IDX(pfn) (0)
#define L3_LOGDIRTY_IDX(pfn) (0)
#define L4_LOGDIRTY_IDX(pfn) (0)
#define PAGING_DEBUG(type, ...)
#define LOGDIRTY 0

#define INVALID_MFN ((mfn_t){0})
#define mfn_eq(a, b) ((a) == (b))

struct paging_log_dirty {
    mfn_t top;
    unsigned long dirty_count;
};

struct paging_struct {
    struct paging_log_dirty log_dirty;
};

struct arch_domain {
    struct paging_struct paging;
};

struct domain {
    struct arch_domain arch;
    unsigned int domain_id;
};

void paging_lock_recursive(struct domain *d);
void paging_unlock(struct domain *d);
mfn_t paging_new_log_dirty_node(struct domain *d);
mfn_t paging_new_log_dirty_leaf(struct domain *d);
void *map_domain_page(mfn_t mfn);
void unmap_domain_page(void *ptr);
bool paging_mode_log_dirty(struct domain *d);
bool paging_mode_translate(struct domain *d);
void *paging_map_log_dirty_bitmap(struct domain *d);
bool __test_and_set_bit(unsigned long nr, volatile unsigned long *addr);