#include <stdint.h>

#define PAGE_SHIFT 12

typedef uint64_t gfn_t;

struct domain;
struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

#define _gfn(x) ((gfn_t)(x))
#define _mfn(x) ((unsigned long)(x))

#define GNTST_okay 0
#define GNTST_general_error 1
#define GNTMAP_contains_pte (1U << 0)

int guest_physmap_remove_page(struct domain *d, gfn_t gfn, unsigned long mfn, int flags);