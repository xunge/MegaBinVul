#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct spinlock {
    int lock;
} spinlock_t;

struct page_info;

struct page_list_head {
    struct page_info *head;
    struct page_info *tail;
};

struct arch_domain {
    struct page_list_head relmem_list;
};

struct domain {
    struct arch_domain arch;
    bool is_dying;
    spinlock_t page_alloc_lock;
    struct page_list_head page_list;
    struct page_list_head relmem_list;
};

struct page_info {
    union {
        struct {
            uint32_t type_info;
        } inuse;
    } u;
    unsigned long count_info;
};

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;

#define mfn_x(mfn) (mfn)
#define gfn_x(gfn) (gfn)
#define INVALID_GFN ((gfn_t)-1)
#define DEFAULT_DOMAIN_ADDRESS_WIDTH 52
#define SHARED_M2P(gfn) (0)
#define PGT_type_mask (0x7)
#define PGT_writable_page (0x1)
#define PGC_state (0x1)
#define PGC_broken (0x2)
#define PAGE_ORDER_4K (0)
#define IOMMUF_readable (1 << 0)
#define IOMMUF_writable (1 << 1)
#define IOMMU_FLUSHF_added (1 << 0)
#define IOMMU_FLUSHF_modified (1 << 1)
#define ESRCH (3)
#define ERESTART (512)

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline bool unlikely(bool x) { return x; }
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline mfn_t page_to_mfn(struct page_info *page) { return 0; }
static inline gfn_t mfn_to_gmfn(struct domain *d, unsigned long mfn) { return 0; }
static inline int iommu_map(struct domain *d, unsigned long dfn, unsigned long mfn, unsigned int order, unsigned int flags, unsigned int *flush_flags) { return 0; }
static inline int iommu_iotlb_flush_all(struct domain *d, unsigned int flags) { return 0; }
static inline void iommu_teardown(struct domain *d) {}
static inline bool page_list_empty(const struct page_list_head *list) { return true; }
static inline struct page_info *page_list_remove_head(struct page_list_head *list) { return NULL; }
static inline void page_list_add(struct page_info *page, struct page_list_head *list) {}
static inline void page_list_add_tail(struct page_info *page, struct page_list_head *list) {}
static inline void page_list_move(struct page_list_head *dst, struct page_list_head *src) {}
static inline struct page_info *page_list_first(const struct page_list_head *list) { return NULL; }
static inline void page_list_del(struct page_info *page, struct page_list_head *list) {}
static inline bool hypercall_preempt_check(void) { return false; }
#define ASSERT(x) ((void)0)
#define BUG_ON(x) ((void)0)
#define _dfn(x) (x)
#define _mfn(x) (x)