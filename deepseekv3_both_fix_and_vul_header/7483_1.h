#include <stddef.h>
#include <stdlib.h>

struct kref {
    int refcount;
};

struct page {
    // dummy page structure
};

struct rcu_head {
    // dummy rcu head
};

struct watch_queue {
    struct kref usage;
    int nr_pages;
    struct page **notes;
    unsigned long *notes_bitmap;
    struct watch_filter *filter;
};

struct watch_filter {
    struct rcu_head rcu;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define rcu_access_pointer(p) (p)
#define kfree_rcu(ptr, rcu) free(ptr)
#define __free_page(page) free(page)
#define bitmap_free(bitmap) free(bitmap)