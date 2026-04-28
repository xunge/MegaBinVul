#include <stdbool.h>
#include <stddef.h>

#define RENAME_EXCHANGE 1
#define EPERM 1
#define EINVAL 2
#define EBUSY 3
#define EMLINK 4
#define FS_RENAME_DOES_D_MOVE (1 << 0)

#define MAY_WRITE 1
#define S_DEAD 1

struct qstr {
    const unsigned char *name;
};

struct inode;
struct dentry;
struct super_block;
struct file_system_type;
struct inode_operations;

struct inode {
    struct super_block *i_sb;
    struct inode_operations *i_op;
    unsigned int i_nlink;
    unsigned int i_flags;
};

struct dentry {
    struct inode *d_inode;
    struct qstr d_name;
    unsigned int d_flags;
};

struct super_block {
    unsigned int s_max_links;
    struct file_system_type *s_type;
};

struct file_system_type {
    unsigned int fs_flags;
};

struct inode_operations {
    int (*rename)(struct inode *, struct dentry *,
                  struct inode *, struct dentry *);
    int (*rename2)(struct inode *, struct dentry *,
                   struct inode *, struct dentry *, unsigned int);
};

static inline bool d_is_dir(const struct dentry *dentry) {
    return false;
}

static int may_delete(struct inode *dir, struct dentry *victim, bool is_dir) {
    return 0;
}

static int may_create(struct inode *dir, struct dentry *dentry) {
    return 0;
}

static int inode_permission(struct inode *inode, int mask) {
    return 0;
}

static int security_inode_rename(struct inode *old_dir, struct dentry *old_dentry,
                                struct inode *new_dir, struct dentry *new_dentry,
                                unsigned int flags) {
    return 0;
}

static const unsigned char *fsnotify_oldname_init(const unsigned char *name) {
    return name;
}

static void fsnotify_oldname_free(const unsigned char *name) {}

static void dget(struct dentry *dentry) {}

static void lock_two_nondirectories(struct inode *inode1, struct inode *inode2) {}

static void inode_lock(struct inode *inode) {}

static bool is_local_mountpoint(struct dentry *dentry) {
    return false;
}

static void shrink_dcache_parent(struct dentry *dentry) {}

static int try_break_deleg(struct inode *inode, struct inode **delegated_inode) {
    return 0;
}

static void dont_mount(struct dentry *dentry) {}

static void detach_mounts(struct dentry *dentry) {}

static void d_move(struct dentry *old_dentry, struct dentry *new_dentry) {}

static void d_exchange(struct dentry *old_dentry, struct dentry *new_dentry) {}

static void unlock_two_nondirectories(struct inode *inode1, struct inode *inode2) {}

static void inode_unlock(struct inode *inode) {}

static void dput(struct dentry *dentry) {}

static void fsnotify_move(struct inode *old_dir, struct inode *new_dir,
                          const unsigned char *name, bool is_dir,
                          struct inode *target, struct dentry *dentry) {}

static void WARN_ON(bool condition) {}