#include <stdint.h>

typedef uint64_t target_phys_addr_t;

#define SYBORG_VIRTIO_CONFIG 0x100
#define SYBORG_VIRTIO_GUEST_FEATURES 0
#define SYBORG_VIRTIO_QUEUE_BASE 1
#define SYBORG_VIRTIO_QUEUE_SEL 2
#define SYBORG_VIRTIO_QUEUE_NOTIFY 3
#define SYBORG_VIRTIO_STATUS 4
#define SYBORG_VIRTIO_INT_ENABLE 5
#define SYBORG_VIRTIO_INT_STATUS 6

#define VIRTIO_PCI_QUEUE_MAX 8

#define DPRINTF(fmt, ...) 
#define BADF(fmt, ...) 

typedef struct VirtIODevice VirtIODevice;
typedef struct SyborgVirtIOProxy SyborgVirtIOProxy;

struct VirtIODevice {
    void (*set_features)(VirtIODevice *, uint32_t);
    uint32_t guest_features;
    uint32_t queue_sel;
    uint8_t status;
    uint8_t isr;
};

struct SyborgVirtIOProxy {
    VirtIODevice *vdev;
    uint32_t int_enable;
};

void virtio_config_writel(VirtIODevice *vdev, uint32_t offset, uint32_t value);
void virtio_reset(VirtIODevice *vdev);
void virtio_queue_set_addr(VirtIODevice *vdev, uint32_t queue_sel, uint32_t value);
void virtio_queue_notify(VirtIODevice *vdev, uint32_t value);
void virtio_set_status(VirtIODevice *vdev, uint8_t status);
void virtio_update_irq(VirtIODevice *vdev);