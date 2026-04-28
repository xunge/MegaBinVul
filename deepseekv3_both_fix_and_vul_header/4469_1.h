#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define XATTR_SIZE_MAX 65536
#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define ENOMEM 12
#define ERANGE 34

struct dentry {
    struct inode *d_inode;
};

struct inode {
    struct inode_operations *i_op;
};

struct inode_operations {
    int (*getxattr)(void);
};

void *kzalloc(size_t size, int flags);
void *kmalloc(size_t size, int flags);
void *krealloc(void *ptr, size_t size, int flags);
void kfree(void *ptr);
ssize_t vfs_listxattr(struct dentry *dentry, char *list, size_t size);
ssize_t vfs_getxattr(struct dentry *dentry, const char *name, void *value, size_t size);
int vfs_setxattr(struct dentry *dentry, const char *name, const void *value, size_t size, int flags);

#define uninitialized_var(x) x = x