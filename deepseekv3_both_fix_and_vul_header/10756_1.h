#include <stddef.h>

struct domain;

struct hvm_ioreq_page {
    unsigned long gmfn;
    struct page *page;
    void *va;
};

struct page {
    // Minimal page structure definition
};

typedef unsigned long mfn_t;
typedef unsigned long gfn_t;

static inline mfn_t _mfn(mfn_t mfn) {
    return mfn;
}

static inline gfn_t _gfn(unsigned long gfn) {
    return (gfn_t)gfn;
}

static inline mfn_t page_to_mfn(struct page *page) {
    return (mfn_t)page;
}

static inline int guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn, unsigned int page_order) {
    return 0;
}

static inline void domain_crash(struct domain *d) {
}

static inline void clear_page(void *va) {
}