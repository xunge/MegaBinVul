#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;
typedef uint64_t p2m_type_t;
typedef uint64_t p2m_access_t;

#define LPAE_SHIFT 9
#define P2M_ROOT_LEVEL 0
#define EINVAL 22
#define ENOENT 2
#define ENOMEM 12

#define GUEST_TABLE_MAP_FAILED (-1)
#define GUEST_TABLE_NORMAL_PAGE 0
#define GUEST_TABLE_SUPER_PAGE 1

#define p2m_access_rwx 0
#define IOMMU_FLUSHF_modified (1 << 0)
#define IOMMU_FLUSHF_added (1 << 1)

struct p2m_domain;
struct domain;

typedef struct {
    struct {
        uint64_t table;
    } p2m;
    uint64_t raw;
} lpae_t;

struct p2m_domain {
    bool mem_access_enabled;
    bool need_flush;
    lpae_t clean_pte;
    struct {
        unsigned int mappings[4];
    } stats;
    gfn_t max_mapped_gfn;
    gfn_t lowest_mapped_gfn;
    struct domain *domain;
};

#define ASSERT(cond) ((void)0)
#define DECLARE_OFFSETS(name, addr) unsigned int name[4]
#define gfn_to_gaddr(gfn) ((uint64_t)(gfn))
#define mfn_eq(a, b) ((a) == (b))
#define INVALID_MFN ((mfn_t)-1)
#define likely(x) __builtin_expect(!!(x), 1)
#define P2M_CLEAR_PERM(pte) ((pte).raw)
#define gfn_x(gfn) (gfn)
#define _dfn(dfn) (dfn)
#define gfn_add(gfn, n) ((gfn_t)((gfn) + (n)))
#define gfn_max(a, b) ((a) > (b) ? (a) : (b))
#define gfn_min(a, b) ((a) < (b) ? (a) : (b))
#define unmap_domain_page(p) ((void)0)

static bool p2m_is_write_locked(struct p2m_domain *p2m) { return true; }
static bool p2m_is_superpage(lpae_t entry, unsigned int level) { return false; }
static bool p2m_is_valid(lpae_t entry) { return false; }
static mfn_t lpae_get_mfn(lpae_t entry) { return 0; }
static bool lpae_is_valid(lpae_t entry) { return false; }
static lpae_t *p2m_get_root_pointer(struct p2m_domain *p2m, gfn_t sgfn) { return NULL; }
static int p2m_next_level(struct p2m_domain *p2m, bool removing_mapping, unsigned int level, lpae_t **table, unsigned int offset) { return 0; }
static bool p2m_split_superpage(struct p2m_domain *p2m, lpae_t *split_pte, unsigned int level, unsigned int target, unsigned int *offsets) { return false; }
static void p2m_remove_pte(lpae_t *entry, lpae_t clean_pte) {}
static void p2m_force_tlb_flush_sync(struct p2m_domain *p2m) {}
static void p2m_write_pte(lpae_t *entry, lpae_t pte, lpae_t clean_pte) {}
static int p2m_mem_access_radix_set(struct p2m_domain *p2m, gfn_t sgfn, p2m_access_t a) { return 0; }
static void p2m_free_entry(struct p2m_domain *p2m, lpae_t entry, unsigned int level) {}
static bool is_iommu_enabled(struct domain *d) { return false; }
static int iommu_iotlb_flush(struct domain *d, uint64_t dfn, uint64_t page_order, unsigned int flags) { return 0; }
static lpae_t mfn_to_p2m_entry(mfn_t smfn, p2m_type_t t, p2m_access_t a) { return (lpae_t){0}; }