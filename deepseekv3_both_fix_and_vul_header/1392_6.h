#include <stddef.h>
#include <errno.h>

typedef struct spinlock {
    int dummy;
} spinlock_t;

typedef struct hlist_node {
    struct hlist_node *next, **pprev;
} hlist_node;

typedef struct hlist_head {
    struct hlist_node *first;
} hlist_head;

typedef struct ax25_dev {
    struct net_device *dev;
} ax25_dev;

typedef struct ax25_cb {
    struct ax25_dev *ax25_dev;
    struct sock *sk;
    struct hlist_node node;
} ax25_cb;

struct net_device;
struct sock;

#define ax25_for_each(s, list) \
    for ((s) = (ax25_cb *)(list)->first; (s); (s) = (ax25_cb *)((hlist_node *)(s))->next)

#define ENETUNREACH 101

extern spinlock_t ax25_list_lock;
extern hlist_head ax25_list;
extern ax25_dev *ax25_dev_ax25dev(struct net_device *dev);
extern void ax25_dev_put(ax25_dev *);
extern void ax25_disconnect(ax25_cb *, int);
extern void spin_lock_bh(spinlock_t *);
extern void spin_unlock_bh(spinlock_t *);
extern void sock_hold(struct sock *);
extern void sock_put(struct sock *);
extern void lock_sock(struct sock *);
extern void release_sock(struct sock *);