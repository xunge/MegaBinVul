#include <stdatomic.h>
#include <stddef.h>

#define __net_init
#define NETNS_REFCNT_DEBUG

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct net {
    _Atomic int count;
#ifdef NETNS_REFCNT_DEBUG
    _Atomic int use_count;
#endif
};

struct pernet_operations {
    int (*init)(struct net *net);
    void (*exit)(struct net *net);
    struct list_head list;
};

extern struct list_head pernet_list;
extern struct list_head *first_device;

static inline void atomic_set(_Atomic int *v, int i) { *v = i; }

void rtnl_lock(void);
void rtnl_unlock(void);
void unregister_netdevices(struct net *net, struct list_head *dev_kill_list);
void unregister_netdevice_many(struct list_head *dev_kill_list);
void rcu_barrier(void);

#define list_for_each_entry(pos, head, member) /* dummy */
#define list_for_each_entry_continue_reverse(pos, head, member) /* dummy */