#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef unsigned int umode_t;

struct mutex {
    int dummy;
};

struct dentry {
    struct inode *d_inode;
    struct {
        const char *name;
        unsigned int len;
    } d_name;
};

struct inode {
    struct mutex i_mutex;
};

struct path {
    struct dentry *dentry;
};

struct kstat {
    umode_t mode;
    long long size;
};

struct iattr;

#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void dput(struct dentry *dentry) {}
static inline int notify_change(struct dentry *dentry, struct iattr *attr, void *unused) { return 0; }
static inline void BUG_ON(int condition) {}

static struct dentry *lookup_one_len(const char *name, struct dentry *parent, unsigned len) { return NULL; }
static struct dentry *ovl_lookup_temp(struct dentry *workdir, struct dentry *dentry) { return NULL; }
static int ovl_create_real(struct inode *dir, struct dentry *newdentry, struct kstat *stat,
                          const char *link, struct dentry *hardlink, bool tmpfile) { return 0; }
static void ovl_path_upper(struct dentry *dentry, struct path *upperpath) {}
static int ovl_copy_up_data(struct path *lowerpath, struct path *upperpath, long long len) { return 0; }
static int ovl_copy_xattr(struct dentry *old, struct dentry *new) { return 0; }
static int ovl_set_attr(struct dentry *dentry, struct kstat *stat) { return 0; }
static int ovl_do_rename(struct inode *olddir, struct dentry *olddentry,
                        struct inode *newdir, struct dentry *newdentry,
                        unsigned int flags) { return 0; }
static void ovl_dentry_update(struct dentry *dentry, struct dentry *upperdentry) {}
static void ovl_dentry_set_opaque(struct dentry *dentry, bool opaque) {}
static void ovl_cleanup(struct inode *dir, struct dentry *dentry) {}