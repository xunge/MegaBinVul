#include <stddef.h>
#include <stdbool.h>

struct port_buffer;
struct ports_device;
struct virtqueue;
struct virtio_device;

struct work_struct {
    unsigned long data;
};

struct device {
    int dummy;
};

struct ports_device {
    struct work_struct control_work;
    struct virtqueue *c_ivq;
    int c_ivq_lock;
    struct virtio_device *vdev;
};

struct port_buffer {
    size_t size;
    size_t len;
    size_t offset;
};

struct virtqueue {
    struct virtio_device *vdev;
};

struct virtio_device {
    struct device dev;
};

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define spin_lock(lock) (void)(lock)
#define spin_unlock(lock) (void)(lock)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define dev_warn(dev, fmt, ...) (void)(dev)

extern struct port_buffer *virtqueue_get_buf(struct virtqueue *vq, unsigned int *len);
extern int add_inbuf(struct virtqueue *vq, struct port_buffer *buf);
extern void free_buf(struct port_buffer *buf, bool reuse);
extern void handle_control_message(struct virtio_device *vdev, struct ports_device *portdev, struct port_buffer *buf);