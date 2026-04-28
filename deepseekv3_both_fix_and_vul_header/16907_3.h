#include <stdint.h>
#include <stddef.h>

#define VMXNET3_INIT_GEN 1
#define VMXNET3_RXD_BTYPE_HEAD 0
#define VMXNET3_RXD_BTYPE_BODY 1
#define DMA_FROM_DEVICE 1
#define __BIG_ENDIAN_BITFIELD 1

typedef uint32_t u32;
typedef uint64_t dma_addr_t;

struct Vmxnet3_RxDesc {
    u32 btype;
    dma_addr_t addr;
    u32 len;
};

struct vmxnet3_rx_ring_base {
    struct Vmxnet3_RxDesc rxd;
};

struct vmxnet3_rx_ring {
    struct vmxnet3_rx_ring_base *base;
    u32 size;
    u32 gen;
    u32 next2fill;
    u32 next2comp;
};

struct vmxnet3_comp_ring {
    u32 gen;
    u32 next2proc;
};

struct vmxnet3_buf_info {
    void *skb;
    void *page;
};

struct vmxnet3_rx_queue {
    struct vmxnet3_rx_ring rx_ring[2];
    struct vmxnet3_comp_ring comp_ring;
    struct vmxnet3_buf_info **buf_info;
};

struct pci_dev {
    void *dev;
};

struct vmxnet3_adapter {
    struct pci_dev *pdev;
};

void vmxnet3_getRxDesc(struct Vmxnet3_RxDesc *rxd, struct Vmxnet3_RxDesc *src, struct Vmxnet3_RxDesc *dst);
void dma_unmap_single(void *dev, dma_addr_t addr, u32 len, int direction);
void dma_unmap_page(void *dev, dma_addr_t addr, u32 len, int direction);
void dev_kfree_skb(void *skb);
void put_page(void *page);