#include <stddef.h>

typedef struct Error Error;
typedef struct DeviceState DeviceState;
typedef struct MemoryRegion MemoryRegion;

typedef struct stellaris_enet_state {
    MemoryRegion *mmio;
} stellaris_enet_state;

#define STELLARIS_ENET(dev) ((stellaris_enet_state *)(dev))
#define DEVICE(obj) ((DeviceState *)(obj))

void unregister_savevm(DeviceState *dev, const char *id, void *opaque);
void memory_region_destroy(MemoryRegion *mr);