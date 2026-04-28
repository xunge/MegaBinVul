#include <assert.h>
#include <stddef.h>

typedef unsigned int netdev_tx_t;
#define NETDEV_TX_OK 0

struct sk_buff {
    unsigned int queue_mapping;
    unsigned int len;
};

struct net_device {
    struct {
        unsigned long tx_bytes;
        unsigned long tx_packets;
    } stats;
    struct ae_handle *ae_handle;
};

struct hns_nic_priv {
    struct tx_ring_data *ring_data;
};

struct ae_handle {
    unsigned int q_num;
};

struct tx_ring_data {
    char data[1];
};

static netdev_tx_t hns_nic_net_xmit_hw(struct net_device *ndev,
                                      struct sk_buff *skb,
                                      struct tx_ring_data *ring_data) {
    return NETDEV_TX_OK;
}

#define netdev_priv(dev) ((struct hns_nic_priv *)((char*)(dev) + sizeof(struct net_device)))
#define tx_ring_data(priv, queue) (priv)->ring_data[(queue)]

static inline void netif_trans_update(struct net_device *dev) {}