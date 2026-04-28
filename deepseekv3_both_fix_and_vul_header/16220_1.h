#include <stddef.h>
#include <errno.h>
#include <assert.h>

struct domain {
    void *shared_info;
};

struct page_info;

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

typedef enum {
    p2m_ram_rw,
    p2m_map_foreign_rw,
    p2m_map_foreign_ro,
    P2M_ALLOC
} p2m_type_t;

#define XSM_TARGET 0
#define INVALID_MFN ((mfn_t){0})
#define _mfn(x) ((mfn_t){x})
#define XENMAPSPACE_grant_table 0
#define XENMAPSPACE_shared_info 1
#define XENMAPSPACE_gmfn_foreign 2
#define XENMAPSPACE_dev_mmio 3

#define EINVAL 22
#define ESRCH 3
#define ENOSYS 38
#define EOPNOTSUPP 95

union add_to_physmap_extra {
    unsigned long foreign_domid;
};

union xen_add_to_physmap_batch_extra {
    unsigned long foreign_domid;
    unsigned long res0;
};

static inline int p2m_is_ram(p2m_type_t t) { return 1; }
static inline mfn_t virt_to_mfn(void *v) { return (mfn_t){0}; }
static inline mfn_t page_to_mfn(struct page_info *p) { return (mfn_t){0}; }

int gnttab_map_frame(struct domain *d, unsigned long idx, gfn_t gfn, mfn_t *mfn);
int xsm_map_gmfn_foreign(int xsm_target, struct domain *d, struct domain *od);
int guest_physmap_add_entry(struct domain *d, gfn_t gfn, mfn_t mfn, int flags, p2m_type_t t);
int map_dev_mmio_region(struct domain *d, gfn_t gfn, int count, mfn_t mfn);
struct domain *get_pg_owner(unsigned long domid);
void put_pg_owner(struct domain *d);
struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, p2m_type_t *t, p2m_type_t alloc);
void put_page(struct page_info *p);