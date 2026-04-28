#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

#define TEE_SHM_DMA_BUF     0x1
#define TEE_SHM_USER_MAPPED 0x2
#define TEE_SHM_KERNEL_MAPPED 0x4
#define TEE_SHM_REGISTER    0x8

#define ENOTSUPP 524
#define EINVAL 22
#define ENOMEM 12

#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define FOLL_WRITE 0x01
#define O_RDWR 02

struct page;
struct tee_shm;
struct tee_context;

struct tee_device_ops {
    int (*shm_register)(struct tee_context *ctx, struct tee_shm *shm,
                       struct page **pages, unsigned int num_pages,
                       unsigned long start);
    int (*shm_unregister)(struct tee_context *ctx, struct tee_shm *shm);
};

struct tee_device_desc {
    struct tee_device_ops *ops;
};

struct tee_device {
    void *mutex;
    void *idr;
    struct tee_device_desc *desc;
};

struct tee_context {
    struct tee_device *teedev;
};

struct tee_shm {
    u32 flags;
    struct tee_context *ctx;
    int id;
    size_t size;
    size_t offset;
    struct page **pages;
    unsigned int num_pages;
    void *dmabuf;
    int refcount;
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

struct kvec {
    void *iov_base;
    size_t iov_len;
};

#define ERR_PTR(x) ((void *)(long)(x))
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_CAST(x) ((void *)(x))
#define DEFINE_DMA_BUF_EXPORT_INFO(name) \
    struct dma_buf_export_info name = {0}

static inline unsigned long untagged_addr(unsigned long addr) { return addr; }
static inline unsigned long rounddown(unsigned long x, unsigned long y) { return x; }
static inline unsigned long roundup(unsigned long x, unsigned long y) { return x; }

void *kzalloc(size_t size, int flags);
void *kcalloc(size_t n, size_t size, int flags);
void kfree(void *ptr);
int pin_user_pages_fast(unsigned long start, int nr_pages, int gup_flags, struct page **pages);
int get_kernel_pages(struct kvec *kiov, int nr_pages, int write, struct page **pages);
void release_registered_pages(struct tee_shm *shm);
bool tee_device_get(struct tee_device *teedev);
void tee_device_put(struct tee_device *teedev);
void teedev_ctx_get(struct tee_context *ctx);
void teedev_ctx_put(struct tee_context *ctx);
void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);
int idr_alloc(void *idr, void *ptr, int start, int end, int gfp_mask);
void idr_remove(void *idr, int id);
extern const struct dma_buf_ops tee_shm_dma_buf_ops;
void *dma_buf_export(const struct dma_buf_export_info *exp_info);