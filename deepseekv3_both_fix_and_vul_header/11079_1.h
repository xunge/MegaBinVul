#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ObjectClass ObjectClass;
typedef struct DeviceClass DeviceClass;
typedef struct SysBusDeviceClass SysBusDeviceClass;

#define DEVICE_CLASS(klass) ((DeviceClass *)(klass))
#define SYS_BUS_DEVICE_CLASS(klass) ((SysBusDeviceClass *)(klass))

struct DeviceClass {
    void (*unrealize)(void);
    const char * const *props;
    const void *vmsd;
};

struct SysBusDeviceClass {
    void (*init)(void);
};

extern void stellaris_enet_init(void);
extern void stellaris_enet_unrealize(void);
extern const char * const stellaris_enet_properties[];
extern const void vmstate_stellaris_enet;