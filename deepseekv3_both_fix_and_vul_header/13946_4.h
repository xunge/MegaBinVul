#include <string.h>
#include <stddef.h>

struct qstr {
    const char *name;
};

struct dentry {
    struct qstr d_name;
    struct inode *d_inode;
};

struct inode;

struct name_snapshot {
    const char *name;
};

void take_dentry_name_snapshot(struct name_snapshot *name, struct dentry *dentry);
void release_dentry_name_snapshot(struct name_snapshot *name);
struct dentry *lock_rename(struct dentry *new_dir, struct dentry *old_dir);
void unlock_rename(struct dentry *new_dir, struct dentry *old_dir);
int d_really_is_negative(const struct dentry *dentry);
int d_mountpoint(const struct dentry *dentry);
int d_is_dir(const struct dentry *dentry);
int d_really_is_positive(const struct dentry *dentry);
struct dentry *lookup_one_len(const char *name, struct dentry *base, int len);
int simple_rename(struct inode *old_dir, struct dentry *old_dentry,
                 struct inode *new_dir, struct dentry *new_dentry,
                 unsigned int flags);
void d_move(struct dentry *old_dentry, struct dentry *new_dentry);
void dput(struct dentry *dentry);
struct inode *d_inode(const struct dentry *dentry);
const char *fsnotify_oldname_init(const char *name);
void fsnotify_oldname_free(const char *old_name);
void fsnotify_move(struct inode *old_dir, struct inode *new_dir,
                  const char *old_name, int is_dir, void *arg1, void *arg2);
int IS_ERR(const void *ptr);