#include <stddef.h>

struct sk_buff {
    void *sk;
};

struct nlmsghdr;

struct net;

struct rtmsg {
    int rtm_table;
};

struct nlattr;

struct nla_policy {
    unsigned int type;
};

struct netlink_skb_parms {
    int dummy;
};

struct dn_fib_table {
    int (*insert)(struct dn_fib_table *, struct rtmsg *, struct nlattr **,
                 struct nlmsghdr *, struct netlink_skb_parms *);
};

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EINVAL 2
#define ENOBUFS 3
#define RTA_MAX 16

extern struct net init_net;
extern int rtm_get_table(struct nlattr **attrs, int table);
extern struct dn_fib_table *dn_fib_get_table(int id, int create);
extern const struct nla_policy rtm_dn_policy[RTA_MAX+1];
extern int capable(int cap);
extern int net_eq(struct net *net1, struct net *net2);
extern struct net *sock_net(void *sk);
extern struct rtmsg *nlmsg_data(struct nlmsghdr *nlh);
extern int nlmsg_parse(struct nlmsghdr *nlh, int payload_len,
                      struct nlattr **tb, int maxtype,
                      const struct nla_policy *policy);

static struct netlink_skb_parms netlink_cb;
#define NETLINK_CB(skb) (netlink_cb)