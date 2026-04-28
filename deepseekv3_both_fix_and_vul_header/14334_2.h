#include <stddef.h>
#include <stdint.h>

#define ERR_PTR(err) ((void *)(intptr_t)(err))
#define EINVAL 22
#define TEE_SHM_DMA_BUF (1 << 0)

struct tee_device;
struct dma_buf;

struct tee_context {
    struct tee_device *teedev;
};

struct tee_device {
    void *mutex;
    void *idr;
};

struct tee_shm {
    struct tee_context *ctx;
    int refcount;
    unsigned long flags;
    struct dma_buf *dmabuf;
};

void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);
void *idr_find(void *idr, int id);
void refcount_inc(int *refcount);
void get_dma_buf(struct dma_buf *dmabuf);