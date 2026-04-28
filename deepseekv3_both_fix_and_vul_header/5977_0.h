#include <stdlib.h>
#include <pthread.h>

struct virtio_mei {
    void *reset_mevp;
    pthread_mutex_t mutex;
    void *base;
    void *config;
};

void virtio_reset_dev(void *base);