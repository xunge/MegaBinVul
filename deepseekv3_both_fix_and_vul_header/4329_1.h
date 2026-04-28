#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define always_inline __attribute__((always_inline))

typedef uint64_t mfn_t;
typedef uint64_t gfn_t;
typedef uint32_t u32;
typedef uint64_t guest_intpte_t;
typedef int bool_t;
typedef int fetch_type_t;
typedef int p2m_type_t;

struct domain {
    struct {
        struct {
            struct sh_dirty_vram *dirty_vram;
            bool is_in_uc_mode;
        } hvm_domain;
        struct {
            unsigned long gfn_bits;
            struct {
                int has_fast_mmio_entries;
            } shadow;
        } paging;
    } arch;
};

struct vcpu {
    struct domain *domain;
};

struct sh_dirty_vram {
    int last_dirty;
    unsigned long begin_pfn;
    unsigned long end_pfn;
};

typedef union {
    guest_intpte_t l1;
} guest_l1e_t;

typedef union {
    uint64_t l1;
} shadow_l1e_t;

#define GUEST_PAGING_LEVELS 4
#define SHADOW_PAGING_LEVELS 4
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_OUT_OF_SYNC 0
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define _PAGE_USER (1UL << 2)
#define _PAGE_ACCESSED (1UL << 5)
#define _PAGE_DIRTY (1UL << 6)
#define _PAGE_PSE (1UL << 7)
#define _PAGE_PAT (1UL << 7)
#define _PAGE_PCD (1UL << 4)
#define _PAGE_PWT (1UL << 3)
#define _PAGE_NX_BIT (1UL << 63)

#define p2m_is_valid(x) (0)
#define p2m_is_grant(x) (0)
#define p2m_is_readonly(x) (0)
#define p2m_mmio_dm 0
#define p2m_mmio_direct 0
#define MTRR_TYPE_UNCACHABLE 0
#define NO_HARDCODE_MEM_TYPE 0
#define PAT_TYPE_UNCACHABLE 0
#define PAT_TYPE_WRBACK 0
#define FETCH_TYPE_WRITE 0
#define ft_prefetch 0
#define ft_demand_write 0

#define ASSERT(x)
#define unlikely(x) (x)
#define is_hvm_domain(d) (0)
#define is_pv_domain(d) (0)
#define is_pv_32bit_domain(d) (0)
#define shadow_mode_refcounts(d) (0)
#define shadow_mode_log_dirty(d) (0)
#define guest_supports_nx(v) (0)
#define guest_supports_superpages(v) (0)
#define is_xen_heap_mfn(x) (0)
#define mfn_valid(x) (0)
#define mfn_x(x) (0)
#define gfn_x(x) (0)
#define mfn_to_page(x) (NULL)
#define page_get_owner(x) (NULL)
#define dom_io NULL
#define iomem_access_permitted(d, x, y) (0)
#define iommu_snoop (0)
#define rangeset_contains_singleton(x, y) (0)
#define mmio_ro_ranges NULL
#define sh_mfn_is_a_page_table(x) (0)
#define mfn_oos_may_write(x) (0)
#define NOW() (0)

static inline gfn_t guest_l1e_get_gfn(guest_l1e_t entry) { return 0; }
static inline u32 guest_l1e_get_flags(guest_l1e_t entry) { return 0; }
static inline shadow_l1e_t shadow_l1e_empty(void) { return (shadow_l1e_t){0}; }
static inline shadow_l1e_t sh_l1e_gnp(void) { return (shadow_l1e_t){0}; }
static inline shadow_l1e_t sh_l1e_mmio(gfn_t gfn, u32 flags) { return (shadow_l1e_t){0}; }
static inline shadow_l1e_t shadow_l1e_from_mfn(mfn_t mfn, u32 flags) { return (shadow_l1e_t){0}; }
static inline int hvm_get_mem_pinned_cacheattr(struct domain *d, gfn_t gfn, int type) { return 0; }
static inline u32 pat_type_2_pte_flags(int type) { return 0; }
static inline u32 get_pat_flags(struct vcpu *v, u32 gflags, uint64_t gpa, uint64_t mpa, int type) { return 0; }
static inline void paging_mark_dirty(struct domain *d, unsigned long mfn) {}
static inline bool_t paging_mfn_is_dirty(struct domain *d, mfn_t mfn) { return 0; }
static inline uint64_t gfn_to_paddr(gfn_t gfn) { return 0; }
static inline uint64_t pfn_to_paddr(unsigned long pfn) { return 0; }

#define SHADOW_DEBUG(level, fmt, ...)
#define SH_PRI_gpte "lx"
#define SH_PRI_pte "lx"
static const char *fetch_type_names[] = {""};