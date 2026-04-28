#include <stdatomic.h>

struct domain;
struct page_info;
typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define _mfn(mfn) ((mfn_t)(mfn))
#define PTF_partial_set (1U << 0)
#define L4_PAGETABLE_ENTRIES 512
#define ERESTART (-1)
#define EINTR (-2)

struct domain {
    struct {
        struct {
            atomic_int nr_l4_pages;
        } pv;
    } arch;
};

struct page_info {
    struct domain *owner;
    unsigned int nr_validated_ptes;
    unsigned int partial_flags;
};

typedef struct {
    unsigned long val;
} l4_pgentry_t;

static struct domain *page_get_owner(struct page_info *page);
static mfn_t page_to_mfn(struct page_info *page);
static l4_pgentry_t *map_domain_page(mfn_t mfn);
static void unmap_domain_page(void *ptr);
static int is_guest_l4_slot(struct domain *d, unsigned int i);
static int put_page_from_l4e(l4_pgentry_t l4e, pfn_t pfn, unsigned int flags);