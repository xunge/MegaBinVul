#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define PGC_count_mask 0xffffffff
#define PGC_allocated 0x1
#define PGT_count_mask 0xffffffff
#define PGT_locked 0x1
#define PGT_pinned 0x2
#define DOMID_INVALID (-1)
#define PRI_mfn "lx"
#define PRtype_info "lx"
#define XENLOG_WARNING 0
#define MEMF_no_refcount 0x1

typedef bool bool_t;

struct spinlock {
    int lock;
};

struct list_head {
    struct list_head *next, *prev;
};

struct domain {
    int domain_id;
    struct spinlock page_alloc_lock;
    struct list_head page_list;
};

struct page_info {
    unsigned long count_info;
    union {
        unsigned long type_info;
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

extern struct domain *dom_xen;
extern void spin_lock(struct spinlock *);
extern void spin_unlock(struct spinlock *);
extern bool_t is_xen_heap_page(struct page_info *);
extern struct domain *page_get_owner(struct page_info *);
extern void page_set_owner(struct page_info *, struct domain *);
extern bool_t domain_adjust_tot_pages(struct domain *, int);
extern void page_list_del(struct page_info *, struct list_head *);
extern void put_domain(struct domain *);
extern void gdprintk(int, const char *, ...);
extern unsigned long page_to_mfn(struct page_info *);
extern void BUG_ON(bool);
extern unsigned long cmpxchg(unsigned long *, unsigned long, unsigned long);
extern int unlikely(int);