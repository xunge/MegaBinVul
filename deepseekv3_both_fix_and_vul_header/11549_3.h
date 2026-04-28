#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>

typedef unsigned short umode_t;

struct ovl_entry;
struct inode {
    void *i_private;
    umode_t i_mode;
    unsigned int i_uid;
    unsigned int i_gid;
    struct super_block *i_sb;
};
struct dentry;
struct path {
    struct dentry *dentry;
    void *mnt;
};
struct kstat {
    umode_t mode;
    unsigned int uid;
    unsigned int gid;
};
struct cred;
struct super_block;
struct vfsmount;

#define MAY_NOT_BLOCK 0x00000001
#define MAY_WRITE 0x00000002
#define IS_RDONLY(inode) ((inode)->i_mode & 040000)
#define ECHILD 10
#define ESTALE 116
#define ENOENT 2
#define EROFS 30

extern struct dentry *ovl_entry_real(struct ovl_entry *oe, bool *is_upper);
extern bool ovl_is_default_permissions(struct inode *inode);
extern struct vfsmount *ovl_entry_mnt_real(struct ovl_entry *oe, struct inode *inode, bool is_upper);
extern int vfs_getattr(const struct path *, struct kstat *);
extern int generic_permission(struct inode *, int);
extern struct inode *d_inode_rcu(const struct dentry *);
extern const struct cred *ovl_override_creds(struct super_block *);
extern void revert_creds(const struct cred *);
extern int __inode_permission(struct inode *, int);
extern void WARN_ON(bool condition);