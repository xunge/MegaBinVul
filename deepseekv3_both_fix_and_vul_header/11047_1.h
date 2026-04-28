#include <stdint.h>

typedef struct VirtIODevice {
    uint8_t *config;
    uint32_t config_len;
} VirtIODevice;

typedef struct VirtioDeviceClass {
    void (*set_config)(VirtIODevice *vdev, uint8_t *config);
} VirtioDeviceClass;

#define VIRTIO_DEVICE_GET_CLASS(obj) ((VirtioDeviceClass *)obj)

static inline void stb_p(uint8_t *ptr, uint8_t v) {
    *ptr = v;
}