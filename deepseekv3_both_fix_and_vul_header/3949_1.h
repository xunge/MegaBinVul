#include <stdint.h>
#include <stddef.h>

#define DMA_SLOT_SIZE 4096

typedef struct {
    int lock;
} spinlock_t;

struct ishtp_device {
    spinlock_t ishtp_dma_tx_lock;
    int ishtp_dma_num_slots;
    int *ishtp_dma_tx_map;
    void *ishtp_host_dma_tx_buf;
    void *devc;
};

void spin_lock_irqsave(spinlock_t *lock, unsigned long flags);
void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);
void dev_err(void *devc, const char *msg);