#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define PRI_dfn "lu"
#define PRI_mfn "lu"
#define _mfn(x) (x)
#define IOMMUF_writable (1 << 0)
#define IOMMUF_readable (1 << 1)

typedef uint64_t dfn_t;
typedef uint64_t mfn_t;
typedef bool bool_t;

struct domain {
    bool creation_finished;
};

struct domain_iommu {
    struct {
        bool no_merge;
        unsigned int paging_mode;
        int mapping_lock;
    } arch;
};

struct page;

static inline dfn_t dfn_x(dfn_t dfn) { return dfn; }
static inline mfn_t mfn_x(mfn_t mfn) { return mfn; }

#define spin_lock(x)
#define spin_unlock(x)

bool iommu_use_hap_pt(struct domain *d);
struct domain_iommu *dom_iommu(struct domain *d);
int amd_iommu_alloc_root(struct domain_iommu *hd);
bool is_hvm_domain(struct domain *d);
int update_paging_mode(struct domain *d, unsigned long dfn);
bool iommu_pde_from_dfn(struct domain *d, unsigned long dfn, unsigned long *pt_mfn);
bool set_iommu_pte_present(unsigned long pt_mfn, unsigned long dfn, unsigned long mfn, int level, bool writable, bool readable);
void amd_iommu_flush_pages(struct domain *d, unsigned long dfn, int count);
bool iommu_update_pde_count(struct domain *d, unsigned long pt_mfn, unsigned long dfn, unsigned long mfn, unsigned int level);
bool iommu_merge_pages(struct domain *d, unsigned long pt_mfn, unsigned long dfn, unsigned int flags, unsigned int level);
void free_amd_iommu_pgtable(struct page *page);
struct page *mfn_to_page(mfn_t mfn);
void domain_crash(struct domain *d);
void AMD_IOMMU_DEBUG(const char *fmt, ...);