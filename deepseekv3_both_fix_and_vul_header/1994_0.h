#include <stdint.h>

#define VIRTIO_PCI_QUEUE_MAX 8

typedef struct VirtQueue VirtQueue;

typedef struct VirtIODevice {
    VirtQueue *vq[VIRTIO_PCI_QUEUE_MAX];
} VirtIODevice;

void virtio_queue_notify_vq(VirtQueue *vq);