#include <stdint.h>

struct platform_device {
    struct {
        void *dev;
    } dev;
};

struct net_device;
struct napi_struct {
    // minimal dummy definition
    int dummy;
};
struct work_struct {
    // minimal dummy definition  
    int dummy;
};
struct mdio_device {
    void *dev;
};
struct phy_device {
    struct mdio_device mdio;
};
struct mii_bus;

struct emac_adapter {
    struct net_device *netdev;
    struct napi_struct napi;
    struct {
        struct napi_struct napi;
    } rx_q;
    struct {
        int irq;
    } irq;
    struct work_struct work_thread;
    struct phy_device *phydev;
    struct mii_bus *mii_bus;
    struct {
        void *digital;
        void *base;
    } phy;
};

void *dev_get_drvdata(void *dev);
struct emac_adapter *netdev_priv(struct net_device *netdev);
void netif_carrier_off(struct net_device *netdev);
void netif_tx_disable(struct net_device *netdev);
void unregister_netdev(struct net_device *netdev);
void netif_napi_del(struct napi_struct *napi);
void free_irq(int irq, void *dev_id);
void cancel_work_sync(struct work_struct *work);
void emac_clks_teardown(struct emac_adapter *adpt);
void put_device(void *dev);
void mdiobus_unregister(struct mii_bus *bus);
void iounmap(void *addr);
void free_netdev(struct net_device *netdev);