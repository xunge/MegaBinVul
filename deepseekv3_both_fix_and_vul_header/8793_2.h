#include <stdbool.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct dentry;
struct user_namespace;
struct mount_ns {
    struct user_namespace *user_ns;
};

struct mountpoint {
    struct dentry *m_dentry;
};

struct mount {
    struct mount *mnt_master;
    struct mount *mnt_parent;
    struct {
        struct dentry *mnt_root;
        int mnt_flags;
    } mnt;
    struct hlist_node mnt_hash;
    struct mount_ns *mnt_ns;
};

struct mount *last_dest;
struct mount *last_source;
struct mount *first_source;
struct mount *dest_master;
struct hlist_head *list;
struct user_namespace *user_ns;
struct mountpoint *mp;
int mount_lock;

#define IS_MNT_NEW(m) (0)
#define IS_MNT_MARKED(m) (0)
#define IS_MNT_SHARED(m) (0)
#define CL_MAKE_SHARED (0)
#define CL_SLAVE (0)
#define CL_UNPRIVILEGED (0)
#define MNT_LOCKED (0)
#define PTR_ERR(p) (0)
#define IS_ERR(p) (0)

bool is_subdir(struct dentry *d1, struct dentry *d2) { return false; }
bool peers(struct mount *m1, struct mount *m2) { return false; }
struct mount *copy_tree(struct mount *m, struct dentry *d, int type) { return 0; }
void mnt_set_mountpoint(struct mount *m1, struct mountpoint *mp, struct mount *m2) {}
void read_seqlock_excl(int *lock) {}
void read_sequnlock_excl(int *lock) {}
void SET_MNT_MARK(struct mount *m) {}
void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {}