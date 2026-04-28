#include <stdint.h>
#include <string.h>

typedef uint64_t mfn_t;
typedef uint64_t pfn_t;

#define _mfn(x) ((mfn_t)(x))
#define pfn_to_pde_idx(x, y) ((x) >> (12 + (y) * 9)) & 0x1ff

union amd_iommu_pte {
    uint64_t raw;
    struct {
        uint64_t pr:1;
        uint64_t reserved:63;
    };
};

#define IOMMU_FLUSHF_modified (1 << 0)

void *map_domain_page(mfn_t mfn);
void unmap_domain_page(void *ptr);