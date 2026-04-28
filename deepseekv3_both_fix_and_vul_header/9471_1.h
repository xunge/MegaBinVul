#include <pthread.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    union {
        struct list_head d_child;
        struct list_head d_u;
    };
    pthread_spinlock_t d_lock;
};

struct inode {
    pthread_mutex_t i_mutex;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)

void dget_dlock(struct dentry *dentry);
void __d_drop(struct dentry *dentry);
void dput(struct dentry *dentry);
int d_unhashed(struct dentry *dentry);
void simple_unlink(struct inode *dir, struct dentry *dentry);
void shrink_dcache_parent(struct dentry *dir);