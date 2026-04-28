#include <stdint.h>
#include <stdlib.h>

struct sk_buff {
    uint16_t protocol;
    unsigned int len;
    void *dev;
    void *transport_header;
};

struct net_device_stats {
    unsigned long rx_packets;
    unsigned long rx_bytes;
};

struct net_device {
    struct net_device_stats stats;
};

struct net {
    // dummy definition
};

extern struct net init_net;

#define ETH_P_IP 0x0800
#define NET_RX_DROP 0
#define ENODEV 19

static inline uint16_t htons(uint16_t hostshort) {
    return ((hostshort & 0xFF) << 8) | ((hostshort >> 8) & 0xFF);
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    // dummy implementation
}

static inline void skb_reset_transport_header(struct sk_buff *skb) {
    // dummy implementation
}

static inline struct net_device_stats *netdev_priv(struct net_device *dev) {
    return &dev->stats;
}

static inline int netif_rx(struct sk_buff *skb) {
    // dummy implementation
    return 0;
}

static inline void kfree_skb(struct sk_buff *skb) {
    // dummy implementation
}

static inline struct net_device *__dev_get_by_name(struct net *net, const char *name) {
    // dummy implementation
    return (struct net_device *)0;
}