#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint64_t u64;

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
    void *d_fsdata;
};

struct inode {
    pthread_mutex_t i_mutex;
    unsigned long i_ino;
};

struct btrfs_root;
struct btrfs_qgroup_inherit;
struct btrfs_inode;
struct btrfs_root_item {
    int refs;
};

#define noinline __attribute__((noinline))
#define I_MUTEX_PARENT 1
#define EEXIST 17
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)

#define BTRFS_I(inode) ((struct btrfs_inode *)(inode))

struct btrfs_inode {
    struct btrfs_root *root;
};

struct btrfs_root {
    struct btrfs_fs_info *fs_info;
    struct btrfs_root_item root_item;
};

struct btrfs_fs_info {
    pthread_rwlock_t subvol_sem;
};

static inline int btrfs_root_refs(struct btrfs_root_item *item)
{
    return item->refs;
}

static inline void mutex_lock_nested(pthread_mutex_t *mutex, int subclass) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline void down_read(pthread_rwlock_t *rwlock) {
    pthread_rwlock_rdlock(rwlock);
}

static inline void up_read(pthread_rwlock_t *rwlock) {
    pthread_rwlock_unlock(rwlock);
}

static inline struct dentry *lookup_one_len(const char *name, struct dentry *parent, int len) {
    return NULL;
}

static inline void dput(struct dentry *dentry) {
}

static inline void fsnotify_mkdir(struct inode *dir, struct dentry *dentry) {
}

extern int btrfs_may_create(struct inode *dir, struct dentry *dentry);
extern int create_snapshot(struct btrfs_root *root, struct dentry *dentry,
              char *name, int namelen, u64 *async_transid,
              bool readonly, struct btrfs_qgroup_inherit **inherit);
extern int create_subvol(struct btrfs_root *root, struct dentry *dentry,
             char *name, int namelen, u64 *async_transid,
             struct btrfs_qgroup_inherit **inherit);