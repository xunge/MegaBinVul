#include <linux/fs.h>
#include <linux/xattr.h>
#include <stddef.h>

struct dentry;
struct ecryptfs_crypt_stat;

#define ECRYPTFS_XATTR_NAME "user.ecryptfs"

extern int ecryptfs_setxattr(struct dentry *dentry, const char *name,
                             const void *value, size_t size, int flags);