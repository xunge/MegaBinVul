#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct pernet_operations {
    int *id;
    struct list_head list;
    int (*init)(struct net *);
    void (*exit)(struct net *);
};

struct net;

extern struct {
    int dummy;
} net_generic_ids;

#define GFP_KERNEL 0
#define EAGAIN 11

int ida_get_new_above(void *ida, int min, int *id);
void ida_pre_get(void *ida, int flags);
void ida_remove(void *ida, int id);
int __register_pernet_operations(struct list_head *list, struct pernet_operations *ops);
void list_add_tail(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);
#define for_each_net(net) for (net = NULL; 0; )
int net_eq(struct net *net1, struct net *net2);