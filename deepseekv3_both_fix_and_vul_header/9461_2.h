#include <stddef.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    void *d_inode;
    int d_lock;
};

#define DENTRY_D_LOCK_NESTED 1
#define list_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void spin_lock_nested(int *lock, int nested) {}
static inline void list_del_init(struct list_head *entry) {}
static inline void dget_dlock(struct dentry *dentry) {}
static inline void d_delete(struct dentry *dentry) {}
static inline void simple_unlink(void *inode, struct dentry *dentry) {}
static inline void dput(struct dentry *dentry) {}