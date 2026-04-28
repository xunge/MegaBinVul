#include <sys/socket.h>
#include <net/if.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#define MODULE_NAME_LEN 64
#define IFNAMSIZ IF_NAMESIZE
#define IFLA_MAX 32
#define IFLA_INFO_MAX 32
#define IFLA_IFNAME 1
#define IFLA_LINKINFO 2
#define IFLA_INFO_KIND 1
#define IFLA_INFO_DATA 2
#define IFLA_INFO_SLAVE_DATA 3
#define IFLA_GROUP 4
#define IFLA_MAP 5
#define IFLA_MASTER 6
#define IFLA_PROTINFO 7

#define NLM_F_EXCL 0x200
#define NLM_F_REPLACE 0x100
#define NLM_F_CREATE 0x400
#define EEXIST 17
#define EOPNOTSUPP 95
#define ENODEV 19

struct nlattr {
    unsigned short nla_len;
    unsigned short nla_type;
};

struct nla_policy {
    unsigned int type;
    unsigned int len;
};

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_flags;
};

struct net;

struct net_device {
    int ifindex;
    const struct rtnl_link_ops *rtnl_link_ops;
};

struct ifinfomsg {
    int ifi_index;
};

struct rtnl_link_ops {
    int maxtype;
    int slave_maxtype;
    const char *kind;
    const struct nla_policy *policy;
    const struct nla_policy *slave_policy;
    int (*validate)(struct nlattr **tb, struct nlattr **data);
    int (*slave_validate)(struct nlattr **tb, struct nlattr **slave_data);
    int (*changelink)(struct net_device *dev, struct nlattr **tb, struct nlattr **data);
    int (*slave_changelink)(struct net_device *master_dev, struct net_device *dev,
                           struct nlattr **tb, struct nlattr **slave_data);
    int (*newlink)(struct net *net, struct net_device *dev,
                  struct nlattr **tb, struct nlattr **data);
};

static const struct nla_policy ifla_policy[IFLA_MAX+1] = {0};
static const struct nla_policy ifla_info_policy[IFLA_INFO_MAX+1] = {0};

#define CONFIG_MODULES