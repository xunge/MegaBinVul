#include <stddef.h>

typedef struct spinlock {
    int lock;
} spinlock_t;

struct page_info;
struct page_list_head {
    struct page_info *next;
};

struct radix_tree_root {
    void *rnode;
};

struct p2m_domain {
    spinlock_t lock;
    struct page_list_head pages;
    struct page_info *root;
    struct radix_tree_root mem_access_settings;
};

struct domain {
    struct {
        struct p2m_domain p2m;
    } arch;
};

#define P2M_ROOT_ORDER 0

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }

struct page_info *page_list_remove_head(struct page_list_head *);
void free_domheap_page(struct page_info *);
void free_domheap_pages(struct page_info *, int);
void p2m_free_vmid(struct domain *);
void radix_tree_destroy(struct radix_tree_root *, void *);