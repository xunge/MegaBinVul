#include <stdint.h>
#include <stddef.h>

#define DMA_SLOT_SIZE 4096

struct ishtp_device {
    void *ishtp_host_dma_tx_buf;
    struct device *devc;
    unsigned long ishtp_dma_tx_lock;
    int ishtp_dma_num_slots;
    uint8_t *ishtp_dma_tx_map;
};

struct device {
    int dummy;
};

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define dev_err(dev, fmt, ...) ((void)0)