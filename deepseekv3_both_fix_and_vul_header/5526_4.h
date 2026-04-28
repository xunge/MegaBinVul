#include <linux/pci.h>
#include <linux/types.h>

typedef unsigned short u16;

struct pci_dev {
    struct {
        unsigned long flags;
    } resource[6];
};

struct pci_cmd_info {
    u16 val;
};

#define PCI_COMMAND_GUEST 0
#define PCI_COMMAND_IO 0x1
#define PCI_COMMAND_MEMORY 0x2
#define PCI_ROM_RESOURCE 6
#define IORESOURCE_IO 0x00000100
#define IORESOURCE_MEM 0x00000200

extern int pci_read_config_word(struct pci_dev *dev, int offset, u16 *value);
extern int xen_pcibk_read_config_word(struct pci_dev *dev, int offset, u16 *value, void *data);
extern int pci_is_enabled(struct pci_dev *dev);