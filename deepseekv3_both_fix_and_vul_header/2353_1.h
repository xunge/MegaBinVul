#include <stddef.h>
#include <stdint.h>

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;

#define INVALID_MFN ((mfn_t){0})
#define _mfn(x) ((mfn_t){x})
#define XENMAPSPACE_grant_table 0
#define XENMAPSPACE_shared_info 1
#define XENMAPSPACE_gmfn_foreign 2
#define XENMAPSPACE_dev_mmio 3
#define XENMAPIDX_grant_table_status (1U<<31)
#define EINVAL 22
#define ESRCH 3
#define EOPNOTSUPP 95
#define ENOSYS 38
#define P2M_ALLOC 0
#define XSM_TARGET 0

enum p2m_type {
    p2m_ram_rw,
    p2m_map_foreign
};
typedef enum p2m_type p2m_type_t;

union xen_add_to_physmap_batch_extra {
    uint16_t foreign_domid;
    uint64_t res0;
};

struct grant_table {
    unsigned int gt_version;
    void **shared_raw;
    void **status;
};

struct arch_domain {
    gfn_t *grant_table_gfn;
};

struct domain {
    struct grant_table *grant_table;
    struct shared_info *shared_info;
    struct arch_domain arch;
};

struct page_info {
    unsigned long mfn;
};

extern unsigned int max_grant_frames;

static inline mfn_t virt_to_mfn(void *v) { return (mfn_t)(uintptr_t)v; }
static inline unsigned long page_to_mfn(struct page_info *page) { return page->mfn; }
static inline unsigned int nr_status_frames(struct grant_table *gt) { return 0; }
static inline unsigned int nr_grant_frames(struct grant_table *gt) { return 0; }
static inline void grant_write_lock(struct grant_table *gt) {}
static inline void grant_write_unlock(struct grant_table *gt) {}
static inline void gnttab_grow_table(struct domain *d, unsigned int count) {}
static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, p2m_type_t *t, unsigned int flags) { return NULL; }
static inline void put_page(struct page_info *page) {}
static inline int p2m_is_ram(p2m_type_t t) { return 1; }
static inline struct domain *rcu_lock_domain_by_any_id(uint16_t domid) { return NULL; }
static inline void rcu_unlock_domain(struct domain *d) {}
static inline int xsm_map_gmfn_foreign(int xsm, struct domain *d, struct domain *od) { return 0; }
static inline int guest_physmap_add_entry(struct domain *d, gfn_t gfn, mfn_t mfn, unsigned int page_order, p2m_type_t t) { return 0; }
static inline int map_dev_mmio_region(struct domain *d, gfn_t gfn, unsigned int count, mfn_t mfn) { return 0; }
#define ASSERT(x) (void)(x)