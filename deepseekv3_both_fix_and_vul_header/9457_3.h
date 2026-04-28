#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    int lock;
};

struct mutex {
    int lock;
};

struct inode {
    struct mutex i_mutex;
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    struct spinlock d_lock;
    struct list_head d_child;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)

void mutex_lock(struct mutex *lock) {}
void mutex_unlock(struct mutex *lock) {}
void spin_lock(struct spinlock *lock) {}
void spin_unlock(struct spinlock *lock) {}
int d_unhashed(struct dentry *dentry) { return 0; }
void dget_dlock(struct dentry *dentry) {}
void __d_drop(struct dentry *dentry) {}
void simple_unlink(struct inode *dir, struct dentry *dentry) {}
void dput(struct dentry *dentry) {}
void shrink_dcache_parent(struct dentry *parent) {}