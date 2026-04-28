#include <stdbool.h>
#include <pthread.h>

struct dentry {
    struct inode *d_inode;
};

struct inode {
    pthread_mutex_t i_mutex;
};

struct iattr;

int ovl_want_write(struct dentry *dentry);
struct dentry *ovl_dentry_upper(struct dentry *dentry);
int notify_change(struct dentry *, struct iattr *, struct inode **);
int ovl_copy_up_last(struct dentry *dentry, struct iattr *attr, bool);
void ovl_drop_write(struct dentry *dentry);