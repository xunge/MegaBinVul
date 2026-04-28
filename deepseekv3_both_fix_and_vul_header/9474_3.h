#include <stddef.h>

typedef struct {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct dentry {
    unsigned int d_flags;
    struct dentry *d_parent;
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
    spinlock_t d_lock;
    void *d_fsdata;
};

struct super_block {
    struct dentry *s_root;
};

struct vfsmount {};

struct autofs_sb_info {
    unsigned long exp_timeout;
    spinlock_t fs_lock;
    spinlock_t lookup_lock;
};

struct completion {
    unsigned int done;
    unsigned int waiters;
};

struct autofs_info {
    unsigned int flags;
    struct completion expire_complete;
};

enum {
    AUTOFS_INF_NO_RCU,
    AUTOFS_INF_EXPIRING
};

unsigned long now;
unsigned long jiffies;

#define DENTRY_D_LOCK_NESTED 0

void spin_lock(spinlock_t *lock);
void spin_unlock(spinlock_t *lock);
void spin_lock_nested(spinlock_t *lock, int subclass);
void synchronize_rcu(void);
void smp_mb(void);
void dput(struct dentry *dentry);
void list_move(struct list_head *list, struct list_head *head);
void init_completion(struct completion *x);
void DPRINTK(const char *fmt, ...);

struct dentry *get_next_positive_subdir(struct dentry *prev, struct dentry *root);
struct dentry *should_expire(struct dentry *dentry, struct vfsmount *mnt, unsigned long timeout, int how);
struct autofs_info *autofs4_dentry_ino(struct dentry *dentry);