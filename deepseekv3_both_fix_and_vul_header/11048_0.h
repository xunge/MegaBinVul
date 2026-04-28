#include <stdint.h>

typedef struct VirtIODevice VirtIODevice;
typedef struct VirtioDeviceClass VirtioDeviceClass;

#define VIRTIO_DEVICE_GET_CLASS(obj) ((VirtioDeviceClass *)obj)

struct VirtioDeviceClass {
    void (*get_config)(VirtIODevice *vdev, uint8_t *config);
};

struct VirtIODevice {
    uint8_t *config;
    uint32_t config_len;
};

static inline uint16_t lduw_p(const void *ptr) {
    return *(const uint16_t *)ptr;
}