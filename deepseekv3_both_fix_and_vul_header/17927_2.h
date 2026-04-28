#include <stddef.h>

struct net_device {
    unsigned int priv_flags;
    const void *netdev_ops;
    void (*destructor)(struct net_device *dev);
    const void *header_ops;
    const void *ethtool_ops;
};

struct net_device_ops;
struct header_ops;
struct ethtool_ops;

void ether_setup(struct net_device *dev);
void free_netdev(struct net_device *dev);

extern const struct net_device_ops macvlan_netdev_ops;
extern const struct header_ops macvlan_hard_header_ops;
extern const struct ethtool_ops macvlan_ethtool_ops;

#define IFF_XMIT_DST_RELEASE (1 << 0)
#define IFF_TX_SKB_SHARING   (1 << 1)