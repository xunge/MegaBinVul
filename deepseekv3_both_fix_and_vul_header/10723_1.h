#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

struct page_list_head {
    struct page_info *next;
    struct page_info *prev;
};

typedef struct spinlock {
    int lock;
} spinlock_t;

struct domain {
    int domain_id;
    struct page_list_head page_list;
    spinlock_t page_alloc_lock;
};

struct page_info {
    unsigned long count_info;
    union {
        struct {
            unsigned long inuse:1;
            unsigned long type_info;
        } inuse;
    } u;
};

#define PGC_count_mask   0x00000fff
#define PGC_allocated    (1UL << 12)
#define PGT_count_mask   0x000000ff
#define PGT_locked       (1UL << 8)
#define PGT_pinned       (1UL << 9)
#define PGT_validated    (1UL << 10)

#define DOMID_INVALID    (-1)

#define PRI_mfn "lx"
#define PRtype_info "lx"

#define XENLOG_WARNING   1
#define MEMF_no_refcount (1U << 0)

typedef int bool_t;

extern struct domain *dom_xen;

void spin_lock(spinlock_t *lock);
void spin_unlock(spinlock_t *lock);
struct domain *page_get_owner(struct page_info *page);
void page_set_owner(struct page_info *page, struct domain *d);
bool_t domain_adjust_tot_pages(struct domain *d, int delta);
void put_domain(struct domain *d);
void page_list_del(struct page_info *page, struct page_list_head *list);
unsigned long page_to_mfn(struct page_info *page);
void gdprintk(int level, const char *fmt, ...);
#define BUG_ON(cond) do { if (cond) __builtin_trap(); } while (0)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define is_xen_heap_page(page) (0)

unsigned long cmpxchg(volatile unsigned long *ptr, unsigned long old, unsigned long new);