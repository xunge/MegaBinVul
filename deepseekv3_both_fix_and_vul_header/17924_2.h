struct net_device {
    unsigned int priv_flags;
    struct net_device_ops *netdev_ops;
    void (*destructor)(struct net_device *dev);
};

struct net_device_ops {
    // 留空，仅用于编译通过
};

extern void ether_setup(struct net_device *dev);
extern void free_netdev(struct net_device *dev);

#define IFF_TX_SKB_SHARING 0x10000

struct net_device_ops l2tp_eth_netdev_ops;