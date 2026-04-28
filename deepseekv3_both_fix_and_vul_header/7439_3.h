#include <stdint.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct VirtQueue VirtQueue;
typedef struct VirtQueueElement VirtQueueElement;
typedef struct virtio_vsock_event virtio_vsock_event;
typedef struct VirtIODevice VirtIODevice;

typedef struct VHostVSockCommon {
    VirtQueue *event_vq;
} VHostVSockCommon;

struct virtio_vsock_event {
    uint32_t id;
};

struct VirtQueueElement {
    struct iovec *in_sg;
    unsigned int in_num;
    struct iovec *out_sg;
    unsigned int out_num;
};

#define VIRTIO_VSOCK_EVENT_TRANSPORT_RESET 0
#define cpu_to_le32(x) (x)
#define VIRTIO_DEVICE(obj) ((VirtIODevice *)(obj))

void error_report(const char *fmt, ...);
void g_free(void *ptr);
size_t iov_from_buf(const struct iovec *iov, unsigned int iov_cnt, size_t offset, const void *buf, size_t bytes);
VirtQueueElement *virtqueue_pop(VirtQueue *vq, size_t sz);
void virtqueue_push(VirtQueue *vq, VirtQueueElement *elem, size_t len);
void virtio_notify(VirtIODevice *vdev, VirtQueue *vq);