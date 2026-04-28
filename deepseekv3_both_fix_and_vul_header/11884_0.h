#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

struct domain {
    unsigned int domain_id;
};

struct page_info {
    unsigned long count_info;
};

typedef unsigned long p2m_type_t;
typedef unsigned long mfn_t;

#define CONFIG_X86
#define unlikely(x) (x)
#define _PGC_allocated 0
#define p2m_invalid 0
#define p2m_mmio_dm 0
#define p2m_is_paging(x) 0
#define p2m_ram_paging_out 0
#define p2m_mmio_direct 0
#define p2m_is_shared(x) 0
#define PAGE_ORDER_4K 0
#define XENLOG_INFO 0
#define ENOENT 0
#define EINVAL 0
#define ENXIO 0

#define _gfn(x) (x)
#define mfn_valid(x) 1
#define mfn_to_page(x) NULL
#define test_and_clear_bit(x, y) 0
#define put_page(x) 
#define get_page(x, y) 1
#define gdprintk(x, y, ...) 
#define ASSERT(x) 
#define __maybe_unused

static mfn_t get_gfn_query(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }
static void put_gfn(struct domain *d, unsigned long gmfn) {}
static int guest_physmap_remove_page(struct domain *d, unsigned long gfn, mfn_t mfn, unsigned int page_order) { return 0; }
static void p2m_mem_paging_drop_page(struct domain *d, unsigned long gmfn, p2m_type_t p2mt) {}
static int clear_mmio_p2m_entry(struct domain *d, unsigned long gmfn, mfn_t mfn, unsigned int page_order) { return 0; }
static mfn_t gfn_to_mfn(struct domain *d, unsigned long gfn) { return 0; }
static int mem_sharing_unshare_page(struct domain *d, unsigned long gmfn, int flags) { return 0; }
static void mem_sharing_notify_enomem(struct domain *d, unsigned long gmfn, bool shared) {}
static mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }
static bool is_domain_direct_mapped(struct domain *d) { return false; }