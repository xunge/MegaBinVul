#include <unistd.h>
#include <stdlib.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};
struct virtio_hyper_dmabuf;

#define VIRTIO_DEV_STARTED 1
#define VIRTIO_DEV_INITIAL 0

extern int kstatus;
extern int vbs_k_hyper_dmabuf_fd;

void virtio_hyper_dmabuf_k_stop(void);
void virtio_hyper_dmabuf_k_reset(void);
void DPRINTF(const char *fmt, ...);