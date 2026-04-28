#include <string.h>
#include <stdlib.h>

struct dentry {
    struct inode *d_inode;
};

struct inode;

extern int cap_convert_nscap(struct dentry *, const void **, size_t);
extern int __vfs_setxattr_locked(struct dentry *, const char *, const void *, size_t, int, struct inode **);
extern int break_deleg_wait(struct inode **);
extern void inode_lock(struct inode *);
extern void inode_unlock(struct inode *);
extern void kfree(const void *);

#define XATTR_NAME_CAPS "security.capability"