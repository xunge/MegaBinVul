#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;
typedef uint64_t gfn_t;
typedef uint64_t mfn_t;
typedef unsigned int p2m_type_t;
typedef unsigned int p2m_access_t;
typedef unsigned int p2m_order_t;

#define PAGE_ORDER_4K 0
#define PAGE_SIZE 4096

struct domain {
    int domain_id;
};

struct p2m_domain {
    struct domain *domain;
    p2m_access_t default_access;
    struct {
        int entry_count;
    } pod;
    mfn_t (*get_entry)(struct p2m_domain *, gfn_t, p2m_type_t *, p2m_access_t *, int, void *, void *);
};

struct page_info {
    unsigned long count_info;
};

#define PGC_allocated (1UL << 0)
#define PGC_page_table (1UL << 1)
#define PGC_xen_heap (1UL << 2)
#define PGC_count_mask (0xFFFFUL)
#define INVALID_MFN (~0UL)
#define p2m_populate_on_demand 0
#define TRC_MEM_POD_ZERO_RECLAIM 0
#define gfn_x(x) (x)
#define mfn_x(x) (x)

static int paging_mode_shadow(struct domain *d) { return 0; }
static int p2m_is_ram(p2m_type_t t) { return 0; }
static struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static unsigned long *map_domain_page(mfn_t mfn) { return NULL; }
static void unmap_domain_page(unsigned long *addr) {}
static int p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, p2m_order_t order, p2m_type_t type, p2m_access_t a) { return 0; }
static void p2m_tlb_flush_sync(struct p2m_domain *p2m) {}
static void p2m_pod_cache_add(struct p2m_domain *p2m, struct page_info *pg, p2m_order_t order) {}
static void domain_crash(struct domain *d) {}
static void __trace_var(int event, int cpu, size_t size, void *data) {}
static int tb_init_done = 0;
#define ASSERT_UNREACHABLE()