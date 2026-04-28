#include <stddef.h>
#include <errno.h>

struct qstr;
struct dentry;
struct nameidata;
struct inode;

struct dentry {
    struct inode *d_inode;
    struct dentry_operations *d_op;
};

struct inode {
    struct inode_operations *i_op;
};

struct dentry_operations {
    int (*d_hash)(struct dentry *, struct qstr *);
};

struct inode_operations {
    struct dentry *(*lookup)(struct inode *, struct dentry *, struct nameidata *);
};

static struct dentry *cached_lookup(struct dentry *base, struct qstr *name, struct nameidata *nd);
static struct dentry *d_alloc(struct dentry *parent, struct qstr *name);
static void dput(struct dentry *dentry);

#define IS_DEADDIR(inode) (0)
#define ERR_PTR(err) ((void *)(long)(err))