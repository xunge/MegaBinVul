#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t u8;

struct domain;
struct amd_iommu;

struct pci_dev {
    u8 bus;
    uint8_t devfn;
};

#define PCI_BDF2(bus, devfn) (((bus) << 8) | (devfn))
#define BUG_ON(condition) do { if (condition) __builtin_trap(); } while (0)
#define ASSERT(condition) do { if (!(condition)) __builtin_trap(); } while (0)
#define smp_wmb() __asm__ __volatile__("": : :"memory")

#define IOMMU_DEV_TABLE_INT_CONTROL_ABORTED 0
#define IOMMU_DEV_TABLE_SYS_MGT_DMA_ABORTED 0
#define IOMMU_DEV_TABLE_IO_CONTROL_ABORTED 0
#define AMD_IOMMU_DEBUG(fmt, ...)

struct amd_iommu_dte {
    bool tv;
    bool v;
    bool iv;
    bool gv;
    bool i;
    bool ex;
    bool sa;
    bool se;
    bool sd;
    uint32_t int_ctl;
    uint32_t sys_mgt;
    uint32_t ioctl;
};

struct domain {
    int domain_id;
};

struct amd_iommu {
    struct {
        struct amd_iommu_dte *buffer;
    } dev_table;
    unsigned long lock;
    unsigned int seg;
};

extern struct domain *dom_io;
extern int get_dma_requestor_id(unsigned int seg, unsigned int bdf);
extern void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
extern void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
extern bool pci_ats_device(unsigned int seg, uint8_t bus, uint8_t devfn);
extern bool pci_ats_enabled(unsigned int seg, uint8_t bus, uint8_t devfn);
extern void disable_ats_device(struct pci_dev *pdev);
extern bool pcidevs_locked();
extern void amd_iommu_flush_device(struct amd_iommu *iommu, int req_id);
extern struct amd_iommu *dom_iommu(const struct domain *domain);