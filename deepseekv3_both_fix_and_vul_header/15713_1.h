#include <stddef.h>
#include <stdint.h>
#include <linux/pci.h>
#include <linux/errno.h>

#define PCI_VENDOR_ID_INTEL 0x8086
#define SKX_CPUNODEID 0
#define SKX_GIDNIDMAP 0
#define ICX_UPI_REGS_ADDR_FUNCTION 0
#define EPERM 1

typedef uint32_t u32;

struct pci_dev {
    struct {
        int number;
    } *bus;
};

struct intel_uncore_type {
    int num_boxes;
    struct intel_uncore_topology **topology;
};

struct intel_uncore_topology {
    // Define structure members as needed
};

static inline int uncore_max_dies(void) { return 0; }
static inline int upi_nodeid_groupid(struct pci_dev *dev, int skx_cpunodeid, int skx_gidnidmap, u32 *nid, u32 *gid) { return 0; }
static inline int upi_fill_topology(struct pci_dev *dev, struct intel_uncore_topology *upi, int idx) { return 0; }
static inline int pcibios_err_to_errno(int err) { return err; }
static inline struct pci_dev *pci_get_device(int vendor, int device, struct pci_dev *from) { return NULL; }
static inline struct pci_dev *pci_get_domain_bus_and_slot(int domain, int bus, int devfn) { return NULL; }
static inline int pci_domain_nr(struct pci_bus *bus) { return 0; }
static inline void pci_dev_put(struct pci_dev *dev) {}

#define GIDNIDMAP(gid, i) 0
#define PCI_DEVFN(slot, func) (((slot) << 3) | (func))