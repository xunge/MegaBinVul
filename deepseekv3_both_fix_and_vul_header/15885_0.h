#include <stddef.h>
#include <string.h>

typedef struct VirtIODevice VirtIODevice;
typedef struct VirtQueue VirtQueue;
typedef struct VirtQueueElement VirtQueueElement;
typedef struct VirtIOSerial VirtIOSerial;
typedef struct iovec iovec;

struct VirtQueueElement {
    iovec *in_sg;
    unsigned int in_num;
};

struct VirtIOSerial {
    VirtQueue *c_ivq;
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

int virtio_queue_ready(VirtQueue *vq);
int virtqueue_pop(VirtQueue *vq, VirtQueueElement *elem);
void virtqueue_push(VirtQueue *vq, VirtQueueElement *elem, unsigned int len);
void virtio_notify(VirtIODevice *vdev, VirtQueue *vq);
void iov_from_buf(iovec *iov, unsigned int iov_cnt, size_t offset, const void *buf, size_t bytes);