#include <stdbool.h>

struct domain;
struct dom_iommu {
    void *platform_ops;
};

extern bool iommu_enabled;
extern struct dom_iommu *dom_iommu(struct domain *d);
extern bool need_iommu(struct domain *d);
extern void iommu_teardown(struct domain *d);
extern void arch_iommu_domain_destroy(struct domain *d);