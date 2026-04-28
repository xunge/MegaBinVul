#include <stddef.h>
#include <sys/types.h>
#include <errno.h>

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
    int f_flags;
};

struct cred;

struct dentry {
    struct inode *d_inode;
    unsigned int d_flags;
    struct dentry_operations *d_op;
};

struct inode;

struct dentry_operations {
    struct inode *(*d_select_inode)(struct dentry *, int);
};

int do_dentry_open(struct file *file, struct inode *inode, void *arg, const struct cred *cred);

#define DCACHE_OP_SELECT_INODE 0x00000001
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))