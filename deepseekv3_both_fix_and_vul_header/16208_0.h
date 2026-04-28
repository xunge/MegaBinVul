#include <stdbool.h>

struct amd_iommu_dte {
    unsigned long it_root;
    unsigned int int_tab_len;
    unsigned int int_ctl;
    bool ig;
    bool iv;
};

struct amd_iommu;

#define IOMMU_DEV_TABLE_INT_CONTROL_TRANSLATED 1
#define IOMMU_DEV_TABLE_INT_CONTROL_ABORTED 0

unsigned long virt_to_maddr(const void *ptr);
unsigned int amd_iommu_intremap_table_order(const void *ptr, const struct amd_iommu *iommu);