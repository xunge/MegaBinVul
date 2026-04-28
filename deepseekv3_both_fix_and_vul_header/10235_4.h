#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>

#define OVERLAYFS_SUPER_MAGIC 0x794c7630
#define FILESYSTEM_MAX_STACK_DEPTH 2
#define MS_RDONLY 1
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define MNT_READONLY 1
#define OVL_WORKDIR_NAME "work"

typedef unsigned int gfp_t;
typedef unsigned short umode_t;

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct ovl_config {
    char *lowerdir;
    char *upperdir;
    char *workdir;
};

struct ovl_entry {
    struct dentry *__upperdentry;
    struct dentry *lowerdentry;
};

struct ovl_fs {
    struct ovl_config config;
    struct vfsmount *upper_mnt;
    struct vfsmount *lower_mnt;
    struct dentry *workdir;
    unsigned int lower_namelen;
};

struct super_block {
    unsigned long s_magic;
    const struct super_operations *s_op;
    struct dentry *s_root;
    void *s_fs_info;
    unsigned int s_stack_depth;
    unsigned long s_flags;
    const struct dentry_operations *s_d_op;
};

struct inode {
    umode_t i_mode;
};

struct dentry {
    struct inode *d_inode;
    void *d_fsdata;
    const struct dentry_operations *d_op;
};

struct vfsmount {
    struct super_block *mnt_sb;
    unsigned int mnt_flags;
};

struct kstatfs {
    unsigned long f_namelen;
};

struct super_operations {};
struct dentry_operations {};
extern const struct dentry_operations ovl_dentry_operations;
extern const struct super_operations ovl_super_operations;

static void pr_err(const char *fmt, ...) {}
static long PTR_ERR(const void *ptr) { return 0; }
static bool IS_ERR(const void *ptr) { return false; }

static struct ovl_entry *ovl_alloc_entry(void) { return NULL; }
static int ovl_parse_opt(char *data, struct ovl_config *config) { return 0; }
static int ovl_mount_dir(const char *name, struct path *path) { return 0; }
static bool ovl_workdir_ok(struct dentry *dentry, struct dentry *upperdentry) { return false; }
static bool ovl_is_allowed_fs_type(struct dentry *dentry) { return false; }
static struct inode *ovl_new_inode(struct super_block *sb, umode_t mode, struct ovl_entry *oe) { return NULL; }
static struct dentry *d_make_root(struct inode *root_inode) { return NULL; }
static struct dentry *ovl_workdir_create(struct vfsmount *mnt, struct dentry *dentry) { return NULL; }
static struct vfsmount *clone_private_mount(struct path *path) { return NULL; }
static void mntput(struct vfsmount *mnt) {}
static void path_put(struct path *path) {}
static void dput(struct dentry *dentry) {}
static int vfs_statfs(struct path *path, struct kstatfs *buf) { return 0; }
static void kfree(const void *objp) {}
static void *kzalloc(size_t size, gfp_t flags) { return NULL; }
static int max(int a, int b) { return a > b ? a : b; }

const struct dentry_operations ovl_dentry_operations = {};
const struct super_operations ovl_super_operations = {};