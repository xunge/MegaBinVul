#include <stdio.h>
#include <string.h>

#define A_ERROR (-1)
#define AR6000_ETH_ADDR_LEN 6
#define ATH_DEBUG_ERR 1
#define IFF_TX_SKB_SHARING (1 << 0)

#define AR_DEBUG_PRINTF(level, fmt) printf fmt

struct net_device {
    char dev_addr[6];
    unsigned int priv_flags;
};

struct ar6_softc {
    struct net_device *arNetDev;
    struct ar_virtual_interface *arApDev;
};

struct ar_virtual_interface {
    struct ar6_softc *arDev;
    struct net_device *arNetDev;
    struct net_device *arStaNetDev;
};

extern struct net_device *arApNetDev;

struct net_device *alloc_etherdev(int size);
void ether_setup(struct net_device *dev);
void init_netdev(struct net_device *dev, char *name);
int register_netdev(struct net_device *dev);
struct ar_virtual_interface *netdev_priv(struct net_device *dev);