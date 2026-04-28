#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

#define EOPNOTSUPP 95
#define EINVAL 22

#define PGC_count_mask 0x00ff
#define PGC_allocated 0x0100
#define PGT_count_mask 0x00ff
#define PGT_locked 0x0100
#define PGT_pinned 0x0200
#define MEMF_no_refcount 0x01
#define MEMF_no_owner 0x02
#define PRI_mfn "lx"
#define PRtype_info "lx"
#define DOMID_INVALID (-1)
#define XENLOG_WARNING 1

struct spinlock {
    unsigned int lock;
};

struct list_head {
    struct list_head *next, *prev;
};

struct domain {
    unsigned int domain_id;
    struct spinlock page_alloc_lock;
    struct list_head page_list;
};

struct page_info {
    unsigned long count_info;
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

static inline void spin_lock(struct spinlock *lock) {
    while (__sync_lock_test_and_set(&lock->lock, 1));
}

static inline void spin_unlock(struct spinlock *lock) {
    __sync_lock_release(&lock->lock);
}

extern int paging_mode_external(struct domain *d);
extern bool is_xen_heap_page(struct page_info *page);
extern const struct domain *page_get_owner_and_reference(struct page_info *page);
extern void put_page(struct page_info *page);
extern int cleanup_page_cacheattr(struct page_info *page);
extern void page_set_owner(struct page_info *page, struct domain *d);
extern void page_list_del(struct page_info *page, struct list_head *list);
extern bool domain_adjust_tot_pages(struct domain *d, int delta);
extern void put_domain(struct domain *d);
extern unsigned long mfn_x(unsigned long mfn);
extern unsigned long page_to_mfn(struct page_info *page);
extern void gdprintk(int level, const char *fmt, ...);

static inline unsigned long cmpxchg(volatile unsigned long *ptr,
                                  unsigned long old,
                                  unsigned long new) {
    return __sync_val_compare_and_swap(ptr, old, new);
}

#define BUG_ON(condition) do { if (condition) __builtin_trap(); } while (0)
#define unlikely(x) __builtin_expect(!!(x), 0)