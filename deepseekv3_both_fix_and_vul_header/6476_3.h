struct net;
struct sock;

struct xfrm_policy_walk {
    // 占位结构体定义
};

struct netlink_callback {
    long args[2];
    struct sk_buff *skb;
};

struct sk_buff {
    struct sock *sk;
};

int sock_net(struct sock *sk);
void xfrm_policy_walk_done(struct xfrm_policy_walk *walk, struct net *net);