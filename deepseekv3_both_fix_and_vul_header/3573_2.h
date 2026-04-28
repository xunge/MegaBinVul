#include <stdint.h>
#include <stddef.h>

#define CAP_NET_ADMIN 1
#define EPERM 1
#define EINVAL 22
#define ENODEV 19
#define EOPNOTSUPP 95
#define NDA_MAX 1
#define NDA_LLADDR 1
#define ETH_ALEN 6
#define NTF_MASTER 1
#define NTF_SELF 2
#define IFF_BRIDGE_PORT 1
#define RTM_DELNEIGH 1

typedef uint8_t __u8;

struct sk_buff {
    void *sk;
};
struct nlmsghdr {};
struct net {};
struct ndmsg {
    int ndm_ifindex;
    int ndm_flags;
};
struct nlattr {
    int len;
};
struct net_device_ops {
    int (*ndo_fdb_del)(struct ndmsg *, struct nlattr **, struct net_device *, __u8 *);
};
struct net_device {
    unsigned int priv_flags;
    struct net_device_ops *netdev_ops;
};

static struct net *sock_net(void *sk) { return 0; }
static int capable(int cap) { return 0; }
static int nlmsg_parse(struct nlmsghdr *nlh, int size, struct nlattr **tb, int max, void *policy) { return 0; }
static struct ndmsg *nlmsg_data(struct nlmsghdr *nlh) { return 0; }
static struct net_device *__dev_get_by_index(struct net *net, int ifindex) { return 0; }
static int nla_len(struct nlattr *nla) { return 0; }
static __u8 *nla_data(struct nlattr *nla) { return 0; }
static struct net_device *netdev_master_upper_dev_get(struct net_device *dev) { return 0; }
static int ndo_dflt_fdb_del(struct ndmsg *ndm, struct nlattr **tb, struct net_device *dev, __u8 *addr) { return 0; }
static void rtnl_fdb_notify(struct net_device *dev, __u8 *addr, int type) {}
static void pr_info(const char *fmt, ...) {}