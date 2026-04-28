#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define CONFIG_X86
#define unlikely(x) (x)
#define likely(x) (x)
#define ASSERT(x) ((void)0)
#define _PGC_allocated 0
#define _PGT_pinned 0
#define PAGE_ORDER_4K 0
#define ENOENT 2
#define EINVAL 22
#define ENXIO 6
#define XENLOG_INFO 0
#define __maybe_unused __attribute__((unused))

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

typedef unsigned long p2m_type_t;
#define p2m_invalid 0
#define p2m_mmio_dm 0
#define p2m_ram_paging_out 0
#define p2m_mmio_direct 0

typedef struct {
    unsigned long mfn;
} mfn_t;

#define mfn_x(mfn) ((mfn).mfn)
#define mfn_valid(mfn) (1)
#define p2m_is_paging(p2mt) (0)
#define p2m_is_shared(p2mt) (0)

static inline int test_and_clear_bit(int nr, volatile unsigned long *addr) { return 0; }

static inline mfn_t get_gfn_query(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return (mfn_t){0}; }
static inline mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return (mfn_t){0}; }
static inline void put_gfn(struct domain *d, unsigned long gmfn) {}
static inline int guest_physmap_remove_page(struct domain *d, unsigned long gfn, mfn_t mfn, unsigned int page_order) { return 0; }
static inline int clear_mmio_p2m_entry(struct domain *d, unsigned long gmfn, mfn_t mfn, unsigned int page_order) { return 0; }
static inline int mem_sharing_unshare_page(struct domain *d, unsigned long gmfn, int flags) { return 0; }
static inline int mem_sharing_notify_enomem(struct domain *d, unsigned long gmfn, int flags) { return 0; }
static inline void p2m_mem_paging_drop_page(struct domain *d, unsigned long gmfn, p2m_type_t p2mt) {}
static inline bool get_page(struct page_info *page, struct domain *d) { return true; }
static inline void put_page(struct page_info *page) {}
static inline void put_page_and_type(struct page_info *page) {}
static inline bool is_domain_direct_mapped(struct domain *d) { return false; }
static inline void gdprintk(int level, const char *fmt, ...) {}

#define _gfn(gmfn) (gmfn)
#define mfn_to_page(mfn) ((struct page_info *)NULL)