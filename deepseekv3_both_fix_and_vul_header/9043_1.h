#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_ORDER 20
#define PRI_xen_pfn "lx"
#define MEMF_populate_on_demand (1 << 0)
#define XENLOG_INFO 0

#define unlikely(x) (x)

struct memop_args {
    struct domain *domain;
    unsigned int nr_done;
    unsigned int nr_extents;
    unsigned int extent_order;
    unsigned int memflags;
    int preempted;
    void *extent_list;
};

struct domain {
    int domain_id;
    struct domain *domain;
};

struct page_info;

typedef uint64_t xen_pfn_t;

extern struct domain *current;
extern int opt_tmem;

int guest_handle_subrange_okay(void *handle, unsigned int start, unsigned int end);
int hypercall_preempt_check(void);
int __copy_from_guest_offset(xen_pfn_t *dst, void *src, unsigned int offset, unsigned int count);
int __copy_to_guest_offset(void *dst, unsigned int offset, xen_pfn_t *src, unsigned int count);
int guest_physmap_mark_populate_on_demand(struct domain *d, xen_pfn_t gpfn, unsigned int order);
int is_domain_direct_mapped(struct domain *d);
int mfn_valid(xen_pfn_t mfn);
struct page_info *mfn_to_page(xen_pfn_t mfn);
int get_page(struct page_info *page, struct domain *d);
void put_page(struct page_info *page);
struct page_info *alloc_domheap_pages(struct domain *d, unsigned int order, unsigned int memflags);
void guest_physmap_add_page(struct domain *d, xen_pfn_t gpfn, xen_pfn_t mfn, unsigned int order);
int paging_mode_translate(struct domain *d);
void set_gpfn_from_mfn(xen_pfn_t mfn, xen_pfn_t gpfn);
void gdprintk(int level, const char *fmt, ...);
int multipage_allocation_permitted(struct domain *d, unsigned int order);
xen_pfn_t page_to_mfn(struct page_info *page);