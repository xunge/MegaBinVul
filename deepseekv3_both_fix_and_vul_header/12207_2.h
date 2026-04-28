#include <stddef.h>

struct net;
struct nft_elem_priv;
struct list_head {
    struct list_head *next, *prev;
};
struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};
struct nft_set_elem_catchall {
    struct nft_elem_priv *elem;
    struct list_head list;
    struct rcu_head rcu;
};
struct nft_set {
    struct list_head catchall_list;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (void *)(head); pos = n)
#define list_del_rcu(list) ((void)0)
#define kfree_rcu(ptr, field) ((void)0)