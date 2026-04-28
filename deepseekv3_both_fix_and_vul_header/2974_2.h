#include <stddef.h>
#include <stdbool.h>

struct mount;
struct dentry;
struct user_namespace;
struct list_head {
    struct list_head *next, *prev;
};
struct nsproxy;
struct vfsmount {
    struct dentry *mnt_root;
};

#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }
#define IS_MNT_NEW(m) (0)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define CL_UNPRIVILEGED (0)

extern struct mount *propagation_next(struct mount *m, struct mount *origin);
extern struct mount *get_source(struct mount *m, struct mount *dest_mnt, struct mount *src_mnt, int *type);
extern struct mount *copy_tree(struct mount *mnt, struct dentry *dentry, int type);
extern bool is_subdir(struct dentry *new_dentry, struct dentry *old_dentry);
extern void mnt_set_mountpoint(struct mount *mnt, struct dentry *dentry, struct mount *child_mnt);
extern void umount_tree(struct mount *mnt, int how, struct list_head *umounts);
extern void release_mounts(struct list_head *head);
extern void br_write_lock(void *lock);
extern void br_write_unlock(void *lock);
extern void list_splice(struct list_head *list, struct list_head *head);
extern void list_add_tail(struct list_head *new, struct list_head *head);
extern int list_empty(const struct list_head *head);
#define list_first_entry(ptr, type, member) \
    ((type *)((char *)(ptr)->next - offsetof(type, member)))

struct task_struct {
    struct nsproxy *nsproxy;
};
extern struct task_struct *current;

struct nsproxy {
    struct mnt_namespace *mnt_ns;
};

struct mnt_namespace {
    struct user_namespace *user_ns;
};

struct mount {
    struct mnt_namespace *mnt_ns;
    struct dentry *mnt_root;
    struct list_head mnt_hash;
    struct vfsmount mnt;
};

void *vfsmount_lock;