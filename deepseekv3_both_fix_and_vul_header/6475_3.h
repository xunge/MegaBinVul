#include <stddef.h>

struct sk_buff {
    void *sk;
    unsigned int len;
};

struct nlmsghdr {
    unsigned int nlmsg_seq;
    unsigned int nlmsg_flags;
};

struct netlink_callback {
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    unsigned long args[10];
};

struct net;

struct xfrm_policy_walk {
    unsigned int type;
    unsigned int seq;
};

struct xfrm_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    unsigned int nlmsg_seq;
    unsigned int nlmsg_flags;
};

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define NLM_F_MULTI 0x2
#define XFRM_POLICY_TYPE_ANY 0

struct net *sock_net(void *sk);
void xfrm_policy_walk_init(struct xfrm_policy_walk *walk, unsigned int type);
int xfrm_policy_walk(struct net *net, struct xfrm_policy_walk *walk,
                    int (*callback)(void), struct xfrm_dump_info *info);
int dump_one_policy(void);