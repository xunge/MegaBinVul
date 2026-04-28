#include <string.h>
#include <net/if.h>
#include <netinet/if_ether.h>

#define ETH_ALEN 6
#define HZ 100
#define IFF_TX_SKB_SHARING (1<<16)

struct net_device {
    unsigned char broadcast[ETH_ALEN];
    unsigned int addr_len;
    unsigned int priv_flags;
    const void *netdev_ops;
    unsigned int watchdog_timeo;
};

extern const void bnep_netdev_ops;

void ether_setup(struct net_device *dev);