#include <sys/types.h>
#include <string.h>

#define XATTR_OS2_PREFIX "os2."
#define XATTR_OS2_PREFIX_LEN (sizeof(XATTR_OS2_PREFIX) - 1)
#define EOPNOTSUPP 95

struct dentry {
    struct inode *d_inode;
};

struct inode;

int is_known_namespace(const char *name);
ssize_t __jfs_getxattr(struct inode *inode, const char *name, void *data, size_t buf_size);