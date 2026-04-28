#include <stdint.h>
#include <stdlib.h>

#define MWIFIEX_MAX_EVT_BD 256
#define MAX_EVENT_SIZE 2048
#define PCI_DMA_FROMDEVICE 2
#define ENOMEM 12
#define ERROR 0
#define EVENT 1

struct mwifiex_adapter {
    struct pcie_service_card *card;
};

struct pcie_service_card {
    void *evtbd_ring_vbase;
    struct sk_buff *evt_buf_list[MWIFIEX_MAX_EVT_BD];
    struct mwifiex_evt_buf_desc *evtbd_ring[MWIFIEX_MAX_EVT_BD];
};

struct sk_buff {
    unsigned int len;
    void *data;
};

struct mwifiex_evt_buf_desc {
    uint64_t paddr;
    uint16_t len;
    uint16_t flags;
};

typedef uint64_t dma_addr_t;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;

#define MWIFIEX_SKB_DMA_ADDR(skb) ((dma_addr_t)(skb))

static inline struct sk_buff *dev_alloc_skb(unsigned int length) { return malloc(sizeof(struct sk_buff)); }
static inline void skb_put(struct sk_buff *skb, unsigned int len) { skb->len = len; }
static inline void kfree(void *p) { free(p); }
static inline int mwifiex_map_pci_memory(struct mwifiex_adapter *adapter, struct sk_buff *skb, int size, int direction) { return 0; }
static inline void mwifiex_dbg(struct mwifiex_adapter *adapter, int level, const char *fmt, ...) {}