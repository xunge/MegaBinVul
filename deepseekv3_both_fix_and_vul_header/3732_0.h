#include <stdbool.h>
#include <stdint.h>

typedef bool bool_t;
typedef uint64_t mfn_t;

struct p2m_domain {
    struct domain *domain;
};

struct domain {
    bool iommu_enabled;
};

extern bool iommu_snoop;

typedef struct {
    unsigned long mfn;
    bool sp;
    bool snp;
    bool suppress_ve;
} ept_entry_t;

#define EPT_TABLE_ORDER 9
#define EPT_PAGETABLE_ENTRIES (1UL << EPT_TABLE_ORDER)

#define ASSERT(cond) ((void)0)

static bool_t is_epte_superpage(ept_entry_t *ept_entry);
static ept_entry_t *ept_set_middle_entry(struct p2m_domain *p2m, ept_entry_t *new_ept);
static void ept_p2m_type_to_flags(struct p2m_domain *p2m, ept_entry_t *epte);
static bool_t is_iommu_enabled(struct domain *d);
static void *map_domain_page(mfn_t mfn);
static void unmap_domain_page(void *ptr);