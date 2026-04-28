#include <string.h>

struct device;
struct net_device_ops;
struct ethtool_ops;

struct efx_nic {
    struct net_device *net_dev;
    struct pci_dev *pci_dev;
    struct {
        void (*update_stats)(struct efx_nic *);
    } *mac_op;
    struct {
        int dummy;
    } mac_stats;
};

struct net_device {
    int watchdog_timeo;
    int irq;
    const struct net_device_ops *netdev_ops;
    const struct ethtool_ops *ethtool_ops;
    int gso_max_segs;
    char name[16];
};

struct pci_dev {
    int irq;
    struct device *dev;
};

struct device_attribute {
    int dummy;
};

struct efx_channel {
    int dummy;
};

struct efx_tx_queue {
    int dummy;
};

extern const struct net_device_ops efx_netdev_ops;
extern const struct ethtool_ops efx_ethtool_ops;
extern struct device_attribute dev_attr_phy_type;

#define HZ 100
#define EFX_TSO_MAX_SEGS 100
#define drv 0

void rtnl_lock(void);
void rtnl_unlock(void);
int dev_alloc_name(struct net_device *dev, const char *name);
int register_netdevice(struct net_device *dev);
void netif_carrier_off(struct net_device *dev);
int device_create_file(struct device *device, const struct device_attribute *entry);
void unregister_netdev(struct net_device *dev);
void efx_update_name(struct efx_nic *efx);
void efx_init_tx_queue_core_txq(struct efx_tx_queue *tx_queue);
void netif_err(const struct efx_nic *efx, int type, struct net_device *netdev, const char *fmt, ...);
#define SET_ETHTOOL_OPS(netdev, ops) ((netdev)->ethtool_ops = (ops))

#define efx_for_each_channel(channel, efx) \
    for ((channel) = NULL; (channel) != (void *)1; (channel) = (void *)1)

#define efx_for_each_channel_tx_queue(tx_queue, channel) \
    for ((tx_queue) = NULL; (tx_queue) != (void *)1; (tx_queue) = (void *)1)