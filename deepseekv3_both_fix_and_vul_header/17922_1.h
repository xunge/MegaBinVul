#include <string.h>

#define ETH_ALEN 6
#define IFF_802_1Q_VLAN 0x1
#define IFF_XMIT_DST_RELEASE 0x2
#define IFF_TX_SKB_SHARING 0x4

struct net_device {
    unsigned int priv_flags;
    int tx_queue_len;
    void *netdev_ops;
    void (*destructor)(struct net_device *dev);
    void *ethtool_ops;
    unsigned char broadcast[ETH_ALEN];
};

extern void ether_setup(struct net_device *dev);
extern const struct net_device_ops vlan_netdev_ops;
extern const struct ethtool_ops vlan_ethtool_ops;
extern void free_netdev(struct net_device *dev);