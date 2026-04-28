#include <stdint.h>

struct sk_buff {
    void *sk;
    unsigned int len;
};

struct nlmsghdr {
    uint32_t nlmsg_seq;
};

struct netlink_callback {
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    uint32_t args[10];
};

struct net;

struct xfrm_policy_walk {
    uint8_t data[32]; // Placeholder for actual structure
};

struct xfrm_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    uint32_t nlmsg_seq;
    uint16_t nlmsg_flags;
};

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define NLM_F_MULTI 0x2
#define XFRM_POLICY_TYPE_ANY 0

struct net *sock_net(void *sk);
void xfrm_policy_walk_init(struct xfrm_policy_walk *walk, int type);
int xfrm_policy_walk(struct net *net, struct xfrm_policy_walk *walk,
                    int (*callback)(void*, void*), void *data);
int dump_one_policy(void *arg1, void *arg2);