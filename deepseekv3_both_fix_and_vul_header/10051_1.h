#include <stdint.h>
#include <string.h>

#define PCI_VENDOR_ID_INTEL 0x8086
#define PCI_DEVICE_ID_INTEL_ESB_9 0x25AB
#define PCI_CLASS_SYSTEM_OTHER 0x0
#define DEVICE_CATEGORY_MISC 0

typedef struct ObjectClass ObjectClass;
typedef struct DeviceClass DeviceClass;
typedef struct PCIDeviceClass PCIDeviceClass;

struct DeviceClass {
    void (*reset)(void);
    void *vmsd;
    unsigned long *categories;
};

struct PCIDeviceClass {
    void (*config_read)(void);
    void (*config_write)(void);
    void (*realize)(void);
    void (*exit)(void);
    uint16_t vendor_id;
    uint16_t device_id;
    uint16_t class_id;
};

#define DEVICE_CLASS(klass) ((DeviceClass *)(klass))
#define PCI_DEVICE_CLASS(klass) ((PCIDeviceClass *)(klass))

static inline void set_bit(int nr, unsigned long *addr) {
    addr[nr / (8 * sizeof(long))] |= (1UL << (nr % (8 * sizeof(long))));
}

extern void i6300esb_config_read(void);
extern void i6300esb_config_write(void);
extern void i6300esb_realize(void);
extern void i6300esb_exit(void);
extern void i6300esb_reset(void);
extern void *vmstate_i6300esb;