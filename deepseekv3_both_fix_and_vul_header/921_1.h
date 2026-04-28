#include <stdint.h>

typedef uint16_t u16;
typedef uint8_t u8;

#define ENODEV 19
#define EBUSY 16

extern struct pci_dev *pci_get_pdev(u16 seg, u8 bus, u8 devfn);
extern struct pci_dev *pci_get_pdev_by_domain(int domain, u16 seg, u8 bus, u8 devfn);
extern void pcidevs_lock(void);
extern void pcidevs_unlock(void);

extern int hardware_domain;
extern int dom_io;

struct pci_dev {
    int domain;
};