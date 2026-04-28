#include <stddef.h>
#include <assert.h>

typedef unsigned int netdev_tx_t;
typedef unsigned long dma_addr_t;

struct net_device {
    unsigned int mtu;
    struct {
        unsigned long tx_bytes;
        unsigned long tx_packets;
    } stats;
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned int queue_mapping;
    struct skb_shared_info *shinfo;
};

struct device;
struct netdev_queue;

struct skb_frag_struct {
    unsigned int size;
    void *page;
};

struct skb_shared_info {
    unsigned int nr_frags;
    struct skb_frag_struct frags[];
};

struct hns_nic_priv {
    struct {
        int (*maybe_stop_tx)(struct sk_buff **, int *, void *);
        void (*fill_desc)(void *, void *, int, dma_addr_t, int, int, int, unsigned int);
    } ops;
    struct {
        int q_num;
        void **qs;
    } *ae_handle;
};

struct hnae_ring {
    unsigned int next_to_use;
    struct {
        dma_addr_t dma;
        int length;
    } *desc_cb;
    struct {
        unsigned long tx_pkts;
        unsigned long tx_bytes;
        unsigned long tx_busy;
        unsigned long sw_err_cnt;
    } stats;
};

struct hns_nic_ring_data {
    struct hnae_ring *ring;
};

#define DMA_TO_DEVICE 1
#define DESC_TYPE_SKB 0
#define DESC_TYPE_PAGE 1
#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define EBUSY 16
#define ENOMEM 12

static inline struct hns_nic_priv *netdev_priv(struct net_device *dev) {
    return NULL;
}

static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb + 1);
}

static inline unsigned int skb_headlen(const struct sk_buff *skb) {
    return skb->len;
}

static inline unsigned int skb_frag_size(const struct skb_frag_struct *frag) {
    return frag->size;
}

static inline void *skb_frag_page(const struct skb_frag_struct *frag) {
    return frag->page;
}

static inline dma_addr_t dma_map_single(struct device *dev, void *ptr, int size, int dir) {
    return 0;
}

static inline int dma_mapping_error(struct device *dev, dma_addr_t dma) {
    return 0;
}

static inline dma_addr_t skb_frag_dma_map(struct device *dev, struct skb_frag_struct *frag, int offset, int size, int dir) {
    return 0;
}

static inline void dma_unmap_page(struct device *dev, dma_addr_t dma, int length, int dir) {
}

static inline void dma_unmap_single(struct device *dev, dma_addr_t dma, int length, int dir) {
}

static inline void netdev_err(struct net_device *dev, const char *fmt, ...) {
}

static inline struct netdev_queue *netdev_get_tx_queue(struct net_device *dev, int queue) {
    return NULL;
}

static inline void netdev_tx_sent_queue(struct netdev_queue *queue, int len) {
}

static inline void netif_trans_update(struct net_device *dev) {
}

static inline void netif_stop_subqueue(struct net_device *dev, int queue) {
}

static inline void dev_kfree_skb_any(struct sk_buff *skb) {
}

static inline struct device *ring_to_dev(struct hnae_ring *ring) {
    return NULL;
}

static inline void unfill_desc(struct hnae_ring *ring) {
}

static inline void hnae_queue_xmit(void *qs, int buf_num) {
}

#define wmb() __asm__ __volatile__("" ::: "memory")
#define smp_mb() __asm__ __volatile__("" ::: "memory")