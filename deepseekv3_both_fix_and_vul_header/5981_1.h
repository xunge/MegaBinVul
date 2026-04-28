#include <pthread.h>
#include <stdlib.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};

struct virtio_coreu {
    pthread_mutex_t mtx;
    pthread_mutex_t rx_mtx;
    pthread_cond_t rx_cond;
    pthread_t rx_tid;
};