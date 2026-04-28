#include <stddef.h>
#include <stdbool.h>

struct dentry;
struct inode;
struct user_namespace;

struct path {
    struct dentry *dentry;
};

struct mount_info {
    struct path mi_backing_dir_path;
    struct dentry *mi_index_dir;
    struct dentry *mi_incomplete_dir;
    bool mi_index_free;
    bool mi_incomplete_free;
};

struct super_block {
    void *s_fs_info;
};

extern struct user_namespace init_user_ns;
extern void incfs_free_mount_info(struct mount_info *mi);
extern void kill_anon_super(struct super_block *sb);
extern int vfs_rmdir(struct user_namespace *, struct inode *, struct dentry *);
extern struct inode *d_inode(const struct dentry *);
extern int pr_debug(const char *fmt, ...);