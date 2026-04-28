#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;
typedef uint64_t dfn_t;

#define _gfn(x) ((gfn_t)(x))
#define _mfn(x) ((mfn_t)(x))
#define _dfn(x) ((dfn_t)(x))
#define mfn_x(x) (x)
#define INVALID_MFN 0
#define INVALID_M2P_ENTRY 0

typedef enum {
    p2m_invalid,
    p2m_grant,
    p2m_shared,
    p2m_foreign,
    p2m_valid
} p2m_type_t;

typedef enum {
    p2m_access_default
} p2m_access_t;

struct domain;
struct p2m_domain {
    struct domain *domain;
    p2m_access_t default_access;
    mfn_t (*get_entry)(struct p2m_domain *, gfn_t, p2m_type_t *, p2m_access_t *, int, void *, void *);
};

#define ASSERT(x) 
#define P2M_DEBUG(fmt, ...) 

static bool paging_mode_translate(struct domain *d) { return false; }
static bool need_iommu_pt_sync(struct domain *d) { return false; }
static int iommu_legacy_unmap(struct domain *d, dfn_t dfn, unsigned int order) { return 0; }
static bool gfn_locked_by_me(struct p2m_domain *p2m, gfn_t gfn) { return true; }
static bool mfn_valid(mfn_t mfn) { return true; }
static bool p2m_is_grant(p2m_type_t t) { return t == p2m_grant; }
static bool p2m_is_shared(p2m_type_t t) { return t == p2m_shared; }
static bool p2m_is_foreign(p2m_type_t t) { return t == p2m_foreign; }
static bool p2m_is_valid(p2m_type_t t) { return t == p2m_valid; }
static void set_gpfn_from_mfn(mfn_t mfn, unsigned long val) {}
static gfn_t gfn_add(gfn_t gfn, unsigned long i) { return gfn + i; }
static int p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, unsigned int order, p2m_type_t t, p2m_access_t a) { return 0; }