#include <stdbool.h>
#include <stddef.h>

struct device {
    struct device_node *of_node;
};

struct device_node;

struct platform_device {
    struct device dev;
};

struct resource {
    unsigned long start;
    unsigned long end;
};

struct net_device {
    unsigned int irq;
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned char dev_addr[6];
    void *netdev_ops;
    void *ethtool_ops;
    unsigned int flags;
    unsigned int watchdog_timeo;
};

struct net_local {
    struct net_device *ndev;
    void *base_addr;
    int reset_lock;
    unsigned int next_tx_buf_to_use;
    unsigned int next_rx_buf_to_use;
    bool tx_ping_pong;
    bool rx_ping_pong;
    struct device_node *phy_node;
};

struct net_device_ops {
};

struct ethtool_ops {
};

#define ENOMEM 1
#define ENXIO 2
#define IORESOURCE_IRQ 0
#define IORESOURCE_MEM 1
#define XEL_TSR_OFFSET 0
#define XEL_BUFFER_OFFSET 0
#define TX_TIMEOUT 1000
#define IFF_MULTICAST 0x1000

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define dev_info(dev, fmt, ...) 
#define dev_err(dev, fmt, ...) 
#define dev_warn(dev, fmt, ...) 
#define SET_NETDEV_DEV(ndev, dev) 

static struct net_device_ops xemaclite_netdev_ops;
static struct ethtool_ops xemaclite_ethtool_ops;

static void xemaclite_writel(unsigned int value, void *addr);
static void xemaclite_update_address(struct net_local *lp, unsigned char *addr);
static void xemaclite_mdio_setup(struct net_local *lp, struct device *dev);
static bool get_bool(struct platform_device *ofdev, const char *propname);
static int of_get_mac_address(struct device_node *np, unsigned char *addr);
static void eth_hw_addr_random(struct net_device *ndev);
static struct device_node *of_parse_phandle(struct device_node *np, const char *phandle, int index);
static struct resource *platform_get_resource(struct platform_device *dev, unsigned int type, unsigned int num);
static void *devm_ioremap_resource(struct device *dev, struct resource *res);
static int register_netdev(struct net_device *ndev);
static void free_netdev(struct net_device *ndev);
static struct net_device *alloc_etherdev(int size);
static void dev_set_drvdata(struct device *dev, void *data);
static void spin_lock_init(int *lock);
static void *netdev_priv(struct net_device *dev);