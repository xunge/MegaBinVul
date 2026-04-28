#include <stddef.h>
#include <string.h>

#define DOMID_INVALID (-1)

struct domain;
struct vtd_iommu {
    int *domid_map;
    unsigned long *domid_bitmap;
};

static inline int domid_mapping(struct vtd_iommu *iommu) { return 0; }
static inline int domain_iommu_domid(struct domain *domain, struct vtd_iommu *iommu) { return 0; }
static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}