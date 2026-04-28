#include <stdint.h>
#include <inttypes.h>

typedef uint64_t mfn_t;

struct domain;
struct vcpu {
    struct domain *domain;
};

struct arch_domain {
    struct {
        struct {
            int oos_active;
        } shadow;
    } paging;
};

struct domain {
    struct arch_domain arch;
};

struct page_info {
    unsigned long shadow_flags;
};

#define SHF_page_type_mask 0
#define SHF_L1_ANY 0
#define SHF_out_of_sync 0
#define SHF_oos_may_write 0

#define ASSERT(cond) ((void)0)
#define SHADOW_PRINTK(fmt, ...) ((void)0)
#define PRI_mfn "lx"
#define mfn_x(mfn) (mfn)
#define TRACE_SHADOW_PATH_FLAG(flag) ((void)0)
#define TRCE_SFLAG_UNSYNC 0
#define shadow_unsync 0

int paging_locked_by_me(struct domain *d);
struct page_info *mfn_to_page(mfn_t mfn);
int sh_page_has_multiple_shadows(struct page_info *pg);
int is_pv_vcpu(struct vcpu *v);
void oos_hash_add(struct vcpu *v, mfn_t gmfn);
void perfc_incr(int counter);