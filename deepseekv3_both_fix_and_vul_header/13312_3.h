#include <stdbool.h>
#include <stddef.h>

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;

#define INVALID_MFN ((mfn_t)-1)
#define mfn_x(mfn) (mfn)
#define mfn_eq(a, b) ((a) == (b))
#define mfn_add(mfn, n) ((mfn) + (n))
#define _gfn(gfn) ((gfn_t)(gfn))

struct paging_domain {
    unsigned long total_pages;
};

struct arch_domain {
    struct paging_domain paging;
};

struct domain {
    struct arch_domain arch;
    unsigned long dirty_cpumask;
};

typedef unsigned int p2m_type_t;

#define l1e_get_mfn(l1e) ((mfn_t)((l1e).l1))
#define l1e_get_flags(l1e) ((unsigned int)((l1e).l1))
#define l1e_get_intpte(l1e) ((unsigned long)((l1e).l1))
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_PSE (1UL << 7)
#define _PAGE_PAT (1UL << 12)
#define _PAGE_PSE_PAT (_PAGE_PSE | _PAGE_PAT)
#define PAGE_SHIFT 12
#define L1_PAGETABLE_ENTRIES 512

typedef union {
    unsigned long l1;
} l1_pgentry_t;

#define cf_check

static inline bool p2m_is_valid(p2m_type_t t) { return false; }
static inline bool p2m_is_grant(p2m_type_t t) { return false; }
static inline p2m_type_t p2m_flags_to_type(unsigned int flags) { return 0; }

static void sh_remove_all_shadows_and_parents(struct domain *d, mfn_t mfn) {}
static bool sh_remove_all_mappings(struct domain *d, mfn_t mfn, gfn_t gfn) { return false; }
static void *map_domain_page(mfn_t mfn) { return NULL; }
static void unmap_domain_page(void *ptr) {}
static void guest_flush_tlb_mask(struct domain *d, unsigned long mask) {}

#define BUILD_BUG_ON(cond) ((void)0)
#define unlikely(cond) (cond)
#define ASSERT(cond) ((void)0)