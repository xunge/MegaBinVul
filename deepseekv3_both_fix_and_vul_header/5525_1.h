#include <stdint.h>

struct xen_pcibk_dev_data {
    int enable_intx;
    int permissive;
};

struct pci_cmd_info {
    uint16_t val;
};

struct pci_dev {
    int is_busmaster;
};

static int verbose_request;
static int permissive;

#define DRV_NAME "xen_pciback"
#define PCI_COMMAND_INVALIDATE (1 << 5)
#define PCI_COMMAND_GUEST (0x1FF)
#define PCI_COMMAND_MEMORY (1 << 1)
#define PCI_COMMAND_MASTER (1 << 2)
#define KERN_DEBUG ""

typedef uint16_t u16;

static inline int is_enable_cmd(u16 value) { return value & PCI_COMMAND_MEMORY; }
static inline int is_master_cmd(u16 value) { return value & PCI_COMMAND_MASTER; }