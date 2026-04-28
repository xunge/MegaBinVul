#include <stdint.h>

typedef struct VirtIODevice VirtIODevice;
typedef struct VirtioDeviceClass VirtioDeviceClass;

#define VIRTIO_DEVICE_GET_CLASS(obj) ((VirtioDeviceClass *)obj)

struct VirtIODevice {
    uint8_t *config;
    uint32_t config_len;
};

struct VirtioDeviceClass {
    void (*set_config)(VirtIODevice *vdev, uint8_t *config);
};

static inline void stl_p(uint8_t *ptr, uint32_t val) {
    ptr[0] = val;
    ptr[1] = val >> 8;
    ptr[2] = val >> 16;
    ptr[3] = val >> 24;
}