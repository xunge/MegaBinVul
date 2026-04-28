#include <stddef.h>

#define EINVAL 22
#define DENTRY_D_LOCK_NESTED 1
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

typedef long long loff_t;

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct spinlock_t {
    int dummy;
};

struct inode {
    struct mutex i_mutex;
};

struct dentry {
    struct inode *d_inode;
    struct spinlock_t d_lock;
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
};

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
    loff_t f_pos;
    void *private_data;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void spin_lock(struct spinlock_t *lock) {}
static inline void spin_unlock(struct spinlock_t *lock) {}
static inline void spin_lock_nested(struct spinlock_t *lock, int subclass) {}
static inline void list_del(struct list_head *entry) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline int simple_positive(struct dentry *dentry) { return 0; }

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)