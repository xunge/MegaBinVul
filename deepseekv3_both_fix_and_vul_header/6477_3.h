#include <stddef.h>

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_type;
    unsigned int nlmsg_flags;
};

struct netlink_ext_ack;

struct net {
    struct {
        void *nlsk;
    } xfrm;
};

struct nlattr;

struct xfrm_link {
    int (*dump)(void);
    int (*start)(void);
    int (*done)(void);
    int nla_max;
    void *nla_pol;
    int (*doit)(struct sk_buff *, struct nlmsghdr *, struct nlattr **);
};

struct netlink_dump_control {
    int (*start)(void);
    int (*dump)(void);
    int (*done)(void);
};

#define CONFIG_COMPAT
#define XFRMA_MAX 1
#define XFRM_MSG_MAX 1
#define XFRM_MSG_BASE 0
#define XFRM_MSG_GETSA 0
#define XFRM_MSG_GETPOLICY 0
#define NLM_F_DUMP 0x1
#define CAP_NET_ADMIN 0
#define EOPNOTSUPP 1
#define EINVAL 2
#define EPERM 3

extern int in_compat_syscall(void);
extern struct net *sock_net(void *);
extern int netlink_net_capable(struct sk_buff *, int);
extern int nlmsg_parse(struct nlmsghdr *, int, struct nlattr **, int, void *, struct netlink_ext_ack *);
extern int netlink_dump_start(void *, struct sk_buff *, struct nlmsghdr *, struct netlink_dump_control *);

const struct xfrm_link xfrm_dispatch[1];
int xfrm_msg_min[1];
struct nla_policy { int dummy; } xfrma_policy[1];