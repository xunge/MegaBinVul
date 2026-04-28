#include <stddef.h>

struct list_head {
    struct list_head *next;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    struct super_block *d_sb;
    int d_lock;
};

struct super_block {
    int dummy;
};

struct autofs_sb_info {
    int lookup_lock;
};

#define DENTRY_D_LOCK_NESTED 1
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_entry(ptr, type, member) container_of(ptr, type, member)

static inline struct autofs_sb_info *autofs4_sbi(struct super_block *sb) { return NULL; }
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void spin_lock_nested(int *lock, int subclass) {}
static inline int d_count(struct dentry *dentry) { return 0; }
static inline int simple_positive(struct dentry *dentry) { return 0; }
static inline struct dentry *dget_dlock(struct dentry *dentry) { return NULL; }
static inline void dput(struct dentry *dentry) {}