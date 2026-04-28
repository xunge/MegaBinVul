#include <stdatomic.h>
#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct ucounts {
    _Atomic int count;
    struct hlist_node node;
};

static int ucounts_lock;