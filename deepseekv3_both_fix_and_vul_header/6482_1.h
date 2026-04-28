#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

#define INVALID_MFN ((mfn_t)-1)
#define INVALID_M2P_ENTRY ((pfn_t)-1)

#define BUG_ON(condition) do { if (condition) abort(); } while (0)
#define ASSERT(condition) do { if (!(condition)) abort(); } while (0)
#define ASSERT_UNREACHABLE() abort()

#define unlikely(x) (x)
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef enum {
    p2m_invalid,
    p2m_populate_on_demand,
    p2m_ram_rw,
    p2m_ram_ro,
    p2m_max_real_type
} p2m_type_t;

typedef enum {
    p2m_access_n,
    p2m_access_r,
    p2m_access_w,
    p2m_access_rw,
    p2m_access_x,
    p2m_access_rx,
    p2m_access_wx,
    p2m_access_rwx,
    p2m_access_rx2rw,
    p2m_access_n2rwx,
    p2m_access_default
} p2m_access_t;

struct domain {
    bool is_dying;
};

struct p2m_domain {
    struct {
        long entry_count;
        long count;
    } pod;
    p2m_access_t default_access;
    mfn_t (*get_entry)(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *t, p2m_access_t *a, 
                       int page_order, unsigned int *cur_order, mfn_t *mfn);
    int (*set_entry)(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, unsigned int order,
                     p2m_type_t t, p2m_access_t a);
};

struct page_info {
    unsigned long mfn;
};

#define SUPERPAGE_ORDER 9
#define SUPERPAGE_PAGES (1UL << SUPERPAGE_ORDER)

typedef int bool_t;

static inline gfn_t gfn_add(gfn_t gfn, unsigned long offset) { return gfn + offset; }
static inline unsigned long gfn_x(gfn_t gfn) { return gfn; }
static inline gfn_t _gfn(unsigned long gfn) { return gfn; }
static inline mfn_t mfn_x(mfn_t mfn) { return mfn; }
static inline bool mfn_valid(mfn_t mfn) { return mfn != INVALID_MFN; }
static inline struct page_info *mfn_to_page(mfn_t mfn) { return (struct page_info *)mfn; }
static inline void set_gpfn_from_mfn(mfn_t mfn, pfn_t pfn) {}

static inline bool p2m_is_ram(p2m_type_t t) { 
    return t == p2m_ram_rw || t == p2m_ram_ro; 
}

static inline void gfn_lock(struct p2m_domain *p2m, gfn_t gfn, unsigned int order) {}
static inline void gfn_unlock(struct p2m_domain *p2m, gfn_t gfn, unsigned int order) {}
static inline void pod_lock(struct p2m_domain *p2m) {}
static inline void pod_unlock(struct p2m_domain *p2m) {}
static inline struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return NULL; }
static inline void p2m_tlb_flush_sync(struct p2m_domain *p2m) {}
static inline void p2m_pod_cache_add(struct p2m_domain *p2m, struct page_info *page, unsigned int order) {}
static inline void p2m_pod_set_cache_target(struct p2m_domain *p2m, long entry_count, int preempt) {}
static inline bool p2m_pod_zero_check_superpage(struct p2m_domain *p2m, gfn_t gfn) { return false; }
static inline void domain_crash(struct domain *d) {}
static inline int p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, unsigned int order,
                               p2m_type_t t, p2m_access_t a) { return 0; }