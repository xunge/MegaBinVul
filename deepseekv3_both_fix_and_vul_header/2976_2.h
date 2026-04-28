#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct vfsmount {
    // Minimal definition to make it compile
    void *mnt_root;
};

struct mnt_namespace {
    struct mount *root;
    struct user_namespace *user_ns;
    struct list_head list;
};

struct mount {
    struct vfsmount mnt;
    struct mnt_namespace *mnt_ns;
    struct list_head mnt_list;
};

struct fs_struct {
    struct {
        struct vfsmount *mnt;
    } root, pwd;
};

struct user_namespace;

#define CL_COPY_ALL 1
#define CL_EXPIRE 2
#define CL_SHARED_TO_SLAVE 4
#define CL_UNPRIVILEGED 8

extern struct mnt_namespace *alloc_mnt_ns(struct user_namespace *user_ns);
extern void free_mnt_ns(struct mnt_namespace *ns);
extern struct mount *copy_tree(struct mount *old, void *root, int flags);
extern struct mount *next_mnt(struct mount *p, struct mount *root);
extern void mntput(struct vfsmount *mnt);
extern struct vfsmount *mntget(struct vfsmount *mnt);
extern void *ERR_CAST(void *ptr);
extern int IS_ERR(const void *ptr);

extern void down_write(void *sem);
extern void up_write(void *sem);
extern void br_write_lock(void *lock);
extern void br_write_unlock(void *lock);
extern void list_add_tail(struct list_head *new, struct list_head *head);

extern struct rw_semaphore namespace_sem;
extern struct rwlock vfsmount_lock;