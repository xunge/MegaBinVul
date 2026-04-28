#include <pthread.h>

struct dentry {
    struct inode *d_inode;
};

struct inode {
    pthread_mutex_t i_mutex;
};

struct iattr;

int ovl_want_write(struct dentry *dentry);
int ovl_copy_up(struct dentry *dentry);
struct dentry *ovl_dentry_upper(struct dentry *dentry);
void ovl_drop_write(struct dentry *dentry);
int notify_change(struct dentry *, struct iattr *, void **);

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}