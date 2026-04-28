#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define PGT_type_mask       (0x7f << 0)
#define PGT_pae_xen_l2      (1 << 7)
#define PGT_count_mask      (0xff << 8)
#define PGT_validated       (1 << 16)
#define PGT_partial         (1 << 17)

#define PGT_writable_page   0
#define PGT_l1_page_table   1
#define PGT_l2_page_table   2
#define PGT_l3_page_table   3
#define PGT_l4_page_table   4
#define PGT_shared_page     5

#define PRI_mfn "lx"
#define PRI_pfn "lx"
#define PRtype_info "lx"
#define XENLOG_WARNING 0
#define EINVAL 22
#define EINTR 4
#define PAGE_ORDER_4K 0

typedef unsigned long cpumask_t;
cpumask_t scratch_cpumask;

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    unsigned long tlbflush_timestamp;
    unsigned int nr_validated_ptes;
    unsigned int partial_pte;
    unsigned int linear_pt_count;
};

struct domain {
    cpumask_t dirty_cpumask;
};

typedef struct {
    unsigned long mfn;
} mfn_t;

typedef struct {
    unsigned long dfn;
} dfn_t;

#define mfn_x(mfn) ((mfn).mfn)
#define page_to_mfn(pg) ((mfn_t){0})
#define get_gpfn_from_mfn(mfn) (0)
#define _dfn(mfn) ((dfn_t){0})

#define ASSERT(cond) ((void)0)
#define BUG_ON(cond) ((void)0)
#define unlikely(cond) (cond)
#define likely(cond) (cond)
#define gdprintk(lvl, fmt, ...) ((void)0)
#define hypercall_preempt_check() (0)
#define cpu_relax() ((void)0)
#define cmpxchg(ptr, old, new) (old)
#define this_cpu(var) (&var)
#define cpumask_copy(dst, src) ((void)0)
#define cpumask_empty(mask) (1)
#define flush_tlb_mask(mask) ((void)0)
#define tlbflush_filter(mask, timestamp) ((void)0)
#define perfc_incr(var) ((void)0)
#define in_irq() (0)
#define shadow_mode_enabled(d) (0)
#define shadow_prepare_page_type_change(d, p, t) ((void)0)
#define page_get_owner(p) (NULL)
#define is_pv_domain(d) (0)
#define need_iommu_pt_sync(d) (0)
#define iommu_legacy_unmap(d, dfn, order) (0)
#define iommu_legacy_map(d, dfn, mfn, order, flags) (0)
#define alloc_page_type(p, t, preempt) (0)
#define put_page(p) ((void)0)

typedef unsigned int IOMMUF_readable;
typedef unsigned int IOMMUF_writable;