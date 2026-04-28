#include <stddef.h>

struct dentry;
struct vfsmount {
    struct dentry *mnt_root;
};

struct list_head {
    struct list_head *next, *prev;
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct user_namespace;

struct mount {
    struct vfsmount mnt;
    struct mnt_namespace *mnt_ns;
    struct list_head mnt_list;
};

struct fs_struct {
    struct path root;
    struct path pwd;
};

struct mnt_namespace {
    struct mount *root;
    struct list_head list;
    struct user_namespace *user_ns;
    unsigned int mounts;
};

#define BUG_ON(condition) ((void)0)
#define likely(x) (x)
#define IS_ERR(x) (0)
#define ERR_CAST(x) ((void *)(x))
#define CLONE_NEWNS (0x00020000)
#define CL_COPY_UNBINDABLE (0x01)
#define CL_EXPIRE (0x02)
#define CL_SHARED_TO_SLAVE (0x04)
#define CL_UNPRIVILEGED (0x08)

static inline void get_mnt_ns(struct mnt_namespace *ns) {}
static inline struct mnt_namespace *alloc_mnt_ns(struct user_namespace *user_ns) { return NULL; }
static inline void namespace_lock() {}
static inline void namespace_unlock() {}
static inline void free_mnt_ns(struct mnt_namespace *ns) {}
static inline struct mount *copy_tree(struct mount *old, struct dentry *root, int flags) { return NULL; }
static inline struct mount *next_mnt(struct mount *p, struct mount *root) { return NULL; }
static inline struct vfsmount *mntget(struct vfsmount *mnt) { return NULL; }
static inline void mntput(struct vfsmount *mnt) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}