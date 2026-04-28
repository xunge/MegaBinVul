#include <linux/if_ether.h>
#include <linux/netdevice.h>
#include <linux/ethtool.h>

struct net_device {
    unsigned long features;
    unsigned long hw_features;
    void *netdev_ops;
    void *ethtool_ops;
    void (*destructor)(struct net_device *dev);
    unsigned long priv_flags;
};

struct net_device_ops;
struct ethtool_ops;

extern struct net_device_ops veth_netdev_ops;
extern struct ethtool_ops veth_ethtool_ops;
void veth_dev_free(struct net_device *dev);
void ether_setup(struct net_device *dev);

#define NETIF_F_LLTX (1 << 22)
#define NETIF_F_NO_CSUM (1 << 3)
#define NETIF_F_SG (1 << 4)
#define NETIF_F_RXCSUM (1 << 11)
#define IFF_TX_SKB_SHARING (1 << 25)