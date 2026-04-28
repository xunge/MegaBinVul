#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint64_t pfn_t;
typedef uint64_t mfn_t;

#define pfn_x(pfn) (pfn)
#define mfn_x(mfn) (mfn)
#define PRI_pfn "lx"
#define PRI_mfn "lx"

#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define unlikely(cond) (cond)
#define VALID_M2P(pfn) ((pfn) < (1ULL << 55))
#define SHARED_M2P(pfn) (0)
#define L1_LOGDIRTY_IDX(pfn) ((pfn) & 0x1ff)
#define L2_LOGDIRTY_IDX(pfn) (((pfn) >> 9) & 0x1ff)
#define L3_LOGDIRTY_IDX(pfn) (((pfn) >> 18) & 0x1ff)
#define L4_LOGDIRTY_IDX(pfn) (((pfn) >> 27) & 0x1ff)

#define PAGING_DEBUG(type, fmt, ...)

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
    unsigned int domain_id;
    struct arch_domain arch;
};

static inline bool paging_mode_log_dirty(struct domain *d) { return false; }
static inline void paging_lock_recursive(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline mfn_t paging_new_log_dirty_node(struct domain *d) { return 0; }
static inline mfn_t paging_new_log_dirty_leaf(struct domain *d) { return 0; }
static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline bool mfn_valid(mfn_t mfn) { return true; }
static inline void *paging_map_log_dirty_bitmap(struct domain *d) { return NULL; }
static inline bool __test_and_set_bit(unsigned long nr, volatile unsigned long *addr) { return false; }