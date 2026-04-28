#include <stdatomic.h>
#include <stdbool.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct ucounts {
    atomic_int count;
    struct hlist_node node;
    void *ns;
};

extern int ucounts_lock;