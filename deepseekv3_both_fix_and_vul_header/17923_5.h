#include <stdint.h>

typedef uint8_t u8;

#define TX_Q_LIMIT 32
#define IFF_NOARP 0x80
#define IFF_MULTICAST 0x1000
#define IFF_XMIT_DST_RELEASE 0x4000
#define IFF_TX_SKB_SHARING 0x10000

#define NETIF_F_SG 0x1
#define NETIF_F_FRAGLIST 0x2
#define NETIF_F_HIGHDMA 0x4
#define NETIF_F_HW_CSUM 0x8
#define NETIF_F_TSO_ECN 0x10
#define NETIF_F_TSO 0x20
#define NETIF_F_TSO6 0x40
#define NETIF_F_LLTX 0x80
#define IFB_FEATURES (NETIF_F_SG | NETIF_F_FRAGLIST | NETIF_F_HIGHDMA | \
                     NETIF_F_HW_CSUM | NETIF_F_TSO_ECN | NETIF_F_TSO | \
                     NETIF_F_TSO6 | NETIF_F_LLTX)

struct net_device {
    void (*destructor)(struct net_device *);
    const void *netdev_ops;
    unsigned int tx_queue_len;
    unsigned int features;
    unsigned int vlan_features;
    unsigned short flags;
    unsigned int priv_flags;
    u8 dev_addr[6];
};

void free_netdev(struct net_device *dev);
void ether_setup(struct net_device *dev);
void random_ether_addr(u8 *addr);

static const struct {
    /* net_device_ops members would go here */
} ifb_netdev_ops;