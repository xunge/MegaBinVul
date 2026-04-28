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

static inline uint8_t ldub_p(const uint8_t *ptr) {
    return *ptr;
}