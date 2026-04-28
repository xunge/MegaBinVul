#include <stdint.h>

typedef struct VirtIODevice VirtIODevice;

#define VIRTIO_NET_F_MAC 5
#define VIRTIO_NET_F_CSUM 0
#define VIRTIO_NET_F_HOST_TSO4 11
#define VIRTIO_NET_F_HOST_TSO6 12
#define VIRTIO_NET_F_HOST_ECN 13
#define VIRTIO_NET_F_GUEST_CSUM 1
#define VIRTIO_NET_F_GUEST_TSO4 7
#define VIRTIO_NET_F_GUEST_TSO6 8
#define VIRTIO_NET_F_GUEST_ECN 10

uint32_t virtio_net_get_features(VirtIODevice *vdev);