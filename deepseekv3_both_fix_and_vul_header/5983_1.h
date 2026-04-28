#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct vmctx;

struct pci_vdev {
    void *arg;
};

struct virtio_audio_vbs_k {
    int kstatus;
    int audio_fd;
};

struct virtio_audio {
    struct virtio_audio_vbs_k vbs_k;
    pthread_mutex_t mtx;
};

#define DPRINTF(fmt, ...)
#define WPRINTF(fmt, ...)

#define VIRTIO_DEV_STARTED 1
#define VIRTIO_DEV_INITIAL 0

extern char *vbs_k_audio_dev_path;
extern void virtio_audio_kernel_stop(struct virtio_audio *);
extern void virtio_audio_kernel_reset(struct virtio_audio *);