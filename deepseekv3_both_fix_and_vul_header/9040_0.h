#include <stddef.h>
#include <stdint.h>

typedef unsigned long xen_pfn_t;

struct memop_args {
    struct domain *domain;
    unsigned int nr_extents;
    unsigned int nr_done;
    unsigned int extent_order;
    unsigned int memflags;
    int preempted;
    void *extent_list;
};

struct domain {
    int domain_id;
};

struct page_info {
};

struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

#define guest_handle_is_null(hnd) 0
#define guest_handle_subrange_okay(hnd, s, e) 1
#define unlikely(x) (x)
#define XENLOG_INFO 0
#define gdprintk(lvl, fmt, ...) 

static int multipage_allocation_permitted(struct domain *d, unsigned int order) { return 1; }
static struct page_info *alloc_domheap_pages(struct domain *d, unsigned int order, unsigned int flags) { return NULL; }
static xen_pfn_t page_to_mfn(struct page_info *page) { return 0; }
static int __copy_to_guest_offset(void *hnd, unsigned long off, xen_pfn_t *mfn, int cnt) { return 0; }
static int hypercall_preempt_check(void) { return 0; }