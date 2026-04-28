#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

struct ovl_entry {
    struct dentry *realdentry;
};

struct inode {
    unsigned short i_mode;
    void *i_private;
    unsigned int i_uid;
    unsigned int i_gid;
};

struct dentry {
    struct inode *d_inode;
    void *d_fsdata;
};

struct path {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct kstat {
    unsigned short mode;
    unsigned int uid;
    unsigned int gid;
};

struct vfsmount;

#define MAY_NOT_BLOCK 0x00000001
#define MAY_WRITE 0x00000002
#define ECHILD 10
#define ENOENT 2
#define ESTALE 116
#define EROFS 30
#define WARN_ON(condition) (condition)
#define ACCESS_ONCE(x) (x)
#define IS_RDONLY(inode) (0)

typedef unsigned short umode_t;
typedef unsigned int kuid_t;
typedef unsigned int kgid_t;

extern struct dentry *ovl_entry_real(struct ovl_entry *oe, bool *is_upper);
extern struct vfsmount *ovl_entry_mnt_real(struct ovl_entry *oe, struct inode *inode, bool is_upper);
extern bool ovl_is_default_permissions(struct inode *inode);
extern int __inode_permission(struct inode *inode, int mask);
extern int generic_permission(struct inode *inode, int mask);
extern struct dentry *d_find_any_alias(struct inode *inode);
extern void dput(struct dentry *dentry);
extern int vfs_getattr(struct path *path, struct kstat *stat);