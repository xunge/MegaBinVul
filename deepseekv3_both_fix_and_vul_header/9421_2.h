#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define VIRTIO_PCI_QUEUE_MAX 8
#define VIRTIO_NO_VECTOR 0

typedef struct BusState BusState;
typedef struct VirtIODevice VirtIODevice;
typedef struct QEMUFile QEMUFile;
typedef struct DeviceState DeviceState;
typedef struct VirtioBusClass VirtioBusClass;
typedef struct VirtQueue VirtQueue;

struct BusState {
    void *parent;
};

struct VirtioBusClass {
    int (*load_config)(void *parent, QEMUFile *f);
    uint32_t (*get_features)(void *parent);
    bool has_variable_vring_alignment;
    int (*load_queue)(void *parent, int i, QEMUFile *f);
};

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

struct VirtIODevice {
    uint8_t status;
    uint8_t isr;
    uint16_t queue_sel;
    uint32_t config_len;
    uint8_t *config;
    VirtQueue vq[VIRTIO_PCI_QUEUE_MAX];
};

struct DeviceState {
    // Minimal definition for DEVICE macro
};

#define DEVICE(obj) ((DeviceState *)(obj))
#define VIRTIO_BUS_GET_CLASS(obj) ((VirtioBusClass *)object_get_class(obj))

static inline uint16_t vring_avail_idx(VirtQueue *vq) { return 0; }
static inline void virtqueue_init(VirtQueue *vq) {}
static inline int virtio_set_features(VirtIODevice *vdev, uint32_t features) { return 0; }
static inline void virtio_notify_vector(VirtIODevice *vdev, uint16_t vector) {}
static inline BusState *qdev_get_parent_bus(DeviceState *dev) { return NULL; }
static inline VirtioBusClass *object_get_class(void *obj) { return NULL; }

void qemu_get_8s(QEMUFile *f, uint8_t *pv);
void qemu_get_be16s(QEMUFile *f, uint16_t *pv);
void qemu_get_be32s(QEMUFile *f, uint32_t *pv);
uint32_t qemu_get_be32(QEMUFile *f);
uint64_t qemu_get_be64(QEMUFile *f);
void qemu_get_buffer(QEMUFile *f, uint8_t *buf, int size);
void error_report(const char *fmt, ...);