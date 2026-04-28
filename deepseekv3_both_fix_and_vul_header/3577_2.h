#include <stddef.h>

#define IFNAMSIZ 16
#define IFLA_MAX 32
#define IFLA_IFNAME 1
#define EINVAL 22
#define ENODEV 19

struct sk_buff {
    void *sk;
};

struct nlmsghdr;
struct net;
struct net_device;
struct ifinfomsg {
    int ifi_index;
};
struct nlattr;

extern int nlmsg_parse(const struct nlmsghdr *nlh, int hdrlen,
                      struct nlattr *tb[], int maxtype,
                      const void *policy);
extern struct net *sock_net(void *sk);
extern struct net_device *__dev_get_by_index(struct net *net, int ifindex);
extern struct net_device *__dev_get_by_name(struct net *net, const char *name);
extern int validate_linkmsg(struct net_device *dev, struct nlattr *tb[]);
extern int do_setlink_skb(struct sk_buff *skb, struct net_device *dev,
                         struct ifinfomsg *ifm, struct nlattr *tb[],
                         const char *ifname, int flags);
extern int do_setlink_dev(struct net_device *dev, struct ifinfomsg *ifm,
                         struct nlattr *tb[], const char *ifname, int flags);
extern int nla_strlcpy(char *dst, const struct nlattr *nla, int dstsize);
extern const void *ifla_policy;
extern void *nlmsg_data(const struct nlmsghdr *nlh);