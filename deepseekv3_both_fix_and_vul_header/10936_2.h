#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

typedef uint64_t dfn_t;
typedef uint64_t mfn_t;

#define PRI_dfn "lx"

struct spinlock {
    int lock;
};

struct domain;
struct domain_iommu {
    struct {
        struct spinlock mapping_lock;
    } arch;
};

#define IOMMUF_writable 0x1
#define IOMMUF_readable 0x2

#define dfn_x(dfn) (dfn)
#define mfn_x(mfn) (mfn)

static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}

static inline struct domain_iommu *dom_iommu(struct domain *d) { return NULL; }
static inline int amd_iommu_alloc_root(struct domain_iommu *hd) { return 0; }
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline int update_paging_mode(struct domain *d, unsigned long dfn) { return 0; }
static inline int iommu_pde_from_dfn(struct domain *d, unsigned long dfn, unsigned long *pt_mfn, bool alloc) { return 0; }
static inline unsigned int set_iommu_pte_present(unsigned long pt_mfn, unsigned long dfn, unsigned long mfn, int level, bool writable, bool readable) { return 0; }
static inline void domain_crash(struct domain *d) {}
static inline void AMD_IOMMU_DEBUG(const char *fmt, ...) {}