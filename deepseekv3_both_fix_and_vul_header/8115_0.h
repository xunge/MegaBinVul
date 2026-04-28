#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <linux/types.h>

typedef unsigned long l2_pgentry_t;

#define _PAGE_PRESENT   0x001
#define _PAGE_RW        0x002
#define _PAGE_PSE       0x080
#define L2_DISALLOW_MASK 0x80000000
#define FASTPATH_FLAG_WHITELIST 0
#define EPERM           1
#define EFAULT          14
#define EINVAL          22
#define EBUSY           16

#define unlikely(x) (x)
#define likely(x) (x)

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

#define MEM_LOG(fmt, ...)

static inline bool is_guest_l2_slot(struct domain *d, unsigned long type, unsigned long slot)
{
    return false;
}

static inline unsigned long pgentry_ptr_to_slot(l2_pgentry_t *pl2e)
{
    return 0;
}

static inline unsigned long l2e_get_flags(l2_pgentry_t l2e)
{
    return 0;
}

static inline bool l2e_has_changed(l2_pgentry_t old, l2_pgentry_t new, unsigned long mask)
{
    return false;
}

static inline void adjust_guest_l2e(l2_pgentry_t l2e, struct domain *d)
{
}

static inline int get_page_from_l2e(l2_pgentry_t l2e, unsigned long pfn, struct domain *d)
{
    return 0;
}

static inline void put_page_from_l2e(l2_pgentry_t l2e, unsigned long pfn)
{
}

static inline struct page_info *mfn_to_page(unsigned long mfn)
{
    return NULL;
}

#define UPDATE_ENTRY(lvl, pl2e, ol2e, nl2e, pfn, vcpu, preserve_ad) (0)

extern int opt_allow_superpage;