#include <stddef.h>
#include <stdint.h>

struct domain;

struct iommu_ops {
    int (*init)(struct domain *d);
};

struct domain_iommu {
    int node;
    struct iommu_ops *platform_ops;
    int hap_pt_share;
    int need_sync;
};

#define CONFIG_NUMA
#define NUMA_NO_NODE (-1)

#define XEN_DOMCTL_IOMMU_no_sharept (1U << 0)

extern int iommu_hap_pt_share;
extern int iommu_hwdom_strict;

static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline int is_iommu_enabled(struct domain *d) { return 0; }
static inline int arch_iommu_domain_init(struct domain *d) { return 0; }
static inline struct iommu_ops *iommu_get_ops(void) { return NULL; }
static inline int is_hardware_domain(struct domain *d) { return 0; }
static inline void check_hwdom_reqs(struct domain *d) {}
static inline int hap_enabled(struct domain *d) { return 0; }
static inline int iommu_use_hap_pt(struct domain *d) { return 0; }

#define ASSERT(x) ((void)0)