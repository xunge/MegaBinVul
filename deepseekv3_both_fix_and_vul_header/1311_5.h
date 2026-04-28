#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t hwaddr;

#define PCI_AIDX_BASE 0x1000
#define PCI_EJ_BASE 0x2000
#define PCI_SEL_BASE 0x3000
#define ACPI_PCIHP_MAX_HOTPLUG_BUS 256
#define ACPI_PCIHP_BSEL_DEFAULT 0

typedef struct AcpiPciHpState {
    uint32_t acpi_index;
    uint32_t hotplug_select;
    bool legacy_piix;
} AcpiPciHpState;

typedef struct BusChild {
    void *child;
    struct BusChild *sibling;
    struct BusChild *next;
} BusChild;

typedef struct PCIBus {
    struct {
        BusChild *children;
    } qbus;
} PCIBus;

typedef struct PCIDevice {
    uint8_t devfn;
} PCIDevice;

typedef struct Object {
    // Minimal definition
} Object;

#define OBJECT(obj) ((Object *)(obj))
#define PCI_DEVICE(obj) ((PCIDevice *)(obj))
#define PCI_SLOT(devfn) ((devfn) >> 3)

#define QTAILQ_FOREACH_SAFE(var, head, field, next_var) \
    for ((var) = (*(head)); \
        (var) != NULL && ((next_var) = (var)->sibling, 1); \
        (var) = (next_var))

static inline int ctz32(uint32_t val) {
    if (val == 0) return 32;
    return __builtin_ctz(val);
}

static inline PCIBus* acpi_pcihp_find_hotplug_bus(AcpiPciHpState *s, uint32_t select) {
    return NULL;
}

static inline void acpi_pcihp_eject_slot(AcpiPciHpState *s, uint32_t select, uint64_t data) {
}

static inline void trace_acpi_pci_acpi_index_write(uint32_t select, int slot, uint32_t index) {
}

static inline void trace_acpi_pci_ej_write(hwaddr addr, uint64_t data) {
}

static inline void trace_acpi_pci_sel_write(hwaddr addr, uint64_t data) {
}

static inline uint32_t object_property_get_uint(Object *o, const char *prop, void *errp) {
    return 0;
}