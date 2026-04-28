#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint32_t dma_addr_t;

struct sk_buff {
    void *data;
};

struct page {};

struct device {};

struct net_device {};

struct pci_dev {
    struct device dev;
};

struct vmxnet3_rx_queue_stats {
    int rx_buf_alloc_failure;
};

struct vmxnet3_rx_buf_info {
    int buf_type;
    struct sk_buff *skb;
    struct page *page;
    dma_addr_t dma_addr;
    u32 len;
};

struct vmxnet3_cmd_ring {
    union Vmxnet3_GenericDesc *base;
    u32 next2fill;
    u32 next2comp;
    u32 gen;
};

struct vmxnet3_rx_queue {
    struct vmxnet3_rx_buf_info *buf_info[2];
    struct vmxnet3_cmd_ring rx_ring[2];
    struct vmxnet3_rx_queue_stats stats;
};

struct vmxnet3_adapter {
    struct net_device *netdev;
    struct pci_dev *pdev;
};

union Vmxnet3_GenericDesc {
    struct {
        u64 addr;
        u32 dword[2];
    } rxd;
    u32 dword[4];
};

enum {
    VMXNET3_RX_BUF_SKB,
    VMXNET3_RX_BUF_PAGE
};

enum {
    VMXNET3_RXD_BTYPE_HEAD,
    VMXNET3_RXD_BTYPE_BODY
};

#define VMXNET3_RXD_BTYPE_SHIFT 4
#define VMXNET3_RXD_GEN_SHIFT 31
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define GFP_ATOMIC 0
#define DMA_FROM_DEVICE 1
#define unlikely(x) (x)
#define BUG_ON(cond) do { if (cond) abort(); } while (0)

static inline u32 cpu_to_le32(u32 x) { return x; }
static inline u64 cpu_to_le64(u64 x) { return x; }

static inline void vmxnet3_cmd_ring_adv_next2fill(struct vmxnet3_cmd_ring *ring) {
    ring->next2fill++;
}

static inline struct sk_buff *__netdev_alloc_skb_ip_align(struct net_device *dev, u32 len, int gfp) {
    return NULL;
}

static inline dma_addr_t dma_map_single(struct device *dev, void *ptr, u32 size, int dir) {
    return 0;
}

static inline int dma_mapping_error(struct device *dev, dma_addr_t dma_addr) {
    return 0;
}

static inline void dev_kfree_skb_any(struct sk_buff *skb) {}

static inline struct page *alloc_page(int gfp) {
    return NULL;
}

static inline dma_addr_t dma_map_page(struct device *dev, struct page *page, u32 offset, u32 size, int dir) {
    return 0;
}

static inline void put_page(struct page *page) {}

static inline void netdev_dbg(struct net_device *dev, const char *fmt, ...) {}