#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define PGT_type_mask 0x0f
#define PGT_pae_xen_l2 (1 << 4)
#define PGT_count_mask 0xfff0
#define PGT_validated (1 << 12)
#define PGT_partial (1 << 13)
#define PGC_page_table (1 << 4)
#define PRI_mfn "lx"
#define PRI_pfn "lx"
#define PRtype_info "lx"
#define EINVAL 22
#define EINTR 4
#define XENLOG_WARNING 1

#define PGT_writable_page 1
#define PGT_shared_page 2
#define PGT_l1_page_table 3
#define PGT_l2_page_table 4
#define PGT_l3_page_table 5
#define PGT_l4_page_table 6

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

struct domain {
    unsigned long dirty_cpumask;
};

typedef unsigned long cpumask_t;
typedef unsigned long mfn_t;

static cpumask_t scratch_cpumask;
static int need_flush_tlb_flush;

#define mfn_x(mfn) (mfn)
#define page_to_mfn(pg) ((mfn_t){0})
#define get_gpfn_from_mfn(mfn) (0)
#define _dfn(mfn) (0)
#define ASSERT(cond) 
#define BUG_ON(cond) 
#define unlikely(cond) (cond)
#define likely(cond) (cond)
#define gdprintk(level, fmt, ...) 
#define perfc_incr(counter) 
#define this_cpu(var) (&var)
#define cpumask_copy(dst, src) 
#define cpumask_empty(mask) (1)
#define tlbflush_filter(mask, timestamp) 
#define flush_tlb_mask(mask) 
#define cmpxchg(ptr, old, new) (old)
#define cpu_relax() 
#define hypercall_preempt_check() (0)
#define is_pv_domain(d) (0)
#define need_iommu_pt_sync(d) (0)
#define iommu_unmap_page(d, dfn) (0)
#define iommu_map_page(d, dfn, mfn, flags) (0)
#define put_page(page) 
#define alloc_page_type(page, type, preemptible) (0)
#define shadow_mode_enabled(d) (0)
#define shadow_remove_all_shadows(d, mfn) 
#define in_irq() (0)
#define page_get_owner(page) (NULL)