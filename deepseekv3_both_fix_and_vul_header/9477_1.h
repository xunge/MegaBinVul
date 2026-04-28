#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct dentry {
    int d_lock;
    struct list_head d_subdirs;
    union {
        struct list_head d_child;
        struct {
            struct list_head d_u;
        };
    };
};

#define DENTRY_D_LOCK_NESTED 1
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define spin_lock_nested(lock, subclass) (void)0
#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = NULL)

int simple_positive(struct dentry *dentry);