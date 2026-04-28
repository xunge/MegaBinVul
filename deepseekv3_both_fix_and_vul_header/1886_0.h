#include <stddef.h>
#include <stdint.h>

typedef uint64_t mfn_t;
typedef uint64_t shadow_l1e_t;

struct domain {
    unsigned int shadow_mode;
};

struct page {
    unsigned int flags;
};

static inline mfn_t shadow_l1e_get_mfn(shadow_l1e_t sl1e) { return 0; }
static inline int shadow_mode_refcounts(struct domain *d) { return 0; }
static inline int mfn_valid(mfn_t mfn) { return 0; }
static inline struct page *mfn_to_page(mfn_t mfn) { return NULL; }
static inline int page_refcounting_suppressed(struct page *p) { return 0; }
static inline void put_page_from_l1e(shadow_l1e_t sl1e, struct domain *d) {}