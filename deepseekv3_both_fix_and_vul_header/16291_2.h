#include <stddef.h>
#include <errno.h>

#define ASSERT(cond) ((void)0)
#define DOMID_INVALID (-1)
#define unlikely(x) (x)
#define _gfn(x) (x)
#define _dfn(x) (x)
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define this_cpu(var) (var)

enum {
    XENMAPSPACE_gmfn_foreign,
    XENMAPSPACE_gmfn_range,
    XENMAPSPACE_gmfn
};

#define IOMMU_FLUSHF_modified (1 << 0)
#define IOMMU_FLUSHF_added (1 << 1)

struct domain;
struct page_info;

struct xen_add_to_physmap {
    unsigned int space;
    unsigned int idx;
    unsigned long gpfn;
    unsigned int size;
};

union add_to_physmap_extra {
    int foreign_domid;
    struct page_info **ppage;
};

int iommu_dont_flush_iotlb;

extern int paging_mode_translate(struct domain *d);
extern int xenmem_add_to_physmap_one(struct domain *d, int space, union add_to_physmap_extra extra, unsigned int idx, unsigned long gfn);
extern int is_iommu_enabled(struct domain *d);
extern int iommu_iotlb_flush(struct domain *d, unsigned long dfn, unsigned int count, unsigned int flags);
extern void put_page(struct page_info *page);
extern int hypercall_preempt_check(void);