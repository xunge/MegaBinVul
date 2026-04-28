#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct page {
    unsigned long private;
    struct address_space *mapping;
    struct list_head lru;
};

struct hstate {
    int surplus_huge_pages;
    int surplus_huge_pages_node[];
};

struct address_space {
    // Members omitted
};

typedef struct {
    int lock;
} spinlock_t;

static void spin_lock(spinlock_t *lock) {
    (void)lock;
}

static void spin_unlock(spinlock_t *lock) {
    (void)lock;
}

static void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

#define BUG_ON(condition) ((void)0)

extern struct hstate *page_hstate(struct page *page);
extern int page_to_nid(struct page *page);
extern void update_and_free_page(struct hstate *h, struct page *page);
extern void enqueue_huge_page(struct hstate *h, struct page *page);
extern void hugetlb_put_quota(struct address_space *mapping, long delta);
extern void set_page_private(struct page *page, unsigned long private);
extern unsigned long page_private(struct page *page);
extern int page_count(struct page *page);
extern int page_mapcount(struct page *page);
extern int huge_page_order(struct hstate *h);

#define MAX_ORDER 11

static spinlock_t hugetlb_lock;