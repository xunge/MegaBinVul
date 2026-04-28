#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define NDEBUG
#define MAPPING_UNHANDLEABLE ((void *)-1)
#define MAPPING_EXCEPTION ((void *)-2)
#define MAPPING_SILENT_FAIL ((void *)-3)
#define BAD_GVA_TO_GFN (-1UL)
#define READONLY_GFN (-2UL)
#define INVALID_MFN (-1UL)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SIZE 4096
#define _PAGE_PRESENT (1UL << 0)
#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_SKIP_VERIFY 0
#define likely(x) (x)
#define mfn_x(mfn) (mfn)
#define mfn_valid(mfn) ((mfn) != INVALID_MFN)
#define gdprintk(level, fmt, ...)
#define XENLOG_DEBUG 0

struct vcpu {
    struct domain *domain;
};

struct domain {
    bool is_hvm;
};

struct sh_emulate_ctxt {
    unsigned long mfn[2];
    bool low_bit_was_clear;
};

static inline bool is_hvm_domain(struct domain *d) { return d->is_hvm; }
static inline int hvm_get_cpl(struct vcpu *v) { return 0; }
static inline bool guest_kernel_mode(struct vcpu *v, void *regs) { return true; }
static inline void *guest_cpu_user_regs(void) { return NULL; }
static inline unsigned long emulate_gva_to_mfn(struct vcpu *v, unsigned long vaddr, struct sh_emulate_ctxt *ctxt) { return 0; }
static inline void *map_domain_page(unsigned long mfn) { return NULL; }
static inline void put_page(void *page) {}
static inline void *mfn_to_page(unsigned long mfn) { return NULL; }
static inline void *vmap(unsigned long *mfns, int count) { return NULL; }
static inline void sh_remove_shadows(struct domain *d, unsigned long mfn, int a, int b) {}