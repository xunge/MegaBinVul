#include <stddef.h>
#include <errno.h>

#define unlikely(x) (x)
#define likely(x)   (x)

#define _PAGE_PRESENT   0x001
#define _PAGE_RW        0x002
#define _PAGE_PSE       0x080
#define L2_DISALLOW_MASK 0x80000000

#define MEM_LOG(fmt, ...) 

typedef unsigned long l2_pgentry_t;

struct vcpu {
    struct domain *domain;
};

struct domain {
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

enum {
    l1,
    l2,
    l3,
    l4
};

static inline int is_guest_l2_slot(struct domain *d, unsigned long type, int slot) { return 1; }
static inline int pgentry_ptr_to_slot(l2_pgentry_t *pl2e) { return 0; }
static inline unsigned long l2e_get_flags(l2_pgentry_t l2e) { return 0; }
static inline int l2e_has_changed(l2_pgentry_t old, l2_pgentry_t new, unsigned long mask) { return 0; }
static inline void adjust_guest_l2e(l2_pgentry_t l2e, struct domain *d) {}
static inline int UPDATE_ENTRY(int level, l2_pgentry_t *pl2e, l2_pgentry_t ol2e, l2_pgentry_t nl2e, unsigned long pfn, struct vcpu *vcpu, int preserve_ad) { return 1; }
static inline int get_page_from_l2e(l2_pgentry_t l2e, unsigned long pfn, struct domain *d) { return 0; }
static inline void put_page_from_l2e(l2_pgentry_t l2e, unsigned long pfn) {}
static inline struct page_info *mfn_to_page(unsigned long pfn) { return NULL; }
static inline int __copy_from_user(void *dst, const void *src, size_t size) { return 0; }

extern int opt_allow_superpage;