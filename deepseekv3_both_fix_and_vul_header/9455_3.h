#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct dentry {
    struct dentry *d_parent;
    struct list_head d_child;
    struct list_head d_subdirs;
    union {
        struct list_head d_child;
    } d_u;
};

#define IS_ROOT(d) ((d) == (d)->d_parent)

static inline void managed_dentry_clear_managed(struct dentry *dentry) {}
static inline void managed_dentry_set_managed(struct dentry *dentry) {}