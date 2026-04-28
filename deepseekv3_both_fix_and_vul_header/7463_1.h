#include <stddef.h>
#include <stdint.h>

typedef uint64_t phys_addr_t;

struct device {
    void *dma_io_tlb_mem;
};

enum dma_data_direction {
    DMA_BIDIRECTIONAL,
    DMA_TO_DEVICE,
    DMA_FROM_DEVICE,
    DMA_NONE
};

#define DMA_ATTR_NO_WARN (1 << 0)
#define DMA_ATTR_SKIP_CPU_SYNC (1 << 1)
#define DMA_ATTR_OVERWRITE (1 << 2)

#define CC_ATTR_MEM_ENCRYPT 0

struct io_tlb_slot {
    phys_addr_t orig_addr;
};

struct io_tlb_mem {
    phys_addr_t start;
    unsigned long nslabs;
    unsigned long used;
    struct io_tlb_slot *slots;
};

#define DMA_MAPPING_ERROR (~(phys_addr_t)0)