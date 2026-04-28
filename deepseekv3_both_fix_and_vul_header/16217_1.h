#include <stddef.h>
#include <errno.h>

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef int p2m_type_t;

struct domain {
    void *shared_info;
};

struct page_info;

#define INVALID_MFN ((mfn_t)-1)
#define XSM_TARGET 0
#define P2M_ALLOC 0
#define XENMAPSPACE_grant_table 0
#define XENMAPSPACE_shared_info 1
#define XENMAPSPACE_gmfn_foreign 2
#define XENMAPSPACE_dev_mmio 3

#define p2m_ram_rw 0
#define p2m_map_foreign_rw 0
#define p2m_map_foreign_ro 0

#define _mfn(x) ((mfn_t)(x))
#define ASSERT(x) ((void)0)

union add_to_physmap_extra {
    unsigned long foreign_domid;
};

union xen_add_to_physmap_batch_extra {
    unsigned long foreign_domid;
    unsigned long res0;
};

static inline mfn_t virt_to_mfn(void *virt) { return (mfn_t)virt; }
static inline mfn_t page_to_mfn(struct page_info *page) { return (mfn_t)page; }

static inline int gnttab_map_frame(struct domain *d, unsigned long idx, gfn_t gfn, mfn_t *mfn) { return 0; }
static inline int guest_physmap_add_entry(struct domain *d, gfn_t gfn, mfn_t mfn, unsigned int page_order, p2m_type_t t) { return 0; }
static inline int map_dev_mmio_region(struct domain *d, gfn_t gfn, unsigned int nr_mfns, mfn_t mfn) { return 0; }
static inline struct domain *get_pg_owner(unsigned long domid) { return NULL; }
static inline void put_pg_owner(struct domain *d) {}
static inline int xsm_map_gmfn_foreign(int xsm_target, struct domain *d, struct domain *od) { return 0; }
static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, p2m_type_t *p2mt, int p2m_alloc) { return NULL; }
static inline void put_page(struct page_info *page) {}
static inline int p2m_is_ram(p2m_type_t t) { return 1; }