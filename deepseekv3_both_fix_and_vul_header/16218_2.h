#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define unlikely(x) (x)
#define _gfn(x) (x)

struct domain;
struct xen_add_to_physmap_batch {
    unsigned int size;
    unsigned int space;
    union add_to_physmap_extra {
        unsigned int res0;
        unsigned int foreign_domid;
    } u;
    void *idxs;
    void *gpfns;
    void *errs;
};

typedef uint64_t xen_ulong_t;
typedef uint64_t xen_pfn_t;

#define XENMAPSPACE_dev_mmio 0
#define XENMAPSPACE_gmfn_foreign 1

int xenmem_add_to_physmap_one(struct domain *d, unsigned int space, union add_to_physmap_extra extra, xen_ulong_t idx, xen_pfn_t gpfn);
int guest_handle_subrange_okay(void *h, unsigned int s, unsigned int e);
int __copy_from_guest_offset(void *dst, void *src, unsigned int off, unsigned int len);
int __copy_to_guest_offset(void *dst, unsigned int off, void *src, unsigned int len);
int hypercall_preempt_check(void);