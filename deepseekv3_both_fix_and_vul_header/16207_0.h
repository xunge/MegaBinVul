#include <stdint.h>
#include <stdbool.h>

struct amd_iommu_dte {
    uint16_t domain_id;
    uint64_t pt_root;
    bool iw;
    bool ir;
    uint8_t paging_mode;
    bool tv;
    bool v;
};

static inline uint64_t paddr_to_pfn(uint64_t addr) {
    return addr >> 12;
}