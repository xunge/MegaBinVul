#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef unsigned int uint;

struct sk_buff {
    // dummy definition
};

struct net_device {
    unsigned short type;
    int ifindex;
    int iflink;
    char *name;
    unsigned int tx_queue_len;
    unsigned char operstate;
    unsigned char link_mode;
    unsigned int mtu;
    unsigned int group;
    unsigned int promiscuity;
    unsigned int num_tx_queues;
    unsigned int num_rx_queues;
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char if_port;
    unsigned char addr_len;
    unsigned char *dev_addr;
    unsigned char *broadcast;
    void *qdisc;
    char *ifalias;
    struct device {
        struct device *parent;
    } dev;
    struct net_device_ops {
        int (*ndo_get_vf_config)(struct net_device *, int, void *);
    } *netdev_ops;
    void *rtnl_link_ops;
};

struct nlmsghdr {
    // dummy definition
};

struct nlattr {
    // dummy definition
};

struct list_head {
    struct list_head *next, *prev;
};

struct rtnl_af_ops {
    int family;
    int (*fill_link_af)(struct sk_buff *, struct net_device *);
    struct list_head list;
};

struct ifinfomsg {
    unsigned char ifi_family;
    unsigned char __ifi_pad;
    unsigned short ifi_type;
    int ifi_index;
    unsigned int ifi_flags;
    unsigned int ifi_change;
};

struct rtnl_link_stats64 {
    uint64_t rx_packets;
    uint64_t tx_packets;
    uint64_t rx_bytes;
    uint64_t tx_bytes;
    uint64_t rx_errors;
    uint64_t tx_errors;
    uint64_t rx_dropped;
    uint64_t tx_dropped;
    uint64_t multicast;
    uint64_t collisions;
};

struct rtnl_link_stats {
    uint32_t rx_packets;
    uint32_t tx_packets;
    uint32_t rx_bytes;
    uint32_t tx_bytes;
    uint32_t rx_errors;
    uint32_t tx_errors;
};

struct rtnl_link_ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char port;
};

struct ifla_vf_info {
    uint32_t vf;
    uint8_t mac[32];
    uint32_t vlan;
    uint32_t qos;
    uint32_t tx_rate;
    int32_t spoofchk;
};

struct ifla_vf_mac {
    uint32_t vf;
    uint8_t mac[32];
};

struct ifla_vf_vlan {
    uint32_t vf;
    uint32_t vlan;
    uint32_t qos;
};

struct ifla_vf_tx_rate {
    uint32_t vf;
    uint32_t rate;
};

struct ifla_vf_spoofchk {
    uint32_t vf;
    uint32_t setting;
};

#define AF_UNSPEC 0
#define IF_OPER_DOWN 0
#define RTEXT_FILTER_VF 0
#define EMSGSIZE 90
#define ENODATA 61

#define ASSERT_RTNL()
#define netdev_master_upper_dev_get(dev) NULL
#define nlmsg_put(skb, pid, seq, type, len, flags) NULL
#define nlmsg_data(nlh) NULL
#define dev_get_flags(dev) 0
#define nla_put_string(skb, type, str) 0
#define nla_put_u32(skb, type, value) 0
#define nla_put_u8(skb, type, value) 0
#define netif_running(dev) 0
#define netif_carrier_ok(dev) 0
#define nla_put(skb, type, len, data) 0
#define nla_reserve(skb, type, len) NULL
#define dev_get_stats(dev, temp) NULL
#define copy_rtnl_link_stats(dest, src)
#define copy_rtnl_link_stats64(dest, src)
#define dev_num_vf(parent) 0
#define nla_nest_start(skb, type) NULL
#define nla_nest_cancel(skb, nla)
#define nla_nest_end(skb, nla) 0
#define nlmsg_end(skb, nlh) 0
#define nlmsg_cancel(skb, nlh)
#define rtnl_port_fill(skb, dev) 0
#define rtnl_link_fill(skb, dev) 0

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

struct rtnl_af_ops *rtnl_af_ops;

enum {
    IFLA_IFNAME,
    IFLA_TXQLEN,
    IFLA_OPERSTATE,
    IFLA_LINKMODE,
    IFLA_MTU,
    IFLA_GROUP,
    IFLA_PROMISCUITY,
    IFLA_NUM_TX_QUEUES,
    IFLA_NUM_RX_QUEUES,
    IFLA_LINK,
    IFLA_MASTER,
    IFLA_CARRIER,
    IFLA_QDISC,
    IFLA_IFALIAS,
    IFLA_MAP,
    IFLA_ADDRESS,
    IFLA_BROADCAST,
    IFLA_STATS,
    IFLA_STATS64,
    IFLA_NUM_VF,
    IFLA_VFINFO_LIST,
    IFLA_VF_INFO,
    IFLA_VF_MAC,
    IFLA_VF_VLAN,
    IFLA_VF_TX_RATE,
    IFLA_VF_SPOOFCHK,
    IFLA_AF_SPEC
};