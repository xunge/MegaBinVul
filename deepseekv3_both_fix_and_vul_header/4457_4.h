#include <stdbool.h>
#include <stddef.h>

enum umount_tree_flags {
    UMOUNT_PROPAGATE,
    UMOUNT_SYNC,
    UMOUNT_CONNECTED
};

#define MNT_UMOUNT 0x1
#define MNT_SYNC_UMOUNT 0x2
#define MS_PRIVATE 0x1

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

struct mnt_namespace;
struct vfsmount {
    unsigned int mnt_flags;
};

struct mount {
    struct mnt_namespace *mnt_ns;
    struct mount *mnt_parent;
    struct list_head mnt_mounts;
    struct list_head mnt_child;
    struct list_head mnt_list;
    struct list_head mnt_expire;
    struct list_head mnt_umount;
    struct vfsmount mnt;
};

static struct list_head unmounted = LIST_HEAD_INIT(unmounted);

static inline void list_move(struct list_head *list, struct list_head *head) {}
static inline void list_del_init(struct list_head *entry) {}
static inline bool list_empty(const struct list_head *head) { return true; }
static inline void __touch_mnt_namespace(struct mnt_namespace *ns) {}
static inline bool mnt_has_parent(struct mount *mnt) { return false; }
static inline void pin_insert_group(struct list_head *a, 
                                  struct vfsmount *b, 
                                  struct list_head *c) {}
static inline void mnt_add_count(struct mount *mnt, int n) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void umount_mnt(struct mount *mnt) {}
static inline void change_mnt_propagation(struct mount *mnt, int flags) {}
static inline void propagate_mount_unlock(struct mount *mnt) {}
static inline struct mount *next_mnt(struct mount *p, struct mount *mnt) { return NULL; }
static inline void propagate_umount(struct list_head *list) {}
static inline bool IS_MNT_LOCKED_AND_LAZY(struct mount *mnt) { return false; }