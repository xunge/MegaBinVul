#include <stdbool.h>
#include <stddef.h>

struct inode;
struct dentry;

struct name_snapshot {
    const char *name;
};

struct qstr {
    const char *name;
};

#define RENAME_EXCHANGE 1
#define EPERM 1
#define EBUSY 16
#define EMLINK 31
#define MAY_WRITE 2

#define S_DEAD 0x01000000

#define FS_RENAME_DOES_D_MOVE 0x00000001

struct super_block {
    unsigned int s_max_links;
    struct file_system_type *s_type;
};

struct file_system_type {
    int fs_flags;
};

struct inode {
    struct super_block *i_sb;
    unsigned int i_nlink;
    struct inode_operations *i_op;
    unsigned long i_flags;
};

struct inode_operations {
    int (*rename)(struct inode *, struct dentry *,
                  struct inode *, struct dentry *,
                  unsigned int);
};

struct dentry {
    struct inode *d_inode;
    struct qstr d_name;
};

int may_delete(struct inode *, struct dentry *, bool);
int may_create(struct inode *, struct dentry *);
int inode_permission(struct inode *, int);
int security_inode_rename(struct inode *, struct dentry *,
                         struct inode *, struct dentry *,
                         unsigned int);
bool d_is_dir(struct dentry *);
void take_dentry_name_snapshot(struct name_snapshot *, struct dentry *);
void release_dentry_name_snapshot(struct name_snapshot *);
void dget(struct dentry *);
void dput(struct dentry *);
void lock_two_nondirectories(struct inode *, struct inode *);
void inode_lock(struct inode *);
void inode_unlock(struct inode *);
bool is_local_mountpoint(struct dentry *);
void shrink_dcache_parent(struct dentry *);
int try_break_deleg(struct inode *, struct inode **);
void dont_mount(struct dentry *);
void detach_mounts(struct dentry *);
void d_move(struct dentry *, struct dentry *);
void d_exchange(struct dentry *, struct dentry *);
void unlock_two_nondirectories(struct inode *, struct inode *);
void fsnotify_move(struct inode *, struct inode *, const char *, bool,
                  struct inode *, struct dentry *);