#include <stddef.h>
#include <stdint.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/if_link.h>
#include <net/if.h>

struct sk_buff {
    void *sk;
};
struct nlmsghdr;
struct netlink_ext_ack;
struct net;
struct net_device;
struct ifinfomsg;
struct nlattr;
struct nla_policy {
    uint16_t type;
    uint16_t len;
};

typedef uint32_t u32;

#define GFP_KERNEL 0
#define NETLINK_CB(skb) ((struct { void *sk; int portid; }){0})
#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define EINVAL 22
#define ENODEV 19
#define ENOBUFS 105
#define EMSGSIZE 90

static inline void WARN_ON(int condition) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int nlmsg_parse(struct nlmsghdr *nlh, int len, struct nlattr *tb[], int maxtype, const struct nla_policy *policy, struct netlink_ext_ack *extack) { return 0; }
static inline int nla_get_s32(struct nlattr *attr) { return 0; }
static inline struct net *get_target_net(void *sk, int netnsid) { return 0; }
static inline void nla_strlcpy(char *dst, struct nlattr *src, int size) {}
static inline u32 nla_get_u32(struct nlattr *attr) { return 0; }
static inline void *nlmsg_data(struct nlmsghdr *nlh) { return 0; }
static inline struct net_device *__dev_get_by_index(struct net *net, int ifindex) { return 0; }
static inline struct net_device *__dev_get_by_name(struct net *net, const char *name) { return 0; }
static inline struct sk_buff *nlmsg_new(int size, int flags) { return 0; }
static inline int if_nlmsg_size(struct net_device *dev, unsigned int filter_mask) { return 0; }
static inline int rtnl_fill_ifinfo(struct sk_buff *skb, struct net_device *dev, struct net *net, int type, int portid, int seq, unsigned int flags, unsigned int change, unsigned int filter_mask, int ifindex, void *data, int netnsid) { return 0; }
static inline int rtnl_unicast(struct sk_buff *skb, struct net *net, int portid) { return 0; }
static inline void put_net(struct net *net) {}
static inline struct net *sock_net(void *sk) { return 0; }

const struct nla_policy ifla_policy[IFLA_MAX+1];