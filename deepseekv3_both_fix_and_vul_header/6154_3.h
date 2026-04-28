#include <stdint.h>
#include <stddef.h>

typedef uint64_t dma_addr_t;
typedef unsigned int netdev_tx_t;

#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define CHECKSUM_PARTIAL 1
#define DMA_TO_DEVICE 1
#define TX_TAILDESC_PTR 0

struct skb_shared_info {
    unsigned int nr_frags;
    struct skb_frag_struct *frags;
};

struct sk_buff {
    unsigned int ip_summed;
    unsigned char *data;
    unsigned int csum_offset;
    void *dev_parent;
    struct skb_shared_info *shinfo;
    unsigned int headlen;
};

struct skb_frag_struct {
    void *address;
    unsigned int size;
};

typedef struct skb_frag_struct skb_frag_t;

struct net_device {
    struct {
        void *parent;
    } dev;
    struct {
        unsigned int tx_dropped;
    } stats;
};

struct temac_local {
    struct cdmac_bd *tx_bd_v;
    int tx_bd_tail;
    unsigned int tx_bd_num;
    dma_addr_t tx_bd_p;
    void (*dma_out)(struct temac_local *, int, dma_addr_t);
};

struct cdmac_bd {
    uint32_t app0;
    uint32_t app1;
    uint32_t app2;
    uint32_t len;
    uint32_t phys;
};

#define STS_CTRL_APP0_SOP (1 << 0)
#define STS_CTRL_APP0_EOP (1 << 1)

static inline uint32_t cpu_to_be32(uint32_t x) { return x; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }

#define WARN_ON_ONCE(cond) (cond)
#define smp_mb() __asm__ __volatile__("" ::: "memory")
#define wmb() __asm__ __volatile__("" ::: "memory")

static inline void *netdev_priv(struct net_device *dev) { return (void*)dev + sizeof(*dev); }
static inline void dev_kfree_skb_any(struct sk_buff *skb) {}
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_wake_queue(struct net_device *dev) {}
static inline int netif_queue_stopped(struct net_device *dev) { return 0; }
static inline void skb_tx_timestamp(struct sk_buff *skb) {}
static inline void ptr_to_txbd(void *ptr, struct cdmac_bd *bd) {}

static inline dma_addr_t dma_map_single(void *dev, void *ptr, size_t size, int dir) { return (dma_addr_t)(uintptr_t)ptr; }
static inline int dma_mapping_error(void *dev, dma_addr_t addr) { return 0; }
static inline void dma_unmap_single(void *dev, dma_addr_t addr, size_t size, int dir) {}

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return skb->shinfo; }
static inline unsigned int skb_headlen(struct sk_buff *skb) { return skb->headlen; }
static inline unsigned int skb_checksum_start_offset(struct sk_buff *skb) { return 0; }
static inline void *skb_frag_address(skb_frag_t *frag) { return frag->address; }
static inline unsigned int skb_frag_size(skb_frag_t *frag) { return frag->size; }

static inline int temac_check_tx_bd_space(struct temac_local *lp, unsigned long num_frag) { return 0; }