#include <stdbool.h>

struct domain {
    struct {
        bool verw;
    } arch;
};

extern bool is_pv_domain(struct domain *d);
extern bool is_iommu_enabled(struct domain *d);
extern bool opt_md_clear_pv;
extern bool opt_md_clear_hvm;
extern bool opt_fb_clear_mmio;