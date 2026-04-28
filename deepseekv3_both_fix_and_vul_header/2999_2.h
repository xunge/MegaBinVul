#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    unsigned int len;
    uint8_t ip_summed;
    void* data;
};

struct net_device {
    unsigned int flags;
    unsigned long features;
    void* priv;
};

struct veth_priv {
    struct net_device *peer;
    struct veth_net_stats *stats;
    uint8_t ip_summed;
};

struct veth_net_stats {
    uint64_t rx_packets;
    uint64_t tx_packets;
    uint64_t rx_bytes;
    uint64_t tx_bytes;
    uint64_t rx_dropped;
    uint64_t tx_dropped;
};

typedef unsigned int netdev_tx_t;

#define IFF_UP 0x1
#define NETIF_F_NO_CSUM 0x0001
#define NET_RX_SUCCESS 0
#define NETDEV_TX_OK 0
#define ETH_HLEN 14

static inline void* netdev_priv(const struct net_device *dev) {
    return dev->priv;
}

static inline struct veth_net_stats* this_cpu_ptr(struct veth_net_stats *ptr) {
    return ptr;
}

static inline int dev_forward_skb(struct net_device *dev, struct sk_buff *skb) {
    return NET_RX_SUCCESS;
}

static inline void kfree_skb(struct sk_buff *skb) {
}