#include <linux/netdevice.h>
#include <linux/if.h>
#include <linux/mii.h>
#include <linux/capability.h>
#include <linux/types.h>
#include <asm/ioctl.h>
#include <linux/if_ether.h>
#include <linux/sockios.h>
#include <linux/errno.h>

#define TX_RING_SIZE 256
typedef unsigned long dma_addr_t;
typedef __u32 u32;
typedef __u64 __le64;

struct net_device;
struct ifreq;

struct netdev_private {
    int phy_addr;
    unsigned long cur_tx;
    unsigned long old_tx;
    unsigned long cur_rx;
    unsigned long old_rx;
    dma_addr_t tx_ring_dma;
    struct netdev_desc *tx_ring;
};

struct netdev_desc {
    __le64 next_desc;
    __le64 status;
    __le64 fraginfo;
};

struct mii_data {
    unsigned short reg_num;
    unsigned short in_value;
    unsigned short out_value;
};

extern int printk(const char *fmt, ...);
static inline void *netdev_priv(struct net_device *dev) { return (void *)dev; }
static inline int mii_read(struct net_device *dev, int phy_addr, int reg_num) { return 0; }
static inline void mii_write(struct net_device *dev, int phy_addr, int reg_num, int val) {}
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_wake_queue(struct net_device *dev) {}
static inline int netif_queue_stopped(struct net_device *dev) { return 0; }
static inline u32 le64_to_cpu(__le64 val) { return (u32)val; }