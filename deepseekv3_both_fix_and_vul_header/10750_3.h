#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

typedef uint64_t mfn_t;
typedef uint64_t p2m_type_t;

#define CONFIG_X86
#define unlikely(x) (x)
#define _PGC_allocated 0
#define _PGT_pinned 0
#define PAGE_ORDER_4K 0
#define XENLOG_INFO 0
#define p2m_ram_paging_out 0
#define p2m_mmio_direct 0
#define p2m_is_paging(x) 0
#define p2m_is_shared(x) 0
#define mfn_valid(x) 1
#define mfn_x(x) (x)
#define _gfn(x) (x)
#define EINVAL 1
#define ENXIO 2

#define ASSERT(x) assert(x)

static inline mfn_t get_gfn_query(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }
static inline int guest_physmap_remove_page(struct domain *d, unsigned long gfn, mfn_t mfn, unsigned int page_order) { return 0; }
static inline void put_gfn(struct domain *d, unsigned long gmfn) {}
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline int test_and_clear_bit(int nr, volatile void *addr) { return 0; }
static inline void put_page(struct page_info *page) {}
static inline void p2m_mem_paging_drop_page(struct domain *d, unsigned long gmfn, p2m_type_t p2mt) {}
static inline int clear_mmio_p2m_entry(struct domain *d, unsigned long gmfn, mfn_t mfn, unsigned int page_order) { return 0; }
static inline void gdprintk(int level, const char *fmt, ...) {}
static inline int mem_sharing_unshare_page(struct domain *d, unsigned long gmfn, int readonly) { return 0; }
static inline void mem_sharing_notify_enomem(struct domain *d, unsigned long gmfn, int readonly) {}
static inline mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gmfn, p2m_type_t *p2mt) { return 0; }
static inline int get_page(struct page_info *page, struct domain *d) { return 1; }
static inline void put_page_and_type(struct page_info *page) {}
static inline int is_domain_direct_mapped(struct domain *d) { return 0; }