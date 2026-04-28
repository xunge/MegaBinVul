#include <stdbool.h>
#include <stddef.h>

typedef unsigned long paddr_t;
typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

typedef enum {
    p2m_invalid,
    p2m_ram_rw,
    p2m_ram_ro,
    p2m_mmio_direct,
    p2m_mmio_dm
} p2m_type_t;

typedef enum {
    p2m_access_n,
    p2m_access_r,
    p2m_access_w,
    p2m_access_rw
} p2m_access_t;

struct p2m_domain {
    gfn_t max_mapped_gfn;
    /* other members would go here */
};

struct lpae_p2m {
    p2m_type_t type;
};

typedef struct {
    struct lpae_p2m p2m;
    /* other members would go here */
} lpae_t;

#define INVALID_MFN ((mfn_t)0)
#define gfn_x(gfn) (gfn)
#define PAGE_SHIFT 12
#define PAGE_MASK (~((1UL << PAGE_SHIFT) - 1))
#define THIRD_MASK PAGE_MASK

#define P2M_ROOT_LEVEL 0
#define GUEST_TABLE_MAP_FAILED (-1)
#define GUEST_TABLE_NORMAL_PAGE 0

#define ASSERT(cond) ((void)0)
#define BUILD_BUG_ON(cond) ((void)0)
#define BUG_ON(cond) ((void)0)

#define DECLARE_OFFSETS(name, addr) unsigned int name[4] = {0}

static unsigned long level_masks[4];
static unsigned int level_orders[4];

static paddr_t gfn_to_gaddr(gfn_t gfn) { return 0; }
static bool p2m_is_locked(struct p2m_domain *p2m) { return true; }
static bool p2m_is_valid(lpae_t entry) { return false; }
static mfn_t lpae_get_mfn(lpae_t entry) { return INVALID_MFN; }
static mfn_t mfn_add(mfn_t mfn, unsigned long offset) { return INVALID_MFN; }
static bool lpae_is_valid(lpae_t entry) { return false; }
static p2m_access_t p2m_mem_access_radix_get(struct p2m_domain *p2m, gfn_t gfn) { return 0; }
static lpae_t *p2m_get_root_pointer(struct p2m_domain *p2m, gfn_t gfn) { return NULL; }
static int p2m_next_level(struct p2m_domain *p2m, bool write, unsigned int level, lpae_t **table, unsigned int offset) { return 0; }
static void unmap_domain_page(void *ptr) {}