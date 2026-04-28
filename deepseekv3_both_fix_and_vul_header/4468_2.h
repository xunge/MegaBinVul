#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define OVL_MAX_STACK 500
#define OVERLAYFS_SUPER_MAGIC 0x794c7630
#define ENOMEM 12
#define EINVAL 22
#define MAX_LFS_FILESIZE ((long long)0x7fffffffffffffff)
#define FILESYSTEM_MAX_STACK_DEPTH 2
#define OVL_WORKDIR_NAME "work"
#define S_IFDIR 0040000
#define MS_RDONLY 1
#define MNT_READONLY 0x00000040
#define GFP_KERNEL 0

struct super_block {
    unsigned long s_flags;
    unsigned int s_stack_depth;
    long long s_maxbytes;
    void *s_root;
    void *s_fs_info;
    void *s_op;
    unsigned long s_magic;
    const struct dentry_operations *s_d_op;
};

struct dentry {
    void *d_fsdata;
    void *d_inode;
};

struct vfsmount {
    unsigned long mnt_flags;
    struct super_block *mnt_sb;
};

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
    struct {
        struct dentry *dentry;
        struct vfsmount *mnt;
    } lowerstack[];
};

struct ovl_fs {
    struct vfsmount *upper_mnt;
    struct dentry *workdir;
    struct vfsmount **lower_mnt;
    unsigned int numlower;
    unsigned int lower_namelen;
    struct ovl_config config;
};

struct dentry_operations {
};

struct super_operations {
};

struct inode {
};

#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_warn(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline char *kstrdup(const char *s, int flags) { return strdup(s); }
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void kfree(void *p) { free(p); }

#define PTR_ERR(p) ((long)(p))
#define IS_ERR(p) ((unsigned long)(p) > (unsigned long)-1000L)

static inline struct vfsmount *clone_private_mount(struct path *path) { return NULL; }
static inline void mntput(struct vfsmount *mnt) {}
static inline void path_put(struct path *path) {}
static inline void dput(struct dentry *dentry) {}

extern int ovl_parse_opt(char *, struct ovl_config *);
extern int ovl_mount_dir(const char *, struct path *);
extern bool ovl_workdir_ok(struct dentry *, struct dentry *);
extern unsigned int ovl_split_lowerdirs(char *);
extern int ovl_lower_dir(const char *, struct path *, unsigned int *, unsigned int *, bool *);
extern struct dentry *ovl_workdir_create(struct vfsmount *, struct dentry *);
extern struct ovl_entry *ovl_alloc_entry(unsigned int);
extern struct inode *ovl_new_inode(struct super_block *, unsigned short, struct ovl_entry *);
extern void ovl_copyattr(struct inode *, struct inode *);
extern const struct dentry_operations ovl_dentry_operations;
extern const struct dentry_operations ovl_reval_dentry_operations;
extern const struct super_operations ovl_super_operations;
extern struct dentry *d_make_root(struct inode *);
extern struct dentry *ovl_dentry_real(struct dentry *);