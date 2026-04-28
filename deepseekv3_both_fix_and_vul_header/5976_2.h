#include <stdint.h>
#include <stdatomic.h>

#define VIRTIO_F_NOTIFY_ON_EMPTY 24
#define VIRTIO_RING_F_EVENT_IDX 29
#define VRING_AVAIL_F_NO_INTERRUPT (1 << 0)

struct vring_used {
    uint16_t flags;
    uint16_t idx;
};

struct vring_avail {
    uint16_t flags;
    uint16_t idx;
};

struct virtio_base {
    uint32_t negotiated_caps;
};

struct virtio_vq_info {
    struct virtio_base *base;
    uint16_t save_used;
    struct vring_used *used;
    struct vring_avail *avail;
};

#define VQ_USED_EVENT_IDX(vq) (0)

void vq_interrupt(struct virtio_base *base, struct virtio_vq_info *vq);

#define atomic_thread_fence() __atomic_thread_fence(__ATOMIC_SEQ_CST)