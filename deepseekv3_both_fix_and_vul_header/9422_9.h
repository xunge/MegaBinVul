#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define VIRTIO_PCI_QUEUE_MAX 8
#define VIRTIO_NO_VECTOR 0

typedef struct QEMUFile QEMUFile;
typedef struct DeviceState DeviceState;

typedef struct BusState {
    DeviceState *parent;
} BusState;

struct VirtQueue {
    struct {
        uint32_t num;
        uint32_t align;
    } vring;
    uint64_t pa;
    uint16_t last_avail_idx;
    bool signalled_used_valid;
    bool notification;
};

typedef struct VirtIODevice {
    uint8_t status;
    uint8_t isr;
    uint16_t queue_sel;
    uint32_t config_len;
    uint8_t *config;
    struct VirtQueue vq[VIRTIO_PCI_QUEUE_MAX];
} VirtIODevice;

typedef struct VirtioBusClass {
    int (*load_config)(DeviceState *d, QEMUFile *f);
    uint32_t (*get_features)(DeviceState *d);
    bool has_variable_vring_alignment;
    int (*load_queue)(DeviceState *d, int n, QEMUFile *f);
} VirtioBusClass;

#define DEVICE(obj) ((DeviceState *)(obj))
#define VIRTIO_BUS_GET_CLASS(obj) ((VirtioBusClass *)obj)

void error_report(const char *fmt, ...);
uint16_t vring_avail_idx(struct VirtQueue *vq);
void virtqueue_init(struct VirtQueue *vq);
void virtio_notify_vector(VirtIODevice *vdev, uint16_t vector);
int virtio_set_features(VirtIODevice *vdev, uint32_t features);
BusState *qdev_get_parent_bus(DeviceState *dev);
void qemu_get_8s(QEMUFile *f, uint8_t *pv);
void qemu_get_be16s(QEMUFile *f, uint16_t *pv);
void qemu_get_be32s(QEMUFile *f, uint32_t *pv);
uint32_t qemu_get_be32(QEMUFile *f);
void qemu_get_buffer(QEMUFile *f, void *pv, size_t size);
uint64_t qemu_get_be64(QEMUFile *f);