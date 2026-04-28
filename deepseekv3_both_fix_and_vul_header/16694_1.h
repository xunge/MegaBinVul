#include <stdint.h>
#include <sys/uio.h>

struct virtio_ops {
    const char *name;
};

struct virtio_dev {
    struct vmctx *vmctx;
};

struct virtio_base {
    struct virtio_ops *vops;
    struct virtio_dev *dev;
    uint32_t device_caps;
};

struct vring_desc {
    uint64_t addr;
    uint32_t len;
    uint16_t flags;
    uint16_t next;
};

struct vring_avail {
    uint16_t flags;
    uint16_t idx;
    uint16_t ring[];
};

struct virtio_vq_info {
    struct virtio_base *base;
    uint16_t last_avail;
    struct vring_avail *avail;
    uint16_t qsize;
    struct vring_desc *desc;
};

struct vmctx;

#define VRING_DESC_F_NEXT      1
#define VRING_DESC_F_INDIRECT  4
#define VIRTIO_RING_F_INDIRECT_DESC 28
#define VQ_MAX_DESCRIPTORS 1024

extern int pr_err(const char *fmt, ...);
extern int _vq_record(int i, volatile struct vring_desc *vdir, struct vmctx *ctx, struct iovec *iov, int n_iov, uint16_t *flags);
extern void *paddr_guest2host(struct vmctx *ctx, uint64_t addr, size_t len);