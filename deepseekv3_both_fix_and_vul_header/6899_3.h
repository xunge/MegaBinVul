#include <stddef.h>

#define XFRMA_MAX 0
#define XFRM_MSG_MAX 0
#define XFRM_MSG_BASE 0
#define XFRM_MSG_GETSA 0
#define XFRM_MSG_GETPOLICY 0
#define NLM_F_DUMP 0
#define EINVAL 0
#define EPERM 0
#define CAP_NET_ADMIN 0

struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_flags;
};
struct net {
    void *user_ns;
    struct {
        void *nlsk;
    } xfrm;
};
struct nlattr;
struct nla_policy {
    unsigned int type;
};
struct netlink_dump_control {
    int (*start)(void);
    int (*dump)(void);
    int (*done)(void);
};

struct xfrm_link {
    int (*dump)(void);
    int (*done)(void);
    int (*doit)(struct sk_buff *, struct nlmsghdr *, struct nlattr **);
    int (*start)(void);
};

extern struct xfrm_link xfrm_dispatch[];
extern int xfrm_msg_min[];
extern struct nla_policy xfrma_policy[];

struct net *sock_net(void *sk);
int ns_capable(void *user_ns, int cap);
int nlmsg_parse(struct nlmsghdr *nlh, int min, struct nlattr **attrs, int max, struct nla_policy *policy);
int netlink_dump_start(void *nlsk, struct sk_buff *skb, struct nlmsghdr *nlh, struct netlink_dump_control *c);