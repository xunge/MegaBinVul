#include <stdint.h>
#include <stddef.h>

#define SHADOW_PAGING_LEVELS 4
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define SH_LINEAR_PT_VIRT_START 0
#define TRCE_SFLAG_WRMAP_GUESS_FOUND 0
#define SHADOW_SET_ERROR (1 << 0)

typedef uint64_t mfn_t;
typedef uint64_t shadow_l1e_t;
typedef uint64_t shadow_l2e_t;
typedef uint64_t shadow_l3e_t;
typedef uint64_t shadow_l4e_t;

struct domain;
struct shadow_paging {
    struct {
        void *guest_vtable;
        void *l3table;
    } shadow;
};

struct arch_vcpu {
    struct shadow_paging paging;
};

struct vcpu {
    struct domain *domain;
    struct arch_vcpu arch;
};

#define mfn_x(mfn) (mfn)
#define shadow_l1e_get_flags(l1e) (l1e)
#define shadow_l1e_get_mfn(l1e) (l1e)
#define shadow_l1e_remove_flags(l1e, flags) (l1e)
#define shadow_l2e_get_flags(l2e) (l2e)
#define shadow_l2e_get_mfn(l2e) (l2e)
#define shadow_l3e_get_flags(l3e) (l3e)
#define shadow_l4e_get_flags(l4e) (l4e)
#define shadow_l1_table_offset(addr) (0)
#define shadow_l2_table_offset(addr) (0)
#define shadow_l3_table_offset(addr) (0)
#define shadow_l4_table_offset(addr) (0)
#define shadow_l1_linear_offset(addr) (0)
#define shadow_l2_linear_offset(addr) (0)
#define shadow_l3_linear_offset(addr) (0)
#define shadow_l4_linear_offset(addr) (0)

enum p2m_type {
    p2m_ram_rw
};

static inline shadow_l1e_t *sh_linear_l1_table(struct vcpu *v) { return NULL; }
static inline shadow_l2e_t *sh_linear_l2_table(struct vcpu *v) { return NULL; }
static inline shadow_l3e_t *sh_linear_l3_table(struct vcpu *v) { return NULL; }
static inline shadow_l4e_t *sh_linear_l4_table(struct vcpu *v) { return NULL; }
static inline int shadow_set_l1e(struct domain *d, shadow_l1e_t *l1p, shadow_l1e_t l1e, enum p2m_type p2mt, mfn_t mfn) { return 0; }
#define TRACE_SHADOW_PATH_FLAG(flag)