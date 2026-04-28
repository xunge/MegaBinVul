#include <stdint.h>

typedef struct VirtIODevice {
    uint8_t *config;
    uint32_t config_len;
} VirtIODevice;

typedef struct VirtioDeviceClass {
    void (*set_config)(VirtIODevice *vdev, uint8_t *config);
} VirtioDeviceClass;

#define VIRTIO_DEVICE_GET_CLASS(obj) ((VirtioDeviceClass *)obj)

static inline void stw_p(uint8_t *ptr, uint16_t v) {
    ptr[0] = v & 0xff;
    ptr[1] = (v >> 8) & 0xff;
}