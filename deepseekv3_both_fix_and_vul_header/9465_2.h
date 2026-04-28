#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

typedef struct {
    volatile int lock;
} spinlock_t;

struct inode {
    unsigned int i_mode;
    struct hlist_head i_dentry;
    spinlock_t i_lock;
};

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    struct hlist_node d_alias;
    spinlock_t d_lock;
    unsigned long d_flags;
    struct {
        struct list_head d_child;
    } d_u;
};

#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define S_IFMT 0170000
#define S_IFDIR 0040000
#define DCACHE_FSNOTIFY_PARENT_WATCHED (1 << 0)
#define DENTRY_D_LOCK_NESTED 1

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void spin_lock_nested(spinlock_t *lock, int subclass) { (void)lock; (void)subclass; }

static inline int fsnotify_inode_watches_children(struct inode *inode) { (void)inode; return 0; }

#define hlist_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)