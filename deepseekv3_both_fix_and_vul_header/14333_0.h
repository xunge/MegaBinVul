#include <linux/types.h>
#include <linux/dma-buf.h>

struct tee_shm {
    unsigned long flags;
    struct dma_buf *dmabuf;
};

#define TEE_SHM_DMA_BUF (1 << 0)

void tee_shm_release(struct tee_shm *shm);