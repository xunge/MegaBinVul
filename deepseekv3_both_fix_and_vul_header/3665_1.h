#include <stddef.h>

struct path {
    struct dentry *dentry;
    void *mnt;
};

struct nameidata {
    struct path path;
    int last_type;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    struct inode_operations *i_op;
};

struct inode_operations {
    void *(*follow_link)(struct dentry *, struct nameidata *);
    void (*put_link)(struct dentry *, struct nameidata *, void *);
};

enum { LAST_BIND };

#define __always_inline inline
#define PTR_ERR(p) ((long)(p))
#define IS_ERR(p) ((unsigned long)(p) > (unsigned long)-1000L)

static inline void touch_atime(void *mnt, struct dentry *dentry) {}
static inline void nd_set_link(struct nameidata *nd, void *ptr) {}
static inline void path_to_nameidata(struct path *path, struct nameidata *nd) {}
static inline void dget(struct dentry *dentry) {}
static inline void mntget(void *mnt) {}
static inline char *nd_get_link(struct nameidata *nd) { return NULL; }
static inline int __vfs_follow_link(struct nameidata *nd, char *s) { return 0; }
static inline int force_reval_path(struct path *path, struct nameidata *nd) { return 0; }
static inline void path_put(struct path *path) {}