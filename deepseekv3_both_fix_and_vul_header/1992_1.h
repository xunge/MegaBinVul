#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stddef.h>

typedef struct BusState BusState;
typedef struct DeviceState DeviceState;
typedef struct PCIDevice PCIDevice;
typedef struct PCIDeviceInfo PCIDeviceInfo;

struct BusState {
    DeviceState *children;
};

struct DeviceState {
    DeviceState *sibling;
    void *info;
};

struct PCIDevice {
    DeviceState qdev;
    uint8_t devfn;
};

struct PCIDeviceInfo {
    DeviceState qdev;
    int no_hotplug;
};

#define QLIST_FOREACH_SAFE(var, head, field, next_var) \
    for ((var) = *(head); (var) && ((next_var) = (var)->field, 1); (var) = (next_var))

#define DO_UPCAST(type, field, dev) \
    ((type *)((char *)(dev) - offsetof(type, field)))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define PCI_SLOT(devfn) (((devfn) >> 3) & 0x1f)

#define PIIX4_DPRINTF(fmt, ...) 

static inline void qdev_free(DeviceState *dev) {
    free(dev);
}