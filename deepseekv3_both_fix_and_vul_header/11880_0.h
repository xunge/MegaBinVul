#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define PRI_dfn "lx"
#define EADDRNOTAVAIL 101
#define EFAULT 14

struct domain;
struct domain_iommu {
    struct {
        void *root_table;
        bool no_merge;
        int mapping_lock;
    } arch;
};

typedef struct {
    unsigned long x;
} dfn_t;

static inline unsigned long dfn_x(dfn_t dfn) { return dfn.x; }

static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline bool iommu_use_hap_pt(struct domain *d) { return false; }
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline int update_paging_mode(struct domain *d, unsigned long dfn) { return 0; }
static inline void domain_crash(struct domain *d) {}
static inline bool iommu_pde_from_dfn(struct domain *d, unsigned long dfn, unsigned long *pt_mfn) { return false; }
static inline void clear_iommu_pte_present(unsigned long mfn, unsigned long dfn) {}
static inline void amd_iommu_flush_pages(struct domain *d, unsigned long dfn, int flags) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

#define AMD_IOMMU_DEBUG(fmt, ...)