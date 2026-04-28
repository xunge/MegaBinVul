#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct vmctx;

struct pci_vdev {
    void *arg;
};

struct virtio_rnd_k {
    int status;
    int fd;
};

struct virtio_rnd {
    struct virtio_rnd_k vbs_k;
    pthread_t rx_tid;
    int fd;
};

#define DPRINTF(fmt, ...) 
#define VIRTIO_DEV_STARTED 1
#define VIRTIO_DEV_INITIAL 0

void virtio_rnd_kernel_stop(struct virtio_rnd *rnd);
void virtio_rnd_kernel_reset(struct virtio_rnd *rnd);