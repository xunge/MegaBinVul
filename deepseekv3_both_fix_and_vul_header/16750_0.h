#include <stddef.h>
#include <errno.h>

struct xattr_handler;
struct dentry;
struct inode;

#define EIO 5

static inline int fuse_is_bad(struct inode *inode) { return 0; }
static inline int fuse_getxattr(struct inode *inode, const char *name, void *value, size_t size) { return 0; }