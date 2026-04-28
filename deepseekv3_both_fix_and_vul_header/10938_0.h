#include <stdint.h>

struct domain;
struct page_info;

typedef uint64_t mfn_t;
typedef uint64_t l3_pgentry_t;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) ((mfn_t)(mfn))

#define PTF_partial_set (1U << 0)
#define L3_PAGETABLE_ENTRIES 512

#define EINTR 4
#define ERESTART 512

struct page_info {
    struct domain *owner;
    unsigned int nr_validated_ptes;
    unsigned int partial_flags;
};

static inline mfn_t page_to_mfn(struct page_info *page);
static struct domain *page_get_owner(struct page_info *page);
static l3_pgentry_t *map_domain_page(mfn_t mfn);
static void unmap_domain_page(void *ptr);
static int put_page_from_l3e(l3_pgentry_t l3e, unsigned long pfn, unsigned int flags);
static l3_pgentry_t unadjust_guest_l3e(l3_pgentry_t l3e, struct domain *d);
static int hypercall_preempt_check(void);