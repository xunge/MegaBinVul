#include <sys/socket.h>

struct l2cap_chan;
struct l2cap_pi {
    struct l2cap_chan *chan;
};

struct socket {
    struct sock *sk;
};

struct sock;

#define BT_DBG(fmt, ...) 

static inline struct l2cap_pi *l2cap_pi(struct sock *sk) {
    return (struct l2cap_pi *)sk;
}

extern struct list_head l2cap_sk_list;
extern void bt_sock_unlink(struct list_head *list, struct sock *sk);
extern int l2cap_sock_shutdown(struct socket *sock, int how);
extern void l2cap_chan_hold(struct l2cap_chan *chan);
extern void l2cap_chan_lock(struct l2cap_chan *chan);
extern void l2cap_chan_unlock(struct l2cap_chan *chan);
extern void l2cap_chan_put(struct l2cap_chan *chan);
extern void sock_orphan(struct sock *sk);
extern void l2cap_sock_kill(struct sock *sk);