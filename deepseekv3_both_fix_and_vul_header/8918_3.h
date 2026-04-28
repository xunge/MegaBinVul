#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

#define unlikely(x) (x)

struct inode;

struct dentry {
    struct inode *d_inode;
};

struct vfsmount {
    struct dentry *mnt_root;
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct nameidata {
    struct path path;
    struct path root;
    struct inode *inode;
};

static inline void dput(struct dentry *dentry) {}
static inline struct dentry *dget_parent(struct dentry *dentry) { return NULL; }
static inline bool path_connected(const struct path *path) { return false; }
static inline bool follow_up(struct path *path) { return false; }
static inline void follow_mount(struct path *path) {}
static inline void set_root(struct nameidata *nd) {}