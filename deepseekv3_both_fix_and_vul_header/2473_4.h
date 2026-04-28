#include <stdint.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define IS_ALIGNED(x, a) (((x) & ((a) - 1)) == 0)

#define GNTST_okay 0
#define GNTST_general_error 1
#define P2M_ALLOC 0
#define PGT_l1_page_table 0
#define PGT_type_mask 0
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define _PAGE_AVAIL (1UL << 2)
#define PAGE_CACHE_ATTRS 0

#define unlikely(x) (x)
#define ASSERT_UNREACHABLE() ((void)0)
#define XENLOG_WARNING 0
#define XENLOG_ERR 0
#define PRIpte "lx"
#define PRIx64 "lx"

typedef uint64_t l1_pgentry_t;
typedef struct domain domain;
typedef struct page_info page_info;
typedef struct vcpu vcpu;

struct domain {
    vcpu *vcpu[1];
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

static inline unsigned long mfn_x(unsigned long mfn) { return mfn; }
static inline unsigned long page_to_mfn(page_info *page) { return 0; }
static inline unsigned long _mfn(unsigned long mfn) { return mfn; }
static inline void *map_domain_page(unsigned long mfn) { return NULL; }
static inline void unmap_domain_page(void *va) { }
static inline void put_page(page_info *page) { }
static inline int page_lock(page_info *page) { return 1; }
static inline void page_unlock(page_info *page) { }
static inline page_info *get_page_from_gfn(domain *d, unsigned long gmfn, void *null, int p2m_alloc) { return NULL; }
static inline unsigned long l1e_get_pfn(l1_pgentry_t l1e) { return 0; }
static inline unsigned long l1e_get_flags(l1_pgentry_t l1e) { return 0; }
static inline unsigned long l1e_get_intpte(l1_pgentry_t l1e) { return 0; }
static inline l1_pgentry_t l1e_from_pfn(unsigned long pfn, unsigned long flags) { return 0; }
static inline l1_pgentry_t l1e_empty(void) { return 0; }
static inline int UPDATE_ENTRY(int level, l1_pgentry_t *ptep, l1_pgentry_t ol1e, l1_pgentry_t nl1e, unsigned long mfn, vcpu *v, int preserve_ad) { return 1; }
static inline void gdprintk(int level, const char *fmt, ...) { }

#define l1 1