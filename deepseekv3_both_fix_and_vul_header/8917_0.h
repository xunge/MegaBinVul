#include <stdbool.h>

struct inode {
    // 基本inode结构
};

struct dentry {
    struct dentry *d_parent;
    struct inode *d_inode;
    unsigned int d_seq;
    // 其他dentry字段
};

struct vfsmount {
    struct dentry *mnt_root;
    struct mount *mnt;
    // 其他vfsmount字段
};

struct mount {
    struct mount *mnt_parent;
    struct dentry *mnt_mountpoint;
    struct vfsmount mnt;
    // 其他mount字段
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct nameidata {
    struct path path;
    struct path root;
    struct inode *inode;
    unsigned seq;
    unsigned m_seq;
};

typedef struct {
    unsigned sequence;
} seqlock_t;

static seqlock_t mount_lock;

#define unlikely(x) (x)
#define ECHILD 10
#define ENOENT 2

static void set_root_rcu(struct nameidata *nd);
static bool path_equal(const struct path *path1, const struct path *path2);
static struct mount *real_mount(struct vfsmount *mnt);
static bool d_mountpoint(const struct dentry *dentry);
static struct mount *__lookup_mnt(struct vfsmount *mnt, struct dentry *dentry);
static unsigned read_seqcount_begin(const unsigned int *s);
static bool read_seqcount_retry(const unsigned int *s, unsigned start);
static bool read_seqretry(const seqlock_t *sl, unsigned start);
static bool path_connected(const struct path *path);