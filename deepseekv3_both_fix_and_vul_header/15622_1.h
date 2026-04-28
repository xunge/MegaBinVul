#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

typedef unsigned int gfp_t;

struct fib6_info {
    union {
        struct list_head fib6_siblings;
        struct list_head nh_list;
    };
    int fib6_ref;
    struct hlist_node gc_link;
};

struct fib6_nh {
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

#define INIT_HLIST_NODE(ptr) do { \
    (ptr)->next = NULL; (ptr)->pprev = NULL; \
} while (0)

static inline void *kzalloc(size_t size, gfp_t flags) {
    (void)flags;
    return calloc(1, size);
}