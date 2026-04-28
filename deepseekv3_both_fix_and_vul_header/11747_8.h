#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct sk_buff {
    struct sock *sk;
    unsigned int len;
    struct netlink_skb_parms {
        uint32_t portid;
    } cb;
};

struct netlink_callback {
    int args[2];
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    unsigned int seq;
};

struct net {
    struct hlist_head dev_index_head[1];
    unsigned int dev_base_seq;
};

struct net_device {
    struct hlist_node index_hlist;
};

struct nlattr {
    int dummy;
};

struct rtnl_link_ops {
    int dummy;
};

struct ifinfomsg {
    int dummy;
};

struct rtgenmsg {
    int dummy;
};

struct nlmsghdr {
    unsigned int nlmsg_seq;
};

struct sock {
    int dummy;
};

struct nla_policy {
    int dummy;
};

#define IFLA_MAX 31
#define IFLA_IF_NETNSID 1
#define IFLA_EXT_MASK 2
#define IFLA_MASTER 3
#define IFLA_LINKINFO 4
#define NLM_F_MULTI 1
#define NLM_F_DUMP_FILTERED 2
#define NETDEV_HASHENTRIES 1
#define RTM_NEWLINK 1

typedef uint32_t u32;

#define likely(x) __builtin_expect(!!(x), 1)

#define hlist_for_each_entry(dev, head, member) \
    for (dev = NULL; dev != (void*)(head); dev = NULL)

#define NETLINK_CB(skb) ((skb)->cb)

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline int nlmsg_parse(const struct nlmsghdr *nlh, int hdrlen, struct nlattr *tb[], int maxtype, const struct nla_policy *policy, void *extack) { return 0; }
static inline int nla_get_s32(const struct nlattr *nla) { return 0; }
static inline u32 nla_get_u32(const struct nlattr *nla) { return 0; }
static inline struct net *get_target_net(struct sk_buff *skb, int netnsid) { return NULL; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline void put_net(struct net *net) {}
static inline int rtnl_fill_ifinfo(struct sk_buff *skb, struct net_device *dev, struct net *net, int type, u32 pid, u32 seq, u32 change, unsigned int flags, u32 ext_filter_mask, int ifindex, struct nlattr *tb[], int netnsid) { return 0; }
static inline int link_dump_filtered(struct net_device *dev, int master_idx, const struct rtnl_link_ops *kind_ops) { return 0; }
static inline void nl_dump_check_consistent(struct netlink_callback *cb, struct nlmsghdr *nlh) {}
static inline const struct rtnl_link_ops *linkinfo_to_kind_ops(struct nlattr **tb) { return NULL; }
static inline size_t nlmsg_len(const struct nlmsghdr *nlh) { return 0; }
static inline struct nlmsghdr *nlmsg_hdr(struct sk_buff *skb) { return NULL; }

extern const struct nla_policy ifla_policy[IFLA_MAX+1];