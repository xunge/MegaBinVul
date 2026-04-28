#include <stdbool.h>
#include <stddef.h>

typedef bool bool_t;

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

struct domain {
    struct {
        void *relmem_list;
    } arch;
    void *page_alloc_lock;
    void *xenpage_list;
    void *page_list;
    unsigned long xenheap_pages;
    bool is_dying;
};

extern struct domain *dom_cow;
extern bool_t in_irq(void);
extern bool_t is_xen_heap_page(struct page_info *);
extern struct domain *page_get_owner(struct page_info *);
extern void page_list_del2(struct page_info *, void *, void *);
extern void spin_lock_recursive(void *);
extern void spin_unlock_recursive(void *);
extern void BUG_ON(bool);
extern void scrub_one_page(struct page_info *);
extern void free_heap_pages(struct page_info *, unsigned int);
extern bool_t domain_adjust_tot_pages(struct domain *, int);
extern void put_domain(struct domain *);
extern void ASSERT(bool);

#define PGT_count_mask 0
#define unlikely(x) (x)
#define likely(x) (x)