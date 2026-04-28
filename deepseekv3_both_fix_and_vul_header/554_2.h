#include <stdint.h>
#include <string.h>

#define ETH_ZLEN 60
#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define FOR_EMAC 0
#define FIRST_OR_LAST_MASK 0x80000000
#define TX_BD_NUM 256
#define TXPL_MASK 0x1
#define DMA_TO_DEVICE 1
#define R_STATUS 0

typedef uint32_t __le32;
typedef uint64_t dma_addr_t;

struct net_device_stats {
    unsigned long tx_dropped;
    unsigned long tx_errors;
};

struct sk_buff {
    unsigned int len;
    void *data;
};

struct net_device {
    struct net_device_stats stats;
    struct {
        int dev;
    } dev;
};

struct arc_emac_priv {
    unsigned int txbd_curr;
    struct net_device_stats stats;
    struct {
        __le32 info;
        __le32 data;
    } *txbd;
    struct {
        dma_addr_t addr;
        unsigned int len;
        struct sk_buff *skb;
    } *tx_buff;
};

#define unlikely(x) (x)
#define wmb() asm volatile("" ::: "memory")
#define smp_mb() asm volatile("" ::: "memory")

static inline __le32 cpu_to_le32(uint32_t x) { return x; }
static inline void *netdev_priv(struct net_device *dev) { return (void *)dev + sizeof(*dev); }
static inline int skb_padto(struct sk_buff *skb, unsigned int len) { return 0; }
static inline int arc_emac_tx_avail(struct arc_emac_priv *priv) { return 1; }
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_start_queue(struct net_device *dev) {}
static inline void netdev_err(struct net_device *dev, const char *fmt, ...) {}
static inline dma_addr_t dma_map_single(void *dev, void *ptr, size_t size, int dir) { return (dma_addr_t)ptr; }
static inline int dma_mapping_error(void *dev, dma_addr_t addr) { return 0; }
static inline void dev_kfree_skb(struct sk_buff *skb) {}
static inline void skb_tx_timestamp(struct sk_buff *skb) {}
static inline void arc_reg_set(struct arc_emac_priv *priv, int reg, int val) {}

#define dma_unmap_addr_set(ptr, name, val) ((ptr)->name = val)
#define dma_unmap_len_set(ptr, name, val) ((ptr)->name = val)
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))