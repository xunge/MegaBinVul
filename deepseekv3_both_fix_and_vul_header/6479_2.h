#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct { uint64_t x; } gfn_t;
typedef struct { uint64_t x; } mfn_t;
typedef uint64_t u64;

#define gfn_x(gfn) ((gfn).x)
#define mfn_x(mfn) ((mfn).x)
#define _gfn(x) ((gfn_t) { (x) })
#define gfn_add(gfn, offset) _gfn(gfn_x(gfn) + (offset))
#define gfn_max(a, b) ((gfn_x(a) > gfn_x(b)) ? (a) : (b))
#define mfn_add(mfn, offset) ((mfn_t) { mfn_x(mfn) + (offset) })
#define PAGE_ORDER_4K 0
#define PAGE_ORDER_2M 9
#define PAGE_ORDER_1G 18
#define PRIu32 "u"

#define INVALID_MFN ((mfn_t) { ~0UL })
#define p2m_populate_on_demand 1
#define p2m_ram_rw 2

struct domain {
    bool is_dying;
    uint32_t domain_id;
    uint32_t tot_pages;
};

struct page_info;
#define page_to_mfn(p) ((mfn_t) { 0 })

struct p2m_domain {
    struct domain *domain;
    struct {
        long entry_count;
        long count;
        gfn_t max_guest;
    } pod;
    int default_access;
};

struct current {
    struct domain *domain;
};
extern struct current *current;

#define unlikely(x) (x)
#define BUG_ON(cond) do { if (cond) {} } while (0)
#define ASSERT(cond) do { if (!(cond)) {} } while (0)

#define TRC_MEM_POD_POPULATE 0
#define TRC_MEM_POD_SUPERPAGE_SPLINTER 0

static inline void pod_lock(struct p2m_domain *p2m) {}
static inline void pod_unlock(struct p2m_domain *p2m) {}
static inline void pod_eager_reclaim(struct p2m_domain *p2m) {}
static inline void p2m_pod_emergency_sweep(struct p2m_domain *p2m) {}
static inline struct page_info *p2m_pod_cache_get(struct p2m_domain *p2m, unsigned int order) { return NULL; }
static inline void p2m_pod_cache_add(struct p2m_domain *p2m, struct page_info *p, unsigned int order) {}
static inline void pod_eager_record(struct p2m_domain *p2m, gfn_t gfn, unsigned int order) {}
static inline bool gfn_locked_by_me(struct p2m_domain *p2m, gfn_t gfn) { return true; }
static inline bool p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, unsigned int order, int type, int access) { return false; }
static inline void set_gpfn_from_mfn(unsigned long mfn, unsigned long gfn) {}
static inline void paging_mark_dirty(struct domain *d, mfn_t mfn) {}
static inline void __trace_var(int id, int unused, size_t size, void *data) {}
static inline void domain_crash(struct domain *d) {}
static inline int printk(const char *fmt, ...) { return 0; }

extern bool tb_init_done;