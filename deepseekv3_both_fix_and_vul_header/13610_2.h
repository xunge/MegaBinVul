#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef uint64_t dma_addr_t;

struct sk_buff {
    unsigned char *data;
};

struct net_device;
struct pci_dev;

struct ql_rcv_buf_cb {
    int index;
    struct sk_buff *skb;
    dma_addr_t mapaddr;
    size_t maplen;
    uint32_t buf_phy_addr_low;
    uint32_t buf_phy_addr_high;
};

struct ql3_adapter {
    struct net_device *ndev;
    struct pci_dev *pdev;
    int num_large_buffers;
    int lrg_buffer_len;
    struct ql_rcv_buf_cb *lrg_buf;
};

#define QL_HEADER_SPACE 0
#define LS_64BITS(addr) ((uint32_t)(addr))
#define MS_64BITS(addr) ((uint32_t)(((uint64_t)(addr)) >> 32))
#define unlikely(x) (x)
#define cpu_to_le32(x) (x)
#define PCI_DMA_FROMDEVICE 0
#define ENOMEM 12

static inline struct sk_buff *netdev_alloc_skb(struct net_device *dev, int len) { return 0; }
static inline void netdev_err(struct net_device *dev, const char *fmt, ...) {}
static inline void ql_free_large_buffers(struct ql3_adapter *qdev) {}
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline dma_addr_t pci_map_single(struct pci_dev *pdev, void *ptr, int size, int dir) { return 0; }
static inline int pci_dma_mapping_error(struct pci_dev *pdev, dma_addr_t addr) { return 0; }
#define dma_unmap_addr_set(ptr, name, val) ((ptr)->name = (val))
#define dma_unmap_len_set(ptr, name, val) ((ptr)->name = (val))