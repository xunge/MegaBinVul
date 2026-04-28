#include <stdbool.h>

struct vfsmount {
    int dummy;
};

struct dentry {
    int dummy;
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct mount {
    struct vfsmount mnt;
    void *mnt_ns;
};

#define MNT_NS_INTERNAL ((void *)1)
#define CL_PRIVATE 0
#define EINVAL 22

extern int namespace_sem;

static inline struct mount *real_mount(struct vfsmount *mnt)
{
    return (struct mount *)mnt;
}

static inline bool IS_MNT_UNBINDABLE(struct mount *mnt)
{
    return false;
}

static inline bool check_mnt(struct mount *mnt)
{
    return true;
}

static inline bool has_locked_children(struct mount *mnt, struct dentry *dentry)
{
    return false;
}

static inline struct mount *clone_mnt(struct mount *old_mnt, struct dentry *dentry, int flags)
{
    return (struct mount *)0;
}

static inline void down_read(int *sem) {}
static inline void up_read(int *sem) {}

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_CAST(x) ((struct vfsmount *)x)
#define ERR_PTR(x) ((void *)(long)(x))