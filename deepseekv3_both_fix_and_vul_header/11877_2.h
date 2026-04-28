#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

typedef uint64_t dfn_t;
typedef uint64_t mfn_t;

struct domain;
struct page;

struct arch_iommu {
    unsigned int paging_mode;
    void *mapping_lock;
};

struct domain_iommu {
    struct arch_iommu arch;
};

#define PRI_dfn "lx"
#define PRI_mfn "lx"

#define dfn_x(dfn) (dfn)
#define mfn_x(mfn) (mfn)

#define IOMMUF_writable (1 << 0)
#define IOMMUF_readable (1 << 1)

#define _mfn(mfn) (mfn)

#define AMD_IOMMU_DEBUG(fmt, ...)

typedef int bool_t;

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline bool iommu_use_hap_pt(struct domain *d) { return false; }
static inline int amd_iommu_alloc_root(struct domain_iommu *hd) { return 0; }
static inline void domain_crash(struct domain *d) {}
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline int update_paging_mode(struct domain *d, unsigned long dfn) { return 0; }
static inline bool iommu_pde_from_dfn(struct domain *d, unsigned long dfn, unsigned long *pt_mfn) { return false; }
static inline bool set_iommu_pte_present(unsigned long pt_mfn, unsigned long dfn, unsigned long mfn, int level, bool writable, bool readable) { return false; }
static inline void amd_iommu_flush_pages(struct domain *d, unsigned long dfn, int level) {}
static inline bool iommu_update_pde_count(struct domain *d, unsigned long pt_mfn, unsigned long dfn, unsigned long mfn, unsigned int level) { return false; }
static inline bool iommu_merge_pages(struct domain *d, unsigned long pt_mfn, unsigned long dfn, unsigned int flags, unsigned int level) { return false; }
static inline void free_amd_iommu_pgtable(struct page *page) {}
static inline struct page *mfn_to_page(mfn_t mfn) { return NULL; }