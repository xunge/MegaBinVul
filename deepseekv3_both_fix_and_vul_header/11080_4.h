#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct SysBusDevice SysBusDevice;
typedef struct DeviceState {
    const char *id;
} DeviceState;
typedef struct MemoryRegion {
    void *ops;
    void *opaque;
    const char *name;
    uint32_t size;
} MemoryRegion;
typedef struct NICInfo NICInfo;
typedef struct NetClientInfo NetClientInfo;
typedef struct NetClientState NetClientState;
typedef struct QEMUFile QEMUFile;
typedef void *qemu_irq;

typedef struct {
    uint8_t a[6];
} MACAddr;

typedef struct {
    MACAddr macaddr;
} NICConf;

typedef struct MemoryRegionOps {
    void *read;
    void *write;
    void *exec;
    unsigned valid;
    unsigned endianness;
} MemoryRegionOps;

typedef struct stellaris_enet_state {
    MemoryRegion mmio;
    qemu_irq irq;
    NICConf conf;
    NICInfo *nic;
} stellaris_enet_state;

#define DEVICE(obj) ((DeviceState *)obj)
#define STELLARIS_ENET(obj) ((stellaris_enet_state *)obj)
#define OBJECT(obj) ((void *)obj)

extern const NetClientInfo net_stellaris_enet_info;
extern const MemoryRegionOps stellaris_enet_ops;

void memory_region_init_io(MemoryRegion *mr, void *opaque, const MemoryRegionOps *ops, void *obj, const char *name, uint32_t size);
void sysbus_init_mmio(SysBusDevice *dev, MemoryRegion *mr);
void sysbus_init_irq(SysBusDevice *dev, qemu_irq *irq);
void qemu_macaddr_default_if_unset(MACAddr *macaddr);
NICInfo *qemu_new_nic(const NetClientInfo *info, NICConf *conf, const char *model, const char *name, void *opaque);
void qemu_format_nic_info_str(NetClientState *nc, const uint8_t *macaddr);
NetClientState *qemu_get_queue(NICInfo *nic);
void stellaris_enet_reset(stellaris_enet_state *s);
void register_savevm(DeviceState *dev, const char *id, int instance_id, int version_id,
                    void (*save_state)(QEMUFile *f, void *opaque),
                    int (*load_state)(QEMUFile *f, void *opaque, int version_id),
                    void *opaque);
const char *object_get_typename(void *obj);
void stellaris_enet_save(QEMUFile *f, void *opaque);
int stellaris_enet_load(QEMUFile *f, void *opaque, int version_id);