#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

struct pci_dev {
    uint8_t bus;
    uint8_t devfn;
    uint8_t type;
};

struct domain {
    int domain_id;
};

struct amd_iommu {
    int seg;
    struct {
        void *buffer;
    } dev_table;
    struct {
        void *ats_devices;
    };
    unsigned long lock;
};

struct domain_iommu {
    struct {
        struct {
            void *root_table;
            int paging_mode;
        } amd;
    } arch;
};

struct amd_iommu_dte {
    unsigned v:1;
    unsigned tv:1;
    unsigned it_root:1;
    unsigned int_ctl:1;
    unsigned iv:1;
    unsigned ex:1;
    unsigned sys_mgt:1;
    unsigned i:1;
};

struct ivrs_mappings {
    unsigned dte_allow_exclusion:1;
    unsigned device_flags;
};

#define PCI_BDF2(bus, devfn) (((bus) << 8) | (devfn))
#define MASK_EXTR(val, mask) (((val) & (mask)) >> __builtin_ctz(mask))
#define PRIx64 "llx"

#define IOMMU_DEV_TABLE_INT_CONTROL_TRANSLATED 1
#define ACPI_IVHD_SYSTEM_MGMT 0x01
#define PCI_CAP_IOTLB_SHIFT 8
#define INV_IOMMU_ALL_PAGES_ADDRESS (~0ULL)

extern int iommu_hwdom_passthrough;
extern int iommu_intremap;
extern int ats_enabled;

static inline int is_hardware_domain(struct domain *d) { return 0; }
static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline int get_dma_requestor_id(int seg, int bdf) { return 0; }
static inline const struct ivrs_mappings *get_ivrs_mappings(int seg) { return NULL; }
static inline int pci_ats_device(int seg, int bus, int devfn) { return 0; }
static inline int iommu_has_cap(struct amd_iommu *iommu, int cap) { return 0; }
static inline int pci_ats_enabled(int seg, int bus, int devfn) { return 0; }
static inline void enable_ats_device(struct pci_dev *pdev, void *list) {}
static inline void amd_iommu_flush_device(struct amd_iommu *iommu, int req_id) {}
static inline void amd_iommu_flush_iotlb(int devfn, struct pci_dev *pdev, uint64_t addr, int size) {}
static inline void amd_iommu_set_root_page_table(struct amd_iommu_dte *dte, uint64_t maddr, int domid, int mode, int valid) {}
static inline uint64_t page_to_maddr(void *page) { return 0; }
static inline int pcidevs_locked() { return 1; }

#define BUG_ON(cond) do { if (cond) __builtin_trap(); } while (0)
#define ASSERT(cond) do { if (!(cond)) __builtin_trap(); } while (0)
#define spin_lock_irqsave(lock, flags) (void)flags
#define spin_unlock_irqrestore(lock, flags) (void)flags
#define AMD_IOMMU_DEBUG(fmt, ...)