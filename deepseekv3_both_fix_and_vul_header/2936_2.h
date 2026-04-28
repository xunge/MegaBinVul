#include <stddef.h>

struct sk_buff {
    unsigned int len;
    void *sk;
};

struct netlink_callback {
    unsigned long args[2];
    unsigned int seq;
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
};

struct net_device {
    unsigned int priv_flags;
    int ifindex;
};

struct net {
    unsigned int dev_base_seq;
};

struct nlmsghdr;

struct br_port_msg {
    int ifindex;
};

extern int br_mdb_rehash_seq;
extern int br_mdb_fill_info(struct sk_buff *skb, struct netlink_callback *cb, struct net_device *dev);
extern int br_rports_fill_info(struct sk_buff *skb, struct netlink_callback *cb, struct net_device *dev);

#define IFF_EBRIDGE 0x0002
#define RTM_GETMDB 0
#define NLM_F_MULTI 0x0002

#define NETLINK_CB(skb) ((struct { int portid; } *)0)
#define nlmsg_put(skb, portid, seq, type, len, flags) NULL
#define nlmsg_data(nlh) ((struct br_port_msg *)0)
#define nlmsg_end(skb, nlh) (0)
#define rcu_read_lock()
#define rcu_read_unlock()
#define for_each_netdev_rcu(net, dev) for(dev = NULL; dev != NULL; dev = NULL)
#define sock_net(sk) ((struct net *)0)