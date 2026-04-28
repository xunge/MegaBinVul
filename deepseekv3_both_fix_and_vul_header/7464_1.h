#include <stddef.h>

struct device;

typedef unsigned long phys_addr_t;

enum dma_data_direction {
    DMA_BIDIRECTIONAL,
    DMA_TO_DEVICE,
    DMA_FROM_DEVICE,
    DMA_NONE
};

#define BUG_ON(condition) ((void)0)

extern void swiotlb_bounce(struct device *dev, phys_addr_t tlb_addr, size_t size, enum dma_data_direction dir);