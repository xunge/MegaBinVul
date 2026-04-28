#include <stddef.h>

struct mutex {
    int dummy;
};

struct spinlock_t {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct inode {
    struct mutex i_mutex;
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    union {
        struct list_head d_child;
        struct {
            struct list_head d_u;
        };
    };
    struct spinlock_t d_lock;
    struct list_head d_list;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((head)->next), \
         n = (typeof(*pos)*)(pos->d_list.next); \
         &pos->d_list != (head); \
         pos = n, n = (typeof(*pos)*)(n->d_list.next))

void mutex_lock(struct mutex *lock) {}
void mutex_unlock(struct mutex *lock) {}
void spin_lock(struct spinlock_t *lock) {}
void spin_unlock(struct spinlock_t *lock) {}
void dget_dlock(struct dentry *dentry) {}
void __d_drop(struct dentry *dentry) {}
void dput(struct dentry *dentry) {}
int d_unhashed(struct dentry *dentry) { return 0; }
void shrink_dcache_parent(struct dentry *dir) {}
void simple_unlink(struct inode *dir, struct dentry *dentry) {}