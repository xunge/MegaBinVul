#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define PCI_MSIX_TABLE_BIR 0x7
#define PCI_MSIX_FLAGS_QSIZE 0x7FF
#define PCI_MSIX_ENTRY_SIZE 16
#define PCI_MSIX_PBA_OFFSET 0xFFFFF800
#define PCI_MSIX_ENTRY_CTRL_MASKBIT 0x40000000
#define MAX_PAGE_SIZE 4096
#define PAGE_SIZE 4096
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define ENOMEM 12
#define EINVAL 22

typedef uint32_t u32;

struct kvm;

struct vfio_pci_msi_entry {
    struct {
        uint32_t ctrl;
    } config;
};

struct vfio_pci_msix_pba {
    int bar;
    size_t size;
    void *guest_phys_addr;
};

struct vfio_pci_msix_table {
    int bar;
    size_t size;
    void *guest_phys_addr;
};

struct msix_cap {
    uint16_t ctrl;
    uint32_t table_offset;
    uint32_t pba_offset;
};

struct vfio_region_info {
    size_t size;
};

struct vfio_pci_device {
    struct {
        struct msix_cap *hdr;
        int pos;
        struct vfio_pci_msi_entry *entries;
        size_t nr_entries;
    } msix;
    struct vfio_pci_msix_pba msix_pba;
    struct vfio_pci_msix_table msix_table;
    struct msix_cap hdr;
};

struct vfio_device {
    struct vfio_pci_device pci;
};

void *pci_get_mmio_block(size_t size);
int vfio_pci_get_region_info(struct vfio_device *vdev, int bar, struct vfio_region_info *info);
void die(const char *msg);
void pr_err(const char *msg);
struct msix_cap *PCI_CAP(struct msix_cap *hdr, int pos);