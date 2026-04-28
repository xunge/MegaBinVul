#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

struct dentry {
    struct dentry *d_parent;
    struct inode *d_inode;
    struct {
        const char *name;
        unsigned int len;
    } d_name;
};

struct inode;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define I_MUTEX_PARENT 1
#define ESTALE 116

static inline void inode_lock_nested(struct inode *inode, int subclass) {}
static inline void inode_unlock(struct inode *inode) {}
static inline struct dentry *lookup_one_len(const char *name, struct dentry *parent, int len) { return NULL; }
static inline int vfs_rmdir(struct inode *dir, struct dentry *dentry) { return 0; }
static inline int vfs_unlink(struct inode *dir, struct dentry *dentry, void *arg) { return 0; }
static inline void dput(struct dentry *dentry) {}
static inline void d_drop(struct dentry *dentry) {}
static inline struct dentry *ovl_dentry_upper(struct dentry *dentry) { return NULL; }
static inline void ovl_dentry_version_inc(struct dentry *dentry) {}