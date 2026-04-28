#include <pthread.h>
#include <stdlib.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};

struct virtio_i2c {
    pthread_mutex_t req_mtx;
    pthread_mutex_t mtx;
};

extern void DPRINTF(const char *fmt, ...);
extern void virtio_i2c_req_stop(struct virtio_i2c *vi2c);
extern void native_adapter_remove(struct virtio_i2c *vi2c);