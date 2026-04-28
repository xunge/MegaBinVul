#include <stdint.h>
#include <stddef.h>
#include <sys/param.h>

typedef struct {
    uint64_t x;
} gfn_t;

typedef struct {
    uint64_t x;
} mfn_t;

typedef unsigned long p2m_type_t;
typedef unsigned long p2m_access_t;

#define gfn_x(gfn) ((gfn).x)
#define mfn_x(mfn) ((mfn).x)
#define mfn_eq(a, b) ((a).x == (b).x)
#define mfn_add(mfn, n) ((mfn_t){ .x = (mfn).x + (n) })
#define INVALID_MFN ((mfn_t){ .x = ~0UL })

#define SUPERPAGE_ORDER 9
#define PAGE_ORDER_2M 9
#define SUPERPAGE_PAGES (1UL << SUPERPAGE_ORDER)
#define PAGE_SIZE 4096

struct page_info {
    unsigned long count_info;
};

struct domain {
    int domain_id;
};

struct p2m_domain {
    struct domain *domain;
    p2m_access_t default_access;
    struct {
        unsigned long entry_count;
    } pod;
    mfn_t (*get_entry)(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *type,
                       p2m_access_t *a, int access_required,
                       unsigned int *order, struct page_info **page);
    int (*set_entry)(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn,
                     unsigned int order, p2m_type_t type, p2m_access_t a);
};

#define PGC_allocated (1UL << 0)
#define PGC_page_table (1UL << 1)
#define PGC_xen_heap (1UL << 2)
#define PGC_count_mask (~(3UL << 30))

#define p2m_is_ram(type) ((type) == 0)
#define p2m_populate_on_demand 0

#define TRC_MEM_POD_ZERO_RECLAIM 0

typedef uint64_t u64;

static int pod_locked_by_me(struct p2m_domain *p2m) { return 1; }
static int superpage_aligned(unsigned long x) { return !(x & ((1UL << SUPERPAGE_ORDER) - 1)); }
static void gfn_lock(struct p2m_domain *p2m, gfn_t gfn, unsigned int order) {}
static void gfn_unlock(struct p2m_domain *p2m, gfn_t gfn, unsigned int order) {}
static void *map_domain_page(mfn_t mfn) { return NULL; }
static void unmap_domain_page(void *map) {}
static void p2m_tlb_flush_sync(struct p2m_domain *p2m) {}
static void p2m_pod_cache_add(struct p2m_domain *p2m, const struct page_info *page, unsigned int order) {}
static void domain_crash(struct domain *d) {}
static int paging_mode_shadow(struct domain *d) { return 0; }
static struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static void __trace_var(int event, int cycles, int size, void *data) {}
static gfn_t gfn_add(gfn_t gfn, unsigned long n) { return (gfn_t){ .x = gfn.x + n }; }
static int p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn,
                        unsigned int order, p2m_type_t type, p2m_access_t a) { return 0; }

extern int tb_init_done;
#define ASSERT(x) do { if (!(x)) { } } while (0)
#define ASSERT_UNREACHABLE() ASSERT(0)