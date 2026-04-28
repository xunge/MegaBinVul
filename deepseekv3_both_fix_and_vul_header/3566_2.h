#include <stddef.h>

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_type;
    unsigned int nlmsg_flags;
};

struct net {
    void *user_ns;
    struct {
        void *nlsk;
    } xfrm;
};

struct nlattr;

struct xfrm_link {
    int (*dump)(struct sk_buff *, struct netlink_dump_control *);
    int (*done)(struct netlink_dump_control *);
    int (*doit)(struct sk_buff *, struct nlmsghdr *, struct nlattr **);
};

struct netlink_dump_control {
    int (*dump)(struct sk_buff *, struct netlink_dump_control *);
    int (*done)(struct netlink_dump_control *);
};

#define XFRMA_MAX 64
#define XFRM_MSG_MAX 64
#define XFRM_MSG_BASE 0
#define NLM_F_DUMP 0x0300
#define XFRM_MSG_GETSA 0
#define XFRM_MSG_GETPOLICY 0
#define CAP_NET_ADMIN 0
#define EINVAL 22
#define EPERM 1

extern struct xfrm_link xfrm_dispatch[];
extern int xfrm_msg_min[];
extern struct {
    int dummy;
} xfrma_policy[XFRMA_MAX + 1];

struct net *sock_net(void *);
int ns_capable(void *, int);
int nlmsg_parse(struct nlmsghdr *, int, struct nlattr **, int, void *);
int netlink_dump_start(void *, struct sk_buff *, struct nlmsghdr *, struct netlink_dump_control *);