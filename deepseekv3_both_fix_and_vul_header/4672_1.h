#include <stdbool.h>
#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct dentry;
struct user_namespace;

struct mnt_namespace {
    struct user_namespace *user_ns;
};

struct mount {
    struct mount *mnt_master;
    struct mount *mnt_parent;
    struct {
        struct dentry *mnt_root;
        int mnt_flags;
    } mnt;
    struct mnt_namespace *mnt_ns;
    struct hlist_node mnt_hash;
    struct dentry *m_dentry;
};

struct seqlock {
    unsigned sequence;
};

#define IS_MNT_NEW(m) (0)
#define IS_MNT_MARKED(m) (0)
#define IS_MNT_SHARED(m) (0)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define CL_MAKE_SHARED (1 << 0)
#define CL_SLAVE (1 << 1)
#define CL_UNPRIVILEGED (1 << 2)
#define MNT_LOCKED (1 << 3)

static struct mount *last_dest;
static struct mount *last_source;
static struct mount *dest_master;
static struct mount *first_source;
static struct mount *mp;
static struct hlist_head *list;
static struct user_namespace *user_ns;
static struct seqlock mount_lock;

static bool is_subdir(struct dentry *d1, struct dentry *d2) { return false; }
static bool peers(struct mount *m1, struct mount *m2) { return false; }
static struct mount *copy_tree(struct mount *m, struct dentry *d, int type) { return NULL; }
static void mnt_set_mountpoint(struct mount *m1, struct mount *m2, struct mount *m3) {}
static void SET_MNT_MARK(struct mount *m) {}
static void read_seqlock_excl(struct seqlock *sl) {}
static void read_sequnlock_excl(struct seqlock *sl) {}
static void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {}