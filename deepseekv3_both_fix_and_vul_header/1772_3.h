#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef unsigned int rx_handler_result_t;

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char pkt_type;
    void *dev;
};

struct ethhdr {
    unsigned char h_dest[6];
    unsigned char h_source[6];
};

struct net_device {
    unsigned int flags;
    void *dev;
};

struct macvlan_port {
    unsigned long *mc_filter;
    struct list_head vlans;
};

struct macvlan_dev {
    int mode;
    struct net_device *dev;
    struct list_head list;
};

#define RX_HANDLER_PASS 0
#define RX_HANDLER_CONSUMED 1
#define RX_HANDLER_ANOTHER 2

#define PACKET_LOOPBACK 5
#define PACKET_HOST 0

#define IFF_UP 0x1
#define NET_RX_SUCCESS 0
#define NET_RX_DROP 1
#define GFP_ATOMIC 0
#define IP_DEFRAG_MACVLAN 0

#define MACVLAN_MODE_VEPA 0
#define MACVLAN_MODE_BRIDGE 1
#define MACVLAN_MODE_SOURCE 2
#define ETH_HLEN 14

static inline int unlikely(int x) { return x; }
static inline const struct ethhdr *eth_hdr(const struct sk_buff *skb) { return (const struct ethhdr *)skb->data; }
static inline int is_multicast_ether_addr(const unsigned char *addr) { return addr[0] & 0x01; }
static inline struct macvlan_port *macvlan_port_get_rcu(void *dev) { return NULL; }
static inline int macvlan_forward_source(struct sk_buff *skb, struct macvlan_port *port, const unsigned char *src) { return 0; }
static inline struct macvlan_dev *macvlan_hash_lookup(struct macvlan_port *port, const unsigned char *addr) { return NULL; }
static inline int macvlan_broadcast_one(struct sk_buff *skb, const struct macvlan_dev *vlan, const struct ethhdr *eth, int local) { return 0; }
static inline int __netif_rx(struct sk_buff *skb) { return 0; }
static inline unsigned int mc_hash(void *port, const unsigned char *addr) { return 0; }
static inline int test_bit(unsigned int nr, const unsigned long *addr) { return 0; }
static inline void macvlan_broadcast_enqueue(struct macvlan_port *port, const struct macvlan_dev *src, struct sk_buff *skb) {}
static inline int macvlan_passthru(struct macvlan_port *port) { return 0; }
static inline struct sk_buff *skb_share_check(struct sk_buff *skb, int pri) { return skb; }
static inline void macvlan_count_rx(const struct macvlan_dev *vlan, unsigned int len, int success, bool local) {}
static inline struct sk_buff *ip_check_defrag(void *net, struct sk_buff *skb, int user) { return skb; }
static inline void *dev_net(void *dev) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}

#define list_first_or_null_rcu(ptr, type, member) NULL