#include <stdint.h>

typedef uint64_t gfn_t;

#define PAGE_SHIFT 12
#define GNTST_okay 0
#define GNTST_general_error 1
#define GNTMAP_contains_pte (1 << 0)

struct domain {
    struct domain *domain;
};

extern struct domain *current;

static inline gfn_t _gfn(unsigned long val) { return (gfn_t)val; }
static inline unsigned long _mfn(unsigned long val) { return val; }

int guest_physmap_remove_page(struct domain *d, gfn_t gfn, unsigned long mfn, int flags);