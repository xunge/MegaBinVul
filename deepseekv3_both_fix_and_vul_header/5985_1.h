#include <unistd.h>
#include <stdlib.h>

struct virtio_dev {
    // minimal empty struct definition
};

struct virtio_net {
    int tapfd;
    struct virtio_dev base;
};

void virtio_reset_dev(struct virtio_dev *dev);
void pr_err(const char *fmt, ...);