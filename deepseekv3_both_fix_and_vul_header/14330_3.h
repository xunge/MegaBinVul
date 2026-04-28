#include <stddef.h>
#include <stdlib.h>

struct tee_shm;
struct tee_device;
struct tee_shm_pool_mgr;
struct tee_shm_pool;

struct mutex {
    int dummy;
};

struct idr {
    int dummy;
};

struct device {
    struct device *parent;
};

struct tee_shm_pool_mgr_ops {
    void (*free)(struct tee_shm_pool_mgr *poolm, struct tee_shm *shm);
};

struct tee_shm_pool_mgr {
    struct tee_shm_pool_mgr_ops *ops;
};

struct tee_shm_pool {
    struct tee_shm_pool_mgr *dma_buf_mgr;
    struct tee_shm_pool_mgr *private_mgr;
};

struct tee_desc_ops {
    int (*shm_unregister)(struct tee_device *ctx, struct tee_shm *shm);
};

struct tee_desc {
    struct tee_desc_ops *ops;
};

struct tee_device {
    struct mutex mutex;
    struct idr idr;
    struct device dev;
    struct tee_shm_pool *pool;
    struct tee_desc *desc;
    struct tee_device *teedev;
};

struct tee_shm {
    unsigned long flags;
    int id;
    struct tee_device *ctx;
    struct tee_shm_pool *pool;
};

#define TEE_SHM_DMA_BUF  (1 << 0)
#define TEE_SHM_POOL     (1 << 1)
#define TEE_SHM_REGISTER (1 << 2)

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void idr_remove(struct idr *idr, int id);
void dev_err(struct device *dev, const char *fmt, ...);
void kfree(void *ptr);
void teedev_ctx_put(struct tee_device *ctx);
void tee_device_put(struct tee_device *teedev);
void release_registered_pages(struct tee_shm *shm);