#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

struct domain;
struct domain_iommu {
    struct {
        int (*reassign_device)(struct domain *, struct domain *, uint8_t, void *);
    } *platform_ops;
};
struct pci_dev {
    bool quarantine;
    struct domain *domain;
    uint8_t phantom_stride;
    uint8_t devfn;
    struct {
        int count;
    } fault;
};

#define ASSERT(cond) ((void)0)
#define XENLOG_G_ERR 0
#define dprintk(level, fmt, ...) ((void)0)
#define printk(fmt, ...) ((void)0)

#define PCI_SLOT(devfn) (((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn) ((devfn) & 0x07)

extern struct domain *dom_io;
extern struct domain *hardware_domain;
extern bool iommu_quarantine;

static inline bool is_iommu_enabled(struct domain *d) { return false; }
static inline bool pcidevs_locked(void) { return true; }
static inline struct pci_dev *pci_get_pdev_by_domain(struct domain *d, uint16_t seg, uint8_t bus, uint8_t devfn) { return NULL; }
static inline void *pci_to_dev(struct pci_dev *pdev) { return NULL; }
static inline const struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }