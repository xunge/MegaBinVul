#include <stdint.h>
#include <stddef.h>

#define DCB_ATTR_MAX 10
#define DCB_CMD_MAX 10
#define DCB_ATTR_IFNAME 1
#define RTM_SETDCB 0
#define CAP_NET_ADMIN 0
#define EPERM 1
#define EINVAL 22
#define EOPNOTSUPP 95
#define ENODEV 19
#define ENOBUFS 105

typedef uint32_t u32;

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_seq;
    int nlmsg_flags;
};

struct net {
};

struct net_device {
    void *dcbnl_ops;
};

struct dcbmsg {
    int cmd;
};

struct nlattr {
};

struct reply_func {
    int (*cb)(struct net_device *, struct nlmsghdr *, u32, struct nlattr **, struct sk_buff *);
    int type;
};

struct NETLINK_CB {
    u32 portid;
};

static const struct reply_func reply_funcs[DCB_CMD_MAX + 1];
static const void *dcbnl_rtnl_policy[DCB_ATTR_MAX + 1];

#define NETLINK_CB(skb) ((struct NETLINK_CB){0})

static inline struct net *sock_net(void *sk) { return NULL; }
static inline struct net_device *__dev_get_by_name(struct net *net, const void *data) { return NULL; }
static inline void *nla_data(struct nlattr *attr) { return NULL; }
static inline void *nlmsg_data(struct nlmsghdr *nlh) { return NULL; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, int size, struct nlattr **tb, int maxtype, const void *policy) { return 0; }
static inline struct sk_buff *dcbnl_newmsg(int type, int cmd, u32 portid, int seq, int flags, struct nlmsghdr **nlh) { return NULL; }
static inline void nlmsg_free(struct sk_buff *skb) {}
static inline void nlmsg_end(struct sk_buff *skb, struct nlmsghdr *nlh) {}
static inline int rtnl_unicast(struct sk_buff *skb, struct net *net, u32 portid) { return 0; }
static inline int capable(int cap) { return 0; }