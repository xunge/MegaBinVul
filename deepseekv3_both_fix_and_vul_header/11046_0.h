#include <stdint.h>

typedef struct VirtIODevice VirtIODevice;
typedef struct VirtioDeviceClass VirtioDeviceClass;

#define VIRTIO_DEVICE_GET_CLASS(obj) ((VirtioDeviceClass *)obj)

struct VirtIODevice {
    uint8_t *config;
    uint32_t config_len;
};

struct VirtioDeviceClass {
    void (*get_config)(VirtIODevice *vdev, uint8_t *config);
};

static inline uint32_t ldl_p(const uint8_t *p) {
    uint32_t val;
    __builtin_memcpy(&val, p, sizeof(val));
    return val;
}