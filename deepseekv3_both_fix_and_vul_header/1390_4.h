#include <stddef.h>
#include <errno.h>

struct net_device;
struct sock;

typedef struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
} hlist_node;

typedef struct ax25_dev {
    int dummy;
} ax25_dev;

typedef struct ax25_cb {
    struct ax25_dev *ax25_dev;
    struct sock *sk;
    struct hlist_node ax25_node;
} ax25_cb;

typedef struct {
    int dummy;
} spinlock_t;

struct hlist_head {
    struct hlist_node *first;
};

extern ax25_dev *ax25_dev_ax25dev(struct net_device *dev);
extern void ax25_disconnect(ax25_cb *s, int err);
extern void spin_lock_bh(spinlock_t *lock);
extern void spin_unlock_bh(spinlock_t *lock);
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);

extern spinlock_t ax25_list_lock;
extern struct hlist_head ax25_list;

#define ax25_for_each(s, list) \
    for (hlist_node *node = (list)->first; node && ({ \
        s = container_of(node, ax25_cb, ax25_node); 1; \
    }); node = node->next)

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))