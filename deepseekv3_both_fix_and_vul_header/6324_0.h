#include <stddef.h>
#include <errno.h>

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef unsigned long p2m_type_t;

#define INVALID_MFN ((mfn_t)-1)
#define XENMAPSPACE_grant_table 0
#define XENMAPSPACE_shared_info 1
#define XENMAPSPACE_gmfn_foreign 2
#define XENMAPSPACE_dev_mmio 3

#define XSM_TARGET 0
#define P2M_ALLOC 0
#define p2m_ram_rw 0
#define p2m_map_foreign_rw 0
#define p2m_map_foreign_ro 0

struct domain {
    void *shared_info;
};

struct page_info;

union add_to_physmap_extra {
    unsigned int foreign_domid;
};

int gnttab_map_frame(struct domain *d, unsigned long idx, gfn_t gfn, mfn_t *mfn);
struct domain *get_pg_owner(unsigned int domid);
void put_pg_owner(struct domain *d);
int xsm_map_gmfn_foreign(int xsm_target, struct domain *d, struct domain *od);
struct page_info *get_page_from_gfn(struct domain *d, unsigned long idx, p2m_type_t *p2mt, int p2m_alloc);
int p2m_is_ram(p2m_type_t t);
mfn_t page_to_mfn(struct page_info *page);
void put_page(struct page_info *page);
mfn_t virt_to_mfn(void *virt);
int guest_physmap_add_entry(struct domain *d, gfn_t gfn, mfn_t mfn, unsigned int page_order, p2m_type_t t);
int map_dev_mmio_region(struct domain *d, gfn_t gfn, unsigned int nr_mfns, mfn_t mfn);