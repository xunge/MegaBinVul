#include <stdio.h>
#include <errno.h>

#define KERN_WARNING ""
#define __func__ ""

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    struct super_operations *s_cop;
};

struct super_operations {
    int (*empty_dir)(struct inode *);
};

struct fscrypt_policy {
    int version;
};

#define EINVAL 22
#define EOPNOTSUPP 95
#define ENOTEMPTY 39