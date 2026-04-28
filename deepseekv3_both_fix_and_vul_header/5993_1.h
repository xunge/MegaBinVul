#include <stdint.h>
#include <stddef.h>

struct virtio_vq_info {
    struct vring_used *used;
};

struct vring_used {
    uint16_t flags;
};

struct virtio_net {
    int rx_ready;
};

#define VRING_USED_F_NO_NOTIFY (1 << 0)