#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct vfsmount;

struct mnt_namespace {
    struct list_head list;
    struct mount *root;
    int mounts;
    void *user_ns;
};

struct mount {
    struct list_head mnt_list;
    struct mnt_namespace *mnt_ns;
    struct vfsmount *mnt;
};

extern void *init_user_ns;

struct mnt_namespace *alloc_mnt_ns(void *);
void mntput(struct vfsmount *);
int IS_ERR(const void *);
struct mount *real_mount(struct vfsmount *);
void list_add(struct list_head *, struct list_head *);