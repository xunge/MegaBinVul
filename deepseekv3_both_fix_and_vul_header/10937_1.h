#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define PRI_mfn "lx"
#define PRI_pfn "lx"
#define PRtype_info "lx"

#define PGT_type_mask 0x7
#define PGT_pae_xen_l2 (1 << 3)
#define PGT_count_mask (0xff << 4)
#define PGT_validated (1 << 12)
#define PGT_partial (1 << 13)
#define PGT_writable_page 1
#define PGT_shared_page 2
#define PGT_l1_page_table 3
#define PGT_l2_page_table 4
#define PGT_l3_page_table 5
#define PGT_l4_page_table 6

#define XENLOG_WARNING 1
#define PAGE_ORDER_4K 0
#define EINVAL 22
#define EINTR 4

#define IOMMUF_readable (1 << 0)
#define IOMMUF_writable (1 << 1)

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    unsigned long tlbflush_timestamp;
    unsigned nr_validated_ptes;
    unsigned partial_flags;
    unsigned linear_pt_count;
};

typedef struct {
    unsigned long bits[1];
} cpumask_t;

struct domain {
    cpumask_t *dirty_cpumask;
};

typedef struct {
    unsigned long x;
} mfn_t;

typedef unsigned long dfn_t;

#define mfn_x(mfn) ((mfn).x)
#define _dfn(x) ((dfn_t){x})

static void ASSERT(bool cond) {}
static bool in_irq(void) { return false; }
static void gdprintk(int level, const char *fmt, ...) {}
static bool shadow_mode_enabled(struct domain *d) { return false; }
static struct domain *page_get_owner(struct page_info *page) { return NULL; }
static void shadow_prepare_page_type_change(struct domain *d, struct page_info *page, unsigned long type) {}
static mfn_t page_to_mfn(struct page_info *page) { return (mfn_t){0}; }
static unsigned long get_gpfn_from_mfn(unsigned long mfn) { return 0; }
static void cpu_relax(void) {}
static bool hypercall_preempt_check(void) { return false; }
static unsigned long cmpxchg(unsigned long *ptr, unsigned long old, unsigned long new) { return 0; }
static bool is_pv_domain(struct domain *d) { return false; }
static bool need_iommu_pt_sync(struct domain *d) { return false; }
static int iommu_legacy_unmap(struct domain *d, dfn_t dfn, unsigned int order) { return 0; }
static int iommu_legacy_map(struct domain *d, dfn_t dfn, mfn_t mfn, unsigned int order, unsigned int flags) { return 0; }
static void _put_page_type(struct page_info *page, int flags, void *data) {}
static int alloc_page_type(struct page_info *page, unsigned long type, bool preemptible) { return 0; }
static void put_page(struct page_info *page) {}

#define cpumask_copy(dst, src) {}
#define cpumask_empty(mask) (1)
#define flush_tlb_mask(mask) {}
#define tlbflush_filter(mask, timestamp) {}
#define perfc_incr(counter) {}
#define BUG_ON(cond) {}

#define this_cpu(var) (&var)
#define unlikely(x) (x)
#define likely(x) (x)

static cpumask_t scratch_cpumask;