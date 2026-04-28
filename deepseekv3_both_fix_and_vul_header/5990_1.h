#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct vmctx;

struct pci_vdev {
    void *arg;
};

struct virtio_ipu {
    struct {
        int ipu_kstatus;
        int ipu_fd;
    } vbs_k;
    pthread_mutex_t mtx;
};

#define LDBG 0
#define IPRINTF(level, fmt, ...)

enum {
    VIRTIO_DEV_STARTED,
    VIRTIO_DEV_INITIAL
};

void virtio_ipu_k_stop(struct virtio_ipu *ipu);
void virtio_ipu_k_reset(struct virtio_ipu *ipu);