#include <stdint.h>

#define SHADOW_PAGING_LEVELS 4
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define SH_LINEAR_PT_VIRT_START 0
#define TRCE_SFLAG_WRMAP_GUESS_FOUND 0
#define SHADOW_SET_ERROR (1 << 0)
#define p2m_ram_rw 0

typedef uint64_t mfn_t;
typedef uint64_t shadow_l1e_t;
typedef uint64_t shadow_l2e_t;
typedef uint64_t shadow_l3e_t;
typedef uint64_t shadow_l4e_t;

struct domain;
struct paging {
    struct {
        void *l3table;
        shadow_l4e_t *guest_vtable;
    } shadow;
};
struct vcpu {
    struct domain *domain;
    struct {
        struct paging paging;
    } arch;
};

#define mfn_x(mfn) (mfn)
#define shadow_l1e_get_flags(l1e) (l1e)
#define shadow_l1e_get_mfn(l1e) (l1e)
#define shadow_l1e_remove_flags(l1e, flags) (l1e & ~(flags))
#define shadow_l2e_get_flags(l2e) (l2e)
#define shadow_l2e_get_mfn(l2e) (l2e)
#define shadow_l3e_get_flags(l3e) (l3e)
#define shadow_l4e_get_flags(l4e) (l4e)
#define shadow_l1_linear_offset(addr) (addr)
#define shadow_l2_linear_offset(addr) (addr)
#define shadow_l3_linear_offset(addr) (addr)
#define shadow_l4_linear_offset(addr) (addr)
#define shadow_l4_table_offset(addr) (addr)
#define l4_linear_offset(addr) (addr)

extern shadow_l1e_t *__linear_l1_table;
extern shadow_l2e_t *__linear_l2_table;
extern shadow_l3e_t *__linear_l3_table;
extern shadow_l4e_t *__linear_l4_table;

shadow_l1e_t *sh_linear_l1_table(struct vcpu *v);
shadow_l2e_t *sh_linear_l2_table(struct vcpu *v);
shadow_l3e_t *sh_linear_l3_table(struct vcpu *v);
shadow_l4e_t *sh_linear_l4_table(struct vcpu *v);
int paging_mode_external(struct domain *d);
int shadow_set_l1e(struct domain *d, shadow_l1e_t *sl1p, shadow_l1e_t sl1e, int p2m_type, mfn_t sl1mfn);
#define TRACE_SHADOW_PATH_FLAG(flag)