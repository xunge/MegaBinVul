#include <stddef.h>

#define MS_REC 0
#define CAP_SYS_ADMIN 0
#define EPERM 1
#define EINVAL 2

struct nameidata {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct vfsmount {
    struct dentry *mnt_root;
};

struct rw_semaphore {
    int dummy;
};
struct rw_semaphore namespace_sem;
int vfsmount_lock;

struct vfsmount *next_mnt(struct vfsmount *m, struct vfsmount *mnt);
void change_mnt_propagation(struct vfsmount *m, int type);
int capable(int cap);
void down_write(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);
void spin_lock(int *lock);
void spin_unlock(int *lock);