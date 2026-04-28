#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define PGT_type_mask 0x7
#define PGT_pae_xen_l2 (1 << 3)
#define PGT_count_mask (0xff << 4)
#define PGT_validated (1 << 12)
#define PGT_partial (1 << 13)
#define PGC_page_table (1 << 4)

#define PGT_writable_page 0
#define PGT_shared_page 1
#define PGT_l1_page_table 2
#define PGT_l2_page_table 3
#define PGT_l3_page_table 4
#define PGT_l4_page_table 5

#define PRI_mfn "lx"
#define PRtype_info "lx"
#define PRI_pfn "lx"

typedef unsigned long cpumask_t;
typedef unsigned long gfn_t;

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
    cpumask_t dirty_cpumask;
};

#define mfn_x(mfn) (mfn)
#define page_to_mfn(pg) (0)
#define mfn_to_gmfn(d, mfn) (0)
#define get_gpfn_from_mfn(mfn) (0)
#define _gfn(gfn) (0)
#define gfn_x(gfn) (0)
#define ASSERT(cond) 
#define BUG_ON(cond) 
#define unlikely(x) (x)
#define likely(x) (x)
#define cmpxchg(ptr, old, new) (old)
#define cpu_relax() 
#define gdprintk(lvl, fmt, ...) 
#define XENLOG_WARNING 0
#define EINVAL 1
#define EINTR 2
#define hypercall_preempt_check() (0)
#define in_irq() (0)
#define shadow_mode_enabled(d) (0)
#define shadow_remove_all_shadows(d, mfn) 
#define page_get_owner(pg) (NULL)
#define is_pv_domain(d) (0)
#define need_iommu(d) (0)
#define iommu_unmap_page(d, gfn) (0)
#define iommu_map_page(d, gfn, mfn, flags) (0)
#define IOMMUF_readable 0
#define IOMMUF_writable 0
#define perfc_incr(counter) 
#define flush_tlb_mask(mask) 
#define tlbflush_filter(mask, timestamp) 
#define cpumask_copy(dst, src) memcpy(dst, &(src), sizeof(cpumask_t))
#define cpumask_empty(mask) (1)
#define this_cpu(var) (NULL)
#define put_page(pg) 
#define alloc_page_type(pg, type, preemptible) (0)