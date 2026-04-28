#include <stdlib.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define ENOMEM 12

struct device {
    struct device *parent;
    void (*release)(struct device *dev);
};

struct virtio_device {
    void *priv;
    struct device dev;
};

struct rpmsg_device_ops {
    // 这里需要定义ops结构体的成员
    // 由于原代码中没有使用具体成员，暂时留空
};

struct rpmsg_device {
    const struct rpmsg_device_ops *ops;
    struct device dev;
    int little_endian;
};

struct virtproc_info {
    struct virtio_device *vdev;
};

struct virtio_rpmsg_channel {
    struct virtproc_info *vrp;
    struct rpmsg_device rpdev;
};

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void kfree(void *ptr) {
    free(ptr);
}

const struct rpmsg_device_ops virtio_rpmsg_ops = {};
void virtio_rpmsg_release_device(struct device *dev) {}
int rpmsg_ctrldev_register_device(struct rpmsg_device *rpdev) { return 0; }
int virtio_is_little_endian(struct virtio_device *vdev) { return 1; }

#define ERR_PTR(err) ((void *)(long)(err))