#include <stdint.h>

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) (mfn)
#define PGT_pae_xen_l2 (1U << 0)
#define PTF_partial_set (1U << 0)
#define L2_PAGETABLE_ENTRIES 512
#define EINTR 4
#define ERESTART 512

typedef uint64_t l2_pgentry_t;

struct domain {
    // minimal definition needed for compilation
};

struct page_info {
    struct {
        struct {
            unsigned int type_info;
        } inuse;
    } u;
    unsigned int partial_flags;
    unsigned int nr_validated_ptes;
};

static struct domain *page_get_owner(struct page_info *page);
static unsigned long page_to_mfn(struct page_info *page);
static l2_pgentry_t *map_domain_page(unsigned long mfn);
static void unmap_domain_page(l2_pgentry_t *pl2e);
static int is_guest_l2_slot(struct domain *d, unsigned int type_info, unsigned int i);
static int put_page_from_l2e(l2_pgentry_t l2e, unsigned long pfn, unsigned int flags);
static int hypercall_preempt_check(void);