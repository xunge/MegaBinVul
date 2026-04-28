#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define PRI_mfn "lx"
#define PRI_pfn "lx"
#define PRtype_info "lx"
#define EINVAL 22
#define EINTR 4
#define XENLOG_WARNING 1
#define PGT_type_mask 0x7f
#define PGT_pae_xen_l2 (1UL << 9)
#define PGT_count_mask (0xff << 10)
#define PGT_validated (1UL << 8)
#define PGT_partial (1UL << 7)
#define PGC_page_table (1UL << 4)
#define PGT_writable_page 1
#define PGT_shared_page 2
#define PGT_l1_page_table 3
#define PGT_l2_page_table 4
#define PGT_l3_page_table 5
#define PGT_l4_page_table 6
#define IOMMUF_readable 1
#define IOMMUF_writable 2
#define need_flush_tlb_flush 0

typedef struct {
    unsigned long mfn;
} mfn_t;

typedef struct {
    unsigned long gfn;
} gfn_t;

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    unsigned long count_info;
    unsigned long shadow_flags;
    unsigned long tlbflush_timestamp;
    unsigned int nr_validated_ptes;
    unsigned int partial_pte;
    unsigned int linear_pt_count;
};

typedef struct {
    unsigned long bits[1];
} cpumask_t;

struct domain {
    cpumask_t domain_dirty_cpumask;
};

static cpumask_t *scratch_cpumask;

static inline unsigned long mfn_x(mfn_t mfn) { return mfn.mfn; }
static inline unsigned long gfn_x(gfn_t gfn) { return gfn.gfn; }

static inline mfn_t page_to_mfn(struct page_info *page) { mfn_t m = {0}; return m; }
static inline struct domain *page_get_owner(struct page_info *page) { return NULL; }
static inline bool shadow_mode_enabled(struct domain *d) { return false; }
static inline bool is_pv_domain(struct domain *d) { return false; }
static inline bool need_iommu(struct domain *d) { return false; }
static inline unsigned long get_gpfn_from_mfn(unsigned long mfn) { return 0; }
static inline unsigned long mfn_to_gmfn(struct domain *d, unsigned long mfn) { return 0; }
static inline gfn_t _gfn(unsigned long gfn) { gfn_t g = {gfn}; return g; }

static inline void shadow_remove_all_shadows(struct domain *d, mfn_t mfn) {}
static inline void tlbflush_filter(cpumask_t *mask, unsigned long timestamp) {}
static inline void flush_tlb_mask(cpumask_t *mask) {}
static inline int iommu_unmap_page(struct domain *d, unsigned long gfn) { return 0; }
static inline int iommu_map_page(struct domain *d, unsigned long gfn, unsigned long mfn, unsigned int flags) { return 0; }
static inline int alloc_page_type(struct page_info *page, unsigned long type, int preemptible) { return 0; }
static inline void put_page(struct page_info *page) {}
static inline bool in_irq(void) { return false; }
static inline void cpu_relax(void) {}
static inline bool hypercall_preempt_check(void) { return false; }
static inline void perfc_incr(int counter) {}
static inline void gdprintk(int level, const char *fmt, ...) {}
static inline void ASSERT(bool condition) {}
static inline void BUG_ON(bool condition) {}
static inline void cpumask_copy(cpumask_t *dst, cpumask_t src) {}
static inline bool cpumask_empty(cpumask_t *mask) { return true; }
static inline cpumask_t *this_cpu(cpumask_t *var) { return var; }
static inline unsigned long cmpxchg(volatile unsigned long *ptr, unsigned long old, unsigned long new) { return old; }

#define unlikely(x) (x)
#define likely(x) (x)