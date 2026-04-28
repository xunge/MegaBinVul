#include <stddef.h>

struct dentry;
struct mountpoint;
struct mount;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct list_head {
    struct list_head *next, *prev;
};

#define MNT_UMOUNT 0x00000001

extern void namespace_lock(void);
extern void namespace_unlock(void);
extern struct mountpoint *lookup_mountpoint(struct dentry *dentry);
extern void lock_mount_hash(void);
extern void unlock_mount_hash(void);
extern void put_mountpoint(struct mountpoint *mp);
extern void umount_tree(struct mount *mnt, int flags);
extern void umount_mnt(struct mount *mnt);
extern int hlist_empty(const struct hlist_head *h);
extern void hlist_add_head(struct hlist_node *n, struct hlist_head *h);

#define hlist_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = hlist_entry((head)->next, typeof(*pos), member), \
        n = hlist_entry(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = hlist_entry(n->member.next, typeof(*n), member))

struct mount {
    struct {
        unsigned int mnt_flags;
    } mnt;
    struct hlist_node mnt_mp_list;
    struct list_head mnt_mounts;
    struct list_head mnt_child;
    struct {
        struct hlist_node s_list;
    } mnt_umount;
};

struct mountpoint {
    struct hlist_head m_list;
};

struct hlist_head unmounted = { NULL };