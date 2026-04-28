#include <stddef.h>

struct inode {
    struct inode_operations *i_op;
};

struct dentry {
    struct inode *d_inode;
};

struct inode_operations {
    int (*removexattr)(struct dentry *, const char *);
};

struct evm_ima_xattr_data {
    int type;
    char digest[64];
};

#define EVM_XATTR_HMAC 2
#define XATTR_NAME_EVM "security.evm"
#define ENODATA 61

int evm_calc_hmac(struct dentry *dentry, const char *xattr_name,
                 const char *xattr_value, size_t xattr_value_len,
                 char *digest);

int __vfs_setxattr_noperm(struct dentry *dentry, const char *name,
                         const void *value, size_t size, int flags);