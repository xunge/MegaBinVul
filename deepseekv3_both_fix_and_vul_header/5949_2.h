#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct net {
    // minimal definition
};

struct pernet_operations {
    struct list_head list;
    int *id;
    void (*exit)(struct net *net);
};

extern struct net init_net;
extern void __unregister_pernet_operations(struct pernet_operations *ops);
extern void ida_remove(void *ids, int id);
extern void list_del(struct list_head *entry);
extern int net_generic_ids;

#define for_each_net(net) \
    for ((net) = &init_net; (net) != NULL; (net) = NULL)