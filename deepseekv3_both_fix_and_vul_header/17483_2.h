#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define ASSERT(cond) ((void)0)
#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))
#define unlikely(x) (x)
#define likely(x) (x)
#define cmpxchg(ptr, old, new) __sync_val_compare_and_swap(ptr, old, new)
#define PRI_mfn "lu"
#define PRI_pfn "lu"
#define PRtype_info "lu"
#define mfn_x(mfn) ((mfn).val)
#define page_to_mfn(page) ((mfn_t){0})
#define get_gpfn_from_mfn(mfn) (0)
#define PGT_type_mask 0xF
#define PGT_pae_xen_l2 (1 << 4)
#define PGT_count_mask (0xFF << 8)
#define PGT_validated (1 << 16)
#define PGT_partial (1 << 17)
#define PGT_non_coherent (1 << 18)
#define PGT_l1_page_table 1
#define PGT_l2_page_table 2
#define PGT_l3_page_table 3
#define PGT_l4_page_table 4
#define PGT_writable_page 5
#define PGT_shared_page 6
#define PGT_root_page_table 7
#define EINVAL 22
#define EINTR 4
#define XENLOG_WARNING 1
#define FLUSH_TLB 1
#define FLUSH_NO_ASSIST 2
#define PAGE_ORDER_4K 0
#define PAGE_SIZE 4096
#define IOMMUF_readable (1 << 0)
#define IOMMUF_writable (1 << 1)
#define need_flush_tlb_flush 0

typedef struct {
    unsigned long val;
} mfn_t;

typedef struct {
    unsigned long val;
} pfn_t;

typedef struct {
    unsigned long val;
} dfn_t;

#define _dfn(x) ((dfn_t){x})

typedef struct {
    unsigned long bits[1];
} cpumask_t;

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    unsigned long tlbflush_timestamp;
    unsigned int nr_validated_ptes;
    unsigned int partial_flags;
    unsigned int linear_pt_count;
};

struct domain {
    cpumask_t *dirty_cpumask;
};

extern cpumask_t scratch_cpumask;
#define this_cpu(var) (&var)

static inline void cpu_relax(void) {}
static inline bool in_irq(void) { return false; }
static inline bool hypercall_preempt_check(void) { return false; }
static inline void gdprintk(int level, const char *fmt, ...) {}
static inline void perfc_incr(int counter) {}
static inline void flush_mask(cpumask_t *mask, int flags) {}
static inline void tlbflush_filter(cpumask_t *mask, unsigned long timestamp) {}
static inline void cache_flush(void *addr, size_t size) {}
static inline void *__map_domain_page(struct page_info *page) { return NULL; }
static inline void unmap_domain_page(void *addr) {}
static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline bool shadow_mode_enabled(struct domain *d) { return false; }
static inline void shadow_prepare_page_type_change(struct domain *d, struct page_info *page, unsigned long type) {}
static inline bool need_iommu_pt_sync(struct domain *d) { return false; }
static inline bool is_pv_domain(struct domain *d) { return false; }
static inline int iommu_legacy_unmap(struct domain *d, dfn_t dfn, unsigned long order) { return 0; }
static inline int iommu_legacy_map(struct domain *d, dfn_t dfn, mfn_t mfn, unsigned long order, unsigned int flags) { return 0; }
static inline void _put_page_type(struct page_info *page, int flags, int *preempted) {}
static inline void put_page(struct page_info *page) {}
static inline int validate_page(struct page_info *page, unsigned long type, bool preemptible) { return 0; }
static inline void BUG_ON(int condition) {}
static inline void cpumask_copy(cpumask_t *dst, cpumask_t *src) {}
static inline bool cpumask_empty(cpumask_t *mask) { return true; }