#include <stdint.h>

struct domain;
struct domain_iommu {
    struct {
        int paging_mode;
    } arch;
};

static inline struct domain_iommu *dom_iommu(struct domain *d);
static inline int is_hvm_domain(struct domain *d);
static int amd_iommu_get_paging_mode(uint64_t max_page);

uint64_t max_page;