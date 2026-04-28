#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

typedef unsigned int u32;
typedef unsigned long dev_t;

struct path {
    struct dentry *dentry;
};

struct dentry;

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    dev_t s_dev;
};

struct kstat {
    unsigned int result_mask;
    dev_t dev;
};

struct fuse_conn;

#define EACCES 13

static inline struct inode *d_inode(struct dentry *dentry) { return NULL; }
static inline struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static inline int fuse_allow_current_process(struct fuse_conn *fc) { return 0; }
static inline int fuse_update_get_attr(struct inode *inode, void *a, struct kstat *b, u32 c, unsigned int d) { return 0; }