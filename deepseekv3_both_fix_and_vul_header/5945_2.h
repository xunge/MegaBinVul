#include <stdatomic.h>
#include <stddef.h>

#define __net_init

struct list_head {
    struct list_head *next, *prev;
};

struct net {
    atomic_int count;
#ifdef NETNS_REFCNT_DEBUG
    atomic_int use_count;
#endif
};

struct pernet_operations {
    int (*init)(struct net *net);
    void (*exit)(struct net *net);
    struct list_head list;
};

extern struct list_head pernet_list;
extern struct pernet_operations *first_device;

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); pos != (typeof(pos))(head); pos = (typeof(pos))(pos->member.next))

#define list_for_each_entry_continue_reverse(pos, head, member) \
    for (pos = (typeof(pos))(pos->member.prev); pos != (typeof(pos))(head); pos = (typeof(pos))(pos->member.prev))

#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void rcu_barrier(void) {}
static inline void rtnl_lock(void) {}
static inline void rtnl_unlock(void) {}
static inline void unregister_netdevices(struct net *net, struct list_head *list) {}
static inline void unregister_netdevice_many(struct list_head *list) {}