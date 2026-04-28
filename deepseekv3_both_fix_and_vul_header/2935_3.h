#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <sys/types.h>

struct sk_buff;
struct netlink_callback {
    int args[2];
};
struct net_device {
    int ifindex;
};
struct net_bridge {
    int multicast_disabled;
    struct net_bridge_mdb_htable *mdb;
};
struct net_bridge_mdb_htable {
    int max;
    int ver;
    struct hlist_head *mhash;
};
struct hlist_head {
    struct hlist_node *first;
};
struct hlist_node {
    struct hlist_node *next, **pprev;
};
struct nlattr;
struct net_bridge_mdb_entry {
    struct net_bridge_port_group *ports;
};
struct net_bridge_port_group {
    struct net_bridge_port *port;
    uint8_t state;
    struct {
        uint16_t proto;
        union {
            uint32_t ip4;
            uint8_t ip6[16];
        } u;
    } addr;
    struct net_bridge_port_group *next;
};
struct net_bridge_port {
    struct net_device *dev;
};

#define MDBA_MDB 0
#define MDBA_MDB_ENTRY 1
#define MDBA_MDB_ENTRY_INFO 2
#define EMSGSIZE 90
#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD

struct br_mdb_entry {
    int ifindex;
    uint8_t state;
    struct {
        union {
            uint32_t ip4;
            uint8_t ip6[16];
        } u;
        uint16_t proto;
    } addr;
};

#define htons(x) ((uint16_t)(((x) << 8) | ((x) >> 8)))
#define rcu_dereference(p) (p)
#define nla_nest_start(skb, type) NULL
#define nla_nest_end(skb, nest) 
#define nla_put(skb, type, len, data) 0
#define nla_nest_cancel(skb, nest) 
#define netdev_priv(dev) ((struct net_bridge *)NULL)
#define hlist_for_each_entry_rcu(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)
#define IS_ENABLED(x) 0