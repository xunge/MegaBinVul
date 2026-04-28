#include <stddef.h>
#include <errno.h>

struct net_device;
struct sock {
    void *sk_socket;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

typedef struct ax25_dev {
    struct net_device *dev;
    void *dev_tracker;
} ax25_dev;

typedef struct ax25_cb {
    struct ax25_dev *ax25_dev;
    struct sock *sk;
    struct hlist_node ax25_node;
} ax25_cb;

typedef struct {
    int dummy;
} spinlock_t;

extern spinlock_t ax25_list_lock;
extern struct hlist_head ax25_list;

#define ax25_for_each(s, list) \
    for (s = NULL; s != NULL; )

void spin_lock_bh(spinlock_t *lock);
void spin_unlock_bh(spinlock_t *lock);
void sock_hold(struct sock *sk);
void sock_put(struct sock *sk);
void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
void dev_put_track(struct net_device *dev, void *dev_tracker);
void ax25_dev_put(ax25_dev *ax25_dev);
void ax25_disconnect(ax25_cb *s, int err);
ax25_dev *ax25_dev_ax25dev(struct net_device *dev);