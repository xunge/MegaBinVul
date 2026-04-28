#include <stdatomic.h>
#include <fcntl.h>

#define TEE_SHM_DMA_BUF (1 << 0)
#define EINVAL 22
#define O_RDWR 02
#define O_CLOEXEC 02000000

struct tee_shm {
    unsigned long flags;
    atomic_int refcount;
    void *dmabuf;
};

extern const struct file_operations tee_shm_fops;

void tee_shm_put(struct tee_shm *shm);
void get_dma_buf(void *dmabuf);
void dma_buf_put(void *dmabuf);
int anon_inode_getfd(const char *name, const struct file_operations *fops, void *priv, int flags);
int dma_buf_fd(void *dmabuf, int flags);