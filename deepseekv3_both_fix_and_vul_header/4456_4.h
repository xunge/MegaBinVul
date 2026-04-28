#include <stddef.h>

struct dentry;
struct hlist_node {
    struct hlist_node *next, **pprev;
};
struct hlist_head {
    struct hlist_node *first;
};
struct list_head {
    struct list_head *next, *prev;
};
struct mount {
    struct {
        unsigned int mnt_flags;
    } mnt;
    struct hlist_node mnt_mp_list;
    struct list_head mnt_mounts;
    struct {
        struct hlist_node s_list;
    } mnt_umount;
    struct list_head mnt_child;
};
struct mountpoint {
    struct hlist_head m_list;
};

#define MNT_UMOUNT 0x00000001
#define UMOUNT_CONNECTED 0

extern void namespace_lock(void);
extern void namespace_unlock(void);
extern struct mountpoint *lookup_mountpoint(struct dentry *);
extern void lock_mount_hash(void);
extern void unlock_mount_hash(void);
extern void put_mountpoint(struct mountpoint *);
extern void umount_tree(struct mount *, int);
extern void umount_mnt(struct mount *);
extern struct hlist_head unmounted;

#define IS_ERR_OR_NULL(ptr) ((!(ptr)) || ((unsigned long)(ptr) > (unsigned long)-1000))
#define hlist_empty(ptr) (!(ptr)->first)
#define hlist_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = hlist_entry((head)->next, typeof(*pos), member), \
         n = hlist_entry(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = hlist_entry(n->member.next, typeof(*n), member))
#define hlist_add_head(n, h) do { \
    (n)->next = (h)->first; \
    if ((h)->first) (h)->first->pprev = &(n)->next; \
    (h)->first = (n); \
    (n)->pprev = &(h)->first; \
} while (0)