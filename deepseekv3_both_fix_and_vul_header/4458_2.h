#include <stdbool.h>

struct dentry;

struct vfsmount {
    // minimal definition needed
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct mount {
    struct vfsmount mnt;
    // minimal definition needed
};

#define EINVAL 22
#define CL_COPY_ALL 0
#define CL_PRIVATE 0

void namespace_lock(void);
void namespace_unlock(void);
struct mount *real_mount(struct vfsmount *mnt);
bool check_mnt(struct mount *mnt);
struct mount *copy_tree(struct mount *, struct dentry *, int);
struct mount *ERR_PTR(long);
long IS_ERR(const void *);
struct vfsmount *ERR_CAST(const void *);