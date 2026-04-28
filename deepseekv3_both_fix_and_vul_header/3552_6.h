#include <stddef.h>

#define CAP_NET_ADMIN 0
#define RTA_MAX 0
#define EPERM 1
#define EINVAL 2
#define ESRCH 3

struct sk_buff {
    void *sk;
};

struct nlmsghdr;
struct nlattr;

struct net {
    int dummy;
};

struct rtmsg {
    int rtm_table;
};

struct netlink_skb_parms {
    int dummy;
};

struct dn_fib_table {
    int (*delete)(struct dn_fib_table *, struct rtmsg *, struct nlattr *[], struct nlmsghdr *, struct netlink_skb_parms *);
};

extern struct net init_net;
extern const void *rtm_dn_policy;

static inline struct net *sock_net(void *sk) { return &init_net; }
static inline int netlink_capable(struct sk_buff *skb, int cap) { return 1; }
static inline int capable(int cap) { return 1; }
static inline int net_eq(struct net *net1, struct net *net2) { return 1; }
static inline struct rtmsg *nlmsg_data(struct nlmsghdr *nlh) { return NULL; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, size_t size, struct nlattr *attrs[], int max, const void *policy) { return 0; }
static inline unsigned int rtm_get_table(struct nlattr *attrs[], int id) { return 0; }
static inline struct dn_fib_table *dn_fib_get_table(unsigned int id, int create) { return NULL; }
static inline struct netlink_skb_parms *get_netlink_cb(struct sk_buff *skb) { 
    static struct netlink_skb_parms cb;
    return &cb; 
}
#define NETLINK_CB(skb) (*get_netlink_cb(skb))