#include <stdint.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define PAGE_MASK (~0UL << PAGE_SHIFT)
#define unlikely(x) (x)
#define GNTST_okay 0
#define GNTST_general_error 1
#define XENLOG_WARNING 0
#define P2M_ALLOC 0
#define PGT_type_mask 0
#define PGT_l1_page_table 0
#define l1 1

typedef uint64_t l1_pgentry_t;
typedef unsigned long mfn_t;

struct vcpu {
    struct domain *domain;
};

struct domain;

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

static inline mfn_t _mfn(unsigned long mfn) { return mfn; }
static inline void adjust_guest_l1e(l1_pgentry_t l1e, struct domain *d) {}
static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, void *null, int p2m) { return NULL; }
static inline unsigned long page_to_mfn(struct page_info *page) { return 0; }
static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline int page_lock(struct page_info *page) { return 1; }
static inline void page_unlock(struct page_info *page) {}
static inline int UPDATE_ENTRY(int level, l1_pgentry_t *ptep, l1_pgentry_t old, l1_pgentry_t new, unsigned long mfn, struct vcpu *v, int preserve_ad) { return 1; }
static inline void put_page_from_l1e(l1_pgentry_t l1e, struct domain *d) {}
static inline void unmap_domain_page(void *va) {}
static inline void put_page(struct page_info *page) {}
static inline void gdprintk(int level, const char *fmt, ...) {}