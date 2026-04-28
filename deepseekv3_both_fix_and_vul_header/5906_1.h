#include <stdint.h>
#include <stddef.h>

typedef uint16_t domid_t;
typedef unsigned long xen_pfn_t;

struct domain;
struct page_info;
struct grant_table;

enum p2m_type {
    p2m_ram_rw,
    p2m_map_foreign
};
typedef enum p2m_type p2m_type_t;

#define XENMAPSPACE_grant_table      0
#define XENMAPSPACE_shared_info      1
#define XENMAPSPACE_gmfn_foreign     2

#define XENMAPIDX_grant_table_status (1U<<31)

#define XSM_TARGET 0

#define EINVAL     22
#define ESRCH      3
#define ENOSYS     38

#define P2M_ALLOC  0

#define ASSERT(x) ((void)0)

struct domain {
    struct grant_table *grant_table;
    struct {
        xen_pfn_t *grant_table_gpfn;
    } arch;
    void *shared_info;
};

struct grant_table {
    int gt_version;
    void **status;
    void **shared_raw;
    int lock;
};

static inline unsigned long virt_to_mfn(void *v) { return 0; }
static inline unsigned long page_to_mfn(struct page_info *p) { return 0; }
static inline unsigned long pfn_to_paddr(unsigned long pfn) { return 0; }

static int nr_status_frames(struct grant_table *gt) { return 0; }
static int nr_grant_frames(struct grant_table *gt) { return 0; }
static int max_grant_frames = 0;
static void gnttab_grow_table(struct domain *d, int n) {}

static void write_lock(int *lock) {}
static void write_unlock(int *lock) {}

static struct domain *rcu_lock_domain_by_any_id(domid_t id) { return NULL; }
static void rcu_unlock_domain(struct domain *d) {}

static int xsm_map_gmfn_foreign(int xsm, struct domain *d1, struct domain *d2) { return 0; }

static struct page_info *get_page_from_gfn(struct domain *d, unsigned long idx, p2m_type_t *t, int alloc) { return NULL; }
static void put_page(struct page_info *p) {}
static int p2m_is_ram(p2m_type_t t) { return 0; }
static void dump_p2m_lookup(struct domain *d, unsigned long addr) {}

static int guest_physmap_add_entry(struct domain *d, xen_pfn_t gpfn, unsigned long mfn, int order, p2m_type_t t) { return 0; }