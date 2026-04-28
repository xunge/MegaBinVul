#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

#define PCI_CAP_IOTLB_SHIFT 0
#define INV_IOMMU_ALL_PAGES_ADDRESS 0
#define PCI_BDF2(bus, devfn) ((bus) << 8 | (devfn))

struct domain {
    int domain_id;
};

struct pci_dev {
    u8 bus;
    uint8_t devfn;
    int type;
};

struct domain_iommu {
    struct {
        void *root_table;
        int paging_mode;
    } arch;
};

struct amd_iommu_dte {
    int v;
    int tv;
    int i;
};

typedef struct {
    unsigned long flags;
} spinlock_t;

struct amd_iommu {
    int seg;
    struct {
        struct amd_iommu_dte *buffer;
    } dev_table;
    void *ats_devices;
    spinlock_t lock;
};

extern struct domain *dom_io;
extern int iommu_hwdom_passthrough;
extern int ats_enabled;

#define BUG_ON(condition) 
#define ASSERT(condition) 
#define AMD_IOMMU_DEBUG(fmt, ...) 
#define PRIx64 "llx"
#define spin_lock_irqsave(lock, flags) 
#define spin_unlock_irqrestore(lock, flags) 

static inline int is_hardware_domain(struct domain *d) { return 0; }
static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline uint64_t page_to_maddr(void *p) { return 0; }
static inline int get_dma_requestor_id(int seg, int bdf) { return 0; }
static inline int pci_ats_device(int seg, int bus, int devfn) { return 0; }
static inline int iommu_has_cap(struct amd_iommu *iommu, int cap) { return 0; }
static inline int pci_ats_enabled(int seg, int bus, int devfn) { return 0; }
static inline void enable_ats_device(struct pci_dev *pdev, void *list) {}
static inline void amd_iommu_flush_device(struct amd_iommu *iommu, int req_id) {}
static inline void amd_iommu_flush_iotlb(uint8_t devfn, struct pci_dev *pdev, uint64_t addr, int size) {}
static inline void amd_iommu_set_root_page_table(struct amd_iommu_dte *dte, uint64_t root, int domain_id, int mode, int valid) {}
static inline int pcidevs_locked() { return 1; }