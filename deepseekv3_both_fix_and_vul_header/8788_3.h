#include <stddef.h>
#include <stdbool.h>

struct hlist_head {};
struct hlist_node {};
struct vfsmount {};
struct mount {
    struct mnt_namespace *mnt_ns;
    struct mount *mnt_parent;
    struct vfsmount *mnt;
    struct hlist_node mnt_hash;
    void *mnt_mountpoint;
};
struct mountpoint {};
struct mnt_namespace {
    int pending_mounts;
};
struct path {};
struct dentry {};

#define HLIST_HEAD(name) struct hlist_head name = {}
#define IS_MNT_SHARED(mnt) (0)
#define UMOUNT_SYNC 0

static int count_mounts(struct mnt_namespace *ns, struct mount *mnt) { return 0; }
static int invent_group_ids(struct mount *mnt, bool recurse) { return 0; }
static int propagate_mnt(struct mount *dest_mnt, struct mountpoint *dest_mp,
                        struct mount *source_mnt, struct hlist_head *tree_list) { return 0; }
static void lock_mount_hash(void) {}
static void unlock_mount_hash(void) {}
static struct mount *next_mnt(struct mount *p, struct mount *root) { return NULL; }
static void set_mnt_shared(struct mount *mnt) {}
static void detach_mnt(struct mount *mnt, struct path *path) {}
static void attach_mnt(struct mount *mnt, struct mount *parent, struct mountpoint *mp) {}
static void touch_mnt_namespace(struct mnt_namespace *ns) {}
static void mnt_set_mountpoint(struct mount *mnt, struct mountpoint *mp, struct mount *child) {}
static void commit_tree(struct mount *mnt, struct mount *shadows) {}
static struct mount *__lookup_mnt_last(struct vfsmount *mnt, struct dentry *dentry) { return NULL; }
static void cleanup_group_ids(struct mount *mnt, struct mount *dead) {}
static void umount_tree(struct mount *mnt, int how) {}
#define hlist_for_each_entry_safe(pos, n, head, member) for (pos = NULL, n = NULL; 0; )
#define hlist_empty(head) (1)
#define hlist_entry(ptr, type, member) ((type *)NULL)
#define hlist_del_init(node)