#include <stdbool.h>
#include <stddef.h>

enum umount_tree_flags {
    UMOUNT_PROPAGATE,
    UMOUNT_SYNC
};

#define MNT_UMOUNT 0x00000001
#define MNT_SYNC_UMOUNT 0x00000002
#define MS_PRIVATE 0x00040000

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct vfsmount {
    unsigned int mnt_flags;
};

struct mnt_namespace {
    int mounts;
};

struct mount {
    struct list_head mnt_list;
    struct list_head mnt_child;
    struct list_head mnt_expire;
    struct list_head mnt_umount;
    struct list_head mnt_mounts;
    struct mnt_namespace *mnt_ns;
    struct mount *mnt_parent;
    struct vfsmount mnt;
};

static struct list_head unmounted = LIST_HEAD_INIT(unmounted);

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

static inline void list_move(struct list_head *list, struct list_head *head) {}
static inline void list_del_init(struct list_head *entry) {}
static inline bool list_empty(const struct list_head *head) { return true; }
static inline void __touch_mnt_namespace(struct mnt_namespace *ns) {}
static inline bool disconnect_mount(struct mount *mnt, enum umount_tree_flags how) { return false; }
static inline void pin_insert_group(struct list_head *pin, 
                                  struct vfsmount *mnt, 
                                  struct list_head *group) {}
static inline bool mnt_has_parent(struct mount *mnt) { return false; }
static inline void mnt_add_count(struct mount *mnt, int n) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void umount_mnt(struct mount *mnt) {}
static inline void change_mnt_propagation(struct mount *mnt, int type) {}
static inline void propagate_mount_unlock(struct mount *mnt) {}
static inline struct mount *next_mnt(struct mount *p, struct mount *mnt) { return NULL; }
static inline void propagate_umount(struct list_head *list) {}