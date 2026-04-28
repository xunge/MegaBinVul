#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct inode {
    struct hlist_head i_dentry;
    int i_lock;
};

struct dentry {
    struct inode *d_inode;
    struct hlist_node d_alias;
};

#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)
#define dget(d) ((void)0)
#define dput(d) ((void)0)
#define hlist_for_each_entry(pos, head, member) for (pos = NULL; pos != NULL; pos = NULL)