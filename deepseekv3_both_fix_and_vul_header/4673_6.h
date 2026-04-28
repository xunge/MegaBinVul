#include <stddef.h>

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct mount {
    struct mount *mnt_master;
    struct mount *mnt_parent;
    struct hlist_node mnt_hash;
};

struct mountpoint {
};

struct hlist_head {
    struct hlist_node *first;
};

struct user_namespace {
};

struct task_struct {
    struct nsproxy *nsproxy;
};

struct nsproxy {
    struct mnt_namespace *mnt_ns;
};

struct mnt_namespace {
    struct user_namespace *user_ns;
};

struct seqcount {
    unsigned sequence;
};

struct mount_lock {
    struct seqcount seqcount;
};

extern struct task_struct *current;
extern struct mount *last_dest;
extern struct mount *last_source;
extern struct mount *first_source;
extern struct mountpoint *mp;
extern struct hlist_head *list;
extern struct mount *dest_master;
extern struct user_namespace *user_ns;
extern struct mount_lock mount_lock;

#define CLEAR_MNT_MARK(m) ((void)0)
#define hlist_for_each_entry(pos, head, member) \
    for (pos = (head)->first ? (typeof(*pos)*)((char*)((head)->first) - offsetof(typeof(*pos), member)) : NULL; \
         pos; \
         pos = pos->member.next ? (typeof(*pos)*)((char*)(pos->member.next) - offsetof(typeof(*pos), member)) : NULL)

struct mount *next_peer(struct mount *m);
struct mount *next_group(struct mount *m, struct mount *origin);
int propagate_one(struct mount *m);
void read_seqlock_excl(struct mount_lock *lock);
void read_sequnlock_excl(struct mount_lock *lock);