#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define ACPI_PCIHP_MAX_HOTPLUG_BUS 256
#define PCI_UP_BASE 0
#define PCI_DOWN_BASE 1
#define PCI_EJ_BASE 2
#define PCI_RMV_BASE 3
#define PCI_SEL_BASE 4
#define ACPI_PCIHP_DPRINTF(fmt, ...) 

typedef uint64_t hwaddr;

typedef struct AcpiPciHpPciStatus {
    uint32_t up;
    uint32_t down;
    uint32_t hotplug_enable;
} AcpiPciHpPciStatus;

typedef struct AcpiPciHpState {
    AcpiPciHpPciStatus acpi_pcihp_pci_status[ACPI_PCIHP_MAX_HOTPLUG_BUS + 1];
    int hotplug_select;
    bool legacy_piix;
} AcpiPciHpState;