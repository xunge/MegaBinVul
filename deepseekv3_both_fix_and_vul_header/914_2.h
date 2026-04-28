#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct domain {
    // dummy definition
};

struct pci_dev {
    uint16_t seg;
    uint8_t bus;
    struct domain *domain;
    // other members as needed
};

struct ivrs_mappings {
    int unity_map_enable;
    uint64_t addr_range_start;
    uint64_t addr_range_length;
    int write_permission;
    int read_permission;
};

extern struct domain *hardware_domain;
extern struct ivrs_mappings *get_ivrs_mappings(uint16_t seg);
extern int get_dma_requestor_id(uint16_t seg, int bdf);
extern int PCI_BDF2(uint8_t bus, uint8_t devfn);
extern int amd_iommu_reserve_domain_unity_map(struct domain *d, uint64_t start,
                                             uint64_t length, int write, int read);
extern int reassign_device(struct domain *src, struct domain *dst, uint8_t devfn,
                          struct pci_dev *pdev);