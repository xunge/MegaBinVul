#include <stdbool.h>
#include <stdatomic.h>

#define TEE_SHM_DMA_BUF (1 << 0)

struct tee_device;
struct tee_shm;

struct tee_shm {
    struct {
        struct tee_device *teedev;
    } *ctx;
    unsigned int flags;
    int id;
    _Atomic int refcount;
    void *dmabuf;
};

struct tee_device {
    struct {
        int dummy;
    } mutex;
    struct {
        int dummy;
    } idr;
};

void mutex_lock(struct {int dummy;} *mutex);
void mutex_unlock(struct {int dummy;} *mutex);
bool refcount_dec_and_test(_Atomic int *count);
void idr_remove(struct {int dummy;} *idr, int id);
void tee_shm_release(struct tee_device *teedev, struct tee_shm *shm);
void dma_buf_put(void *dmabuf);