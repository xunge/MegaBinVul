#include <stddef.h>

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct spinlock {
    int lock;
};

struct inode {
    struct spinlock i_lock;
};

struct dentry {
    struct inode *d_inode;
    struct spinlock d_lock;
    struct hlist_node d_alias;
    struct {
        struct hlist_node d_alias;
    } d_u;
};

struct super_block {
    struct dentry *s_root;
};

#define ENOMEM 12

struct dentry *d_make_root(struct inode *inode);
void ihold(struct inode *inode);
void spin_lock(struct spinlock *lock);
void spin_unlock(struct spinlock *lock);
void hlist_del_init(struct hlist_node *n);