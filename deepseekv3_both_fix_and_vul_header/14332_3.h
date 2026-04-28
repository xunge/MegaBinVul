#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

#define ERR_PTR(err) ((void *)(intptr_t)(err))
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define ERR_CAST(ptr) ((void *)(ptr))
#define GFP_KERNEL 0
#define O_RDWR 02
#define EINVAL 22
#define ENOMEM 12

#define TEE_SHM_MAPPED 0x1
#define TEE_SHM_DMA_BUF 0x2
#define TEE_SHM_PRIV 0x4
#define TEE_SHM_POOL 0x8

struct device {
    struct device *parent;
};

struct mutex {
    int dummy;
};

struct idr {
    int dummy;
};

struct dma_buf {
    int dummy;
};

struct dma_buf_ops {
    int dummy;
};

struct dma_buf_export_info {
    const struct dma_buf_ops *ops;
    size_t size;
    int flags;
    void *priv;
};

#define DEFINE_DMA_BUF_EXPORT_INFO(name) \
    struct dma_buf_export_info name = {0}

struct tee_context {
    struct tee_device *teedev;
};

struct tee_shm_pool_mgr_ops {
    int (*alloc)(struct tee_shm_pool_mgr *, struct tee_shm *, size_t);
    void (*free)(struct tee_shm_pool_mgr *, struct tee_shm *);
};

struct tee_shm_pool_mgr {
    struct tee_shm_pool_mgr_ops *ops;
};

struct tee_shm_pool {
    struct tee_shm_pool_mgr *private_mgr;
    struct tee_shm_pool_mgr *dma_buf_mgr;
};

struct tee_shm {
    int refcount;
    u32 flags;
    struct tee_context *ctx;
    int id;
    struct dma_buf *dmabuf;
    size_t size;
};

struct tee_device {
    struct device dev;
    struct tee_shm_pool *pool;
    struct mutex mutex;
    struct idr idr;
};

extern int tee_device_get(struct tee_device *teedev);
extern void tee_device_put(struct tee_device *teedev);
extern void teedev_ctx_get(struct tee_context *ctx);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern int idr_alloc(struct idr *idr, void *ptr, int start, int end, int gfp);
extern void idr_remove(struct idr *idr, int id);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);
extern struct dma_buf *dma_buf_export(struct dma_buf_export_info *exp_info);
extern const struct dma_buf_ops tee_shm_dma_buf_ops;