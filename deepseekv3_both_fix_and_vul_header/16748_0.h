#include <stddef.h>

struct xattr_handler;
struct dentry;
struct inode;

#define EIO 5

static int fuse_is_bad(struct inode *inode);
static int fuse_removexattr(struct inode *inode, const char *name);
static int fuse_setxattr(struct inode *inode, const char *name, const void *value, size_t size, int flags);