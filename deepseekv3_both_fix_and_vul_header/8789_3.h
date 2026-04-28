#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((char *)((head)->next) - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(pos))((char *)(pos->member.next) - offsetof(typeof(*pos), member)))

#define list_add_tail(new, head) do { \
    (new)->next = (head); \
    (new)->prev = (head)->prev; \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

#define list_splice(list, head) do { \
    (list)->next->prev = (head); \
    (head)->next = (list)->next; \
} while (0)

#define BUG_ON(condition) ((void)0)

struct mount {
    struct mount *mnt_parent;
    struct list_head mnt_list;
    struct mnt_namespace *mnt_ns;
};

struct mnt_namespace {
    struct list_head list;
    unsigned int mounts;
    unsigned int pending_mounts;
};

void attach_shadowed(struct mount *mnt, struct mount *parent, struct mount *shadows);
void touch_mnt_namespace(struct mnt_namespace *n);