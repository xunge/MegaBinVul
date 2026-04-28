#include <stdint.h>
#include <stddef.h>

#define likely(x) (x)
#define unlikely(x) (x)
#define ASSERT(x) ((void)0)
#define XENLOG_ERR 0
#define PGC_count_mask 0xFFF

struct page_info {
    uint32_t count_info;
};

struct paging_info {
    struct {
        unsigned long total_pages;
        unsigned long p2m_pages;
    } hap;
    int p2m_alloc_failed;
};

struct arch_domain {
    struct paging_info paging;
};

struct domain {
    int domain_id;
    struct arch_domain arch;
};

static inline void paging_lock_recursive(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline struct page_info *hap_alloc(struct domain *d) { return NULL; }
static inline void *page_get_owner(struct page_info *pg) { return NULL; }
static inline void page_set_owner(struct page_info *pg, struct domain *d) {}
static inline void dprintk(int level, const char *fmt, ...) {}