#include <stdbool.h>
#include <stddef.h>

enum umount_tree_flags {
    UMOUNT_PROPAGATE,
    UMOUNT_SYNC
};

struct list_head {
    struct list_head *next, *prev;
};

struct mount {
    struct {
        unsigned long mnt_flags;
    } mnt;
    struct list_head mnt_list;
    struct list_head mnt_child;
    struct list_head mnt_expire;
    struct list_head mnt_umount;
    struct mount *mnt_parent;
    struct list_head mnt_mounts;
    void *mnt_ns;
};

struct vfsmount {
    struct mount *mnt;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))(head)->next; pos != (typeof(pos))(head); pos = (typeof(pos))(pos->member.next))

#define list_first_entry(ptr, type, member) \
    ((type *)((char *)((ptr)->next) - (unsigned long)(&((type *)0)->member)))

#define list_empty(head) ((head)->next == (head))
#define list_del_init(entry) do { (entry)->next = (entry); (entry)->prev = (entry); } while (0)
#define list_move(list, head) do { (list)->prev->next = (list)->next; (list)->next->prev = (list)->prev; \
                                 (list)->next = (head)->next; (list)->prev = (head); \
                                 (head)->next->prev = (list); (head)->next = (list); } while (0)
#define list_add_tail(new, head) do { (new)->next = (head); (new)->prev = (head)->prev; \
                                     (head)->prev->next = (new); (head)->prev = (new); } while (0)

#define IS_MNT_LOCKED_AND_LAZY(p) 0
#define MS_PRIVATE 0
#define MNT_UMOUNT 0
#define MNT_SYNC_UMOUNT 0

static struct list_head unmounted;

extern void propagate_mount_unlock(struct mount *mnt);
extern void propagate_umount(struct list_head *list);
extern struct mount *next_mnt(struct mount *p, struct mount *mnt);
extern void __touch_mnt_namespace(void *ns);
extern void pin_insert_group(struct list_head *a, struct vfsmount *b, void *c);
extern bool mnt_has_parent(struct mount *p);
extern void mnt_add_count(struct mount *p, int n);
extern void umount_mnt(struct mount *p);
extern void change_mnt_propagation(struct mount *p, int flags);