#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

struct domain {
    unsigned int domain_id;
};

struct page_info;

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;

#define _gfn(gfn) ((gfn_t)(gfn))

#ifdef CONFIG_X86
typedef enum {
    p2m_invalid,
    p2m_mmio_dm,
    p2m_ram_paging_out,
    p2m_mmio_direct
} p2m_type_t;

#define p2m_is_paging(p2mt) (0)
#define p2m_is_shared(p2mt) (0)

mfn_t get_gfn_query(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt);
void put_gfn(struct domain *d, unsigned long gmfn);
mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt);
int clear_mmio_p2m_entry(struct domain *d, unsigned long gmfn, mfn_t mfn, int order);
int mem_sharing_unshare_page(struct domain *d, unsigned long gmfn);
void mem_sharing_notify_enomem(struct domain *d, unsigned long gmfn, bool shared);
void p2m_mem_paging_drop_page(struct domain *d, gfn_t gfn, p2m_type_t p2mt);
#else
mfn_t gfn_to_mfn(struct domain *d, gfn_t gfn);
#endif

#define mfn_valid(mfn) (1)
#define mfn_to_page(mfn) ((struct page_info *)NULL)
#define get_page(page, d) (1)
#define put_page(page)
#define put_page_alloc_ref(page)
#define PAGE_ORDER_4K (0)
#define guest_physmap_remove_page(d, gfn, mfn, order) (0)
#define is_domain_direct_mapped(d) (0)

#define unlikely(x) (x)
#define ASSERT(x)
#define __maybe_unused

#define XENLOG_INFO (0)
#define gdprintk(level, fmt, ...)

bool iommu_dont_flush_iotlb;
#define this_cpu(var) (var)