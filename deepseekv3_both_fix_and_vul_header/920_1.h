#include <stdint.h>
#include <stdbool.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t u32;

struct domain;
struct domain_iommu;
struct pci_dev;
struct vm_event;
struct p2m_domain;

#define EXDEV 18
#define ERESTART 85
#define ENODEV 19
#define EBUSY 16
#define XENLOG_G_WARNING ""

extern struct domain *dom_io;
extern struct domain *hardware_domain;
extern bool is_iommu_enabled(struct domain *d);
extern const struct domain_iommu *dom_iommu(struct domain *d);
extern bool is_hvm_domain(struct domain *d);
extern bool vm_event_check_ring(struct vm_event *);
extern struct p2m_domain *p2m_get_hostp2m(struct domain *d);
extern bool pcidevs_trylock(void);
extern void pcidevs_unlock(void);
extern struct pci_dev *pci_get_pdev(u16 seg, u8 bus, u8 devfn);
extern struct pci_dev *pci_get_pdev_by_domain(struct domain *d, u16 seg, u8 bus, u8 devfn);
extern int pci_reset_msix_state(struct pci_dev *pdev);
extern void msixtbl_init(struct domain *d);
extern void *pci_to_dev(struct pci_dev *pdev);
extern int printk(const char *fmt, ...);

#define PCI_SLOT(devfn) (((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn) ((devfn) & 0x07)

struct domain {
    int domain_id;
    struct {
        struct {
            bool mem_sharing_enabled;
        } hvm;
    } arch;
    struct vm_event *vm_event_paging;
};

struct domain_iommu {
    struct {
        int (*assign_device)(struct domain *d, u8 devfn, void *dev, u32 flag);
    } *platform_ops;
};

struct pci_dev {
    struct domain *domain;
    bool msix;
    u8 phantom_stride;
    u8 devfn;
    struct {
        int count;
    } fault;
    bool quarantine;
};

struct p2m_domain {
    bool global_logdirty;
};