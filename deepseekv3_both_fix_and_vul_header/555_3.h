#include <stdint.h>
#include <stddef.h>

#define TX_BD_NUM 256
#define FOR_EMAC 0x80000000
#define DROP 0x40000000
#define DEFR 0x20000000
#define LTCL 0x10000000
#define UFLO 0x08000000
#define FIRST_OR_LAST_MASK 0x00000001
#define DMA_TO_DEVICE 1

struct net_device_stats {
    unsigned long tx_packets;
    unsigned long tx_bytes;
    unsigned long tx_errors;
    unsigned long tx_dropped;
    unsigned long tx_carrier_errors;
    unsigned long collisions;
    unsigned long tx_fifo_errors;
};

struct device {
    int dummy;
};

struct net_device {
    struct net_device_stats stats;
    struct device dev;
};

struct sk_buff {
    unsigned int len;
};

struct arc_emac_bd {
    uint32_t info;
    uint32_t data;
};

struct buffer_state {
    struct sk_buff *skb;
    uintptr_t addr;
    uint32_t len;
};

struct arc_emac_priv {
    struct arc_emac_bd *txbd;
    struct buffer_state *tx_buff;
    unsigned int txbd_dirty;
};

#define le32_to_cpu(x) (x)
#define unlikely(x) (x)
#define likely(x) (x)
#define smp_mb() __asm__ __volatile__("" ::: "memory")
#define dma_unmap_single(dev, addr, len, dir) ((void)0)
#define dma_unmap_addr(tx_buff, addr) ((tx_buff)->addr)
#define dma_unmap_len(tx_buff, len) ((tx_buff)->len)
#define dev_kfree_skb_irq(skb) ((void)0)
#define netif_queue_stopped(ndev) (0)
#define netif_wake_queue(ndev) ((void)0)
#define netdev_priv(ndev) ((struct arc_emac_priv *)((char *)(ndev) + sizeof(struct net_device)))

static int arc_emac_tx_avail(struct arc_emac_priv *priv) { return 1; }