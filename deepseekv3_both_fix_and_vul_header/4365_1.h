#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct fuse_conn {
    struct list_head devices;
    struct rcu_head rcu;
};

#define WARN_ON(condition) ((void)(condition))
#define kfree_rcu(ptr, member) free(ptr)