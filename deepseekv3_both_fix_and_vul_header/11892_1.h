#include <stdint.h>
#include <stdbool.h>

typedef uint64_t mfn_t;
typedef uint64_t paddr_t;

#define ASSERT(cond) ((void)0)
#define mfn_valid(mfn) (1)
#define is_hvm_domain(d) (1)
#define mfn_to_page(mfn) ((struct page_info *)(mfn))
#define mfn_eq(a, b) ((a) == (b))
#define map_domain_page(mfn) ((void *)(mfn))
#define unmap_domain_page(ptr) ((void)0)
#define shadow_l1e_get_flags(e) (0)
#define shadow_l1e_get_mfn(e) ((mfn_t)0)
#define shadow_l1e_remove_flags(e, f) (e)
#define shadow_set_l1e(d, p, e, t, m) (0)
#define perfc_incr(c) ((void)0)

#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define PGC_count_mask (0xFFUL)
#define SH_type_l1_shadow 1
#define SH_type_fl1_shadow 2
#define SHF_pagetable_dying (1UL << 0)
#define SHADOW_SET_ERROR (1UL << 0)
#define p2m_ram_rw 0

struct domain {
    int dummy;
};

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            struct {
                bool pagetable_dying;
            } shadow;
        } paging;
    } arch;
};

struct page_info {
    uint64_t count_info;
    union {
        struct {
            int type;
        } sh;
    } u;
    uint64_t shadow_flags;
    bool pagetable_dying;
};

typedef uint64_t shadow_l1e_t;

extern struct vcpu *current;