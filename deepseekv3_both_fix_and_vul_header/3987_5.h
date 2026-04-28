#include <linux/netlink.h>
#include <linux/net.h>
#include <linux/socket.h>

struct net;
struct sock;
struct xfrm_state_walk;
struct netlink_callback {
    long args[5];
    struct {
        struct sock *sk;
    } *skb;
};

static inline struct net* sock_net(struct sock* sk) { return 0; }
static inline void xfrm_state_walk_done(struct xfrm_state_walk* walk, struct net* net) {}