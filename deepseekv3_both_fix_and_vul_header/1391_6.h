#include <stddef.h>

struct net_device;
struct sock;

typedef struct ax25_dev {
    struct net_device *dev;
    void *dev_tracker;
} ax25_dev;

typedef struct ax25_cb {
    struct ax25_dev *ax25_dev;
    struct sock *sk;
    struct ax25_cb *next;
} ax25_cb;

typedef struct {
    int dummy;
} spinlock_t;

extern spinlock_t ax25_list_lock;
extern struct ax25_cb *ax25_list;

#define ax25_for_each(s, list) \
    for (s = *(list); s != NULL; s = s->next)

extern struct ax25_dev *ax25_dev_ax25dev(struct net_device *dev);
extern void ax25_dev_put(struct ax25_dev *ax25_dev);
extern void ax25_disconnect(struct ax25_cb *s, int err);
extern void spin_lock_bh(spinlock_t *lock);
extern void spin_unlock_bh(spinlock_t *lock);
extern void sock_hold(struct sock *sk);
extern void sock_put(struct sock *sk);
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);
extern void dev_put_track(struct net_device *dev, void *tracker);

#define ENETUNREACH 101