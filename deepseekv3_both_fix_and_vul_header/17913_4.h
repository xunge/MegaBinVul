#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/ethernet.h>

#define IFF_TX_SKB_SHARING (1 << 0)

struct net_device {
    unsigned int priv_flags;
    struct net_device_ops *netdev_ops;
    void (*destructor)(struct net_device *dev);
};

struct net_device_ops {
    // 这里可以留空，因为代码中只使用了指针
};

extern struct net_device_ops ieee80211_dataif_ops;
void ether_setup(struct net_device *dev);
void free_netdev(struct net_device *dev);