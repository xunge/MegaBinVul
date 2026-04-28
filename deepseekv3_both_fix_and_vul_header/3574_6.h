#include <stddef.h>

struct net;
struct sk_buff;
struct ifinfomsg;
struct nlattr;

struct net_device {
    int group;
    struct net_device *next;
};

extern int do_setlink_full(const struct sk_buff *skb, struct net_device *dev, struct ifinfomsg *ifm, struct nlattr **tb, const char *, int);
extern int do_setlink_simple(struct net_device *dev, struct ifinfomsg *ifm, struct nlattr **tb);
#define for_each_netdev(net, dev) for ((dev) = (struct net_device *)(net); (dev); (dev) = (dev)->next)