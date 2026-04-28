#include <stdbool.h>
#include <stdint.h>

typedef unsigned long mfn_t;
typedef unsigned long pfn_t;
typedef unsigned long gfn_t;
typedef unsigned int p2m_type_t;

struct domain {
    unsigned int domain_id;
};

struct page_info {
    unsigned long count_info;
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

#define mfn_x(mfn) (mfn)
#define _gfn(gfn) ((gfn_t)(gfn))
#define mfn_valid(mfn) (1)
#define PAGE_ORDER_4K (0)
#define _PGC_allocated (0)
#define _PGT_pinned (0)
#define p2m_is_paging(p2mt) (0)
#define p2m_is_shared(p2mt) (0)
#define p2m_ram_paging_out (0)
#define p2m_mmio_direct (0)
#define unlikely(x) (x)
#define ASSERT(x) (void)(x)
#define gdprintk(level, fmt, ...) (void)(0)
#define XENLOG_INFO (0)
#define ENXIO (5)
#define EINVAL (22)

static inline struct page_info *mfn_to_page(mfn_t mfn) { return (struct page_info *)0; }
static inline bool test_and_clear_bit(int nr, volatile unsigned long *addr) { return false; }

static inline mfn_t get_gfn_query(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }
static inline void put_gfn(struct domain *d, unsigned long gmfn) {}
static inline void guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn, unsigned int page_order) {}
static inline void p2m_mem_paging_drop_page(struct domain *d, unsigned long gmfn, p2m_type_t p2mt) {}
static inline int clear_mmio_p2m_entry(struct domain *d, unsigned long gmfn, mfn_t mfn, unsigned int page_order) { return 0; }
static inline mfn_t gfn_to_mfn(struct domain *d, gfn_t gfn) { return 0; }
static inline bool get_page(struct page_info *page, struct domain *d) { return true; }
static inline void put_page(struct page_info *page) {}
static inline void put_page_and_type(struct page_info *page) {}
static inline bool is_domain_direct_mapped(struct domain *d) { return false; }
static inline int mem_sharing_unshare_page(struct domain *d, unsigned long gmfn, unsigned int flags) { return 0; }
static inline int mem_sharing_notify_enomem(struct domain *d, unsigned long gmfn, unsigned int flags) { return 0; }
static inline mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }