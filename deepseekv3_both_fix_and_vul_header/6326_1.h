#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;
typedef uint16_t domid_t;

#define INVALID_MFN ((mfn_t){0})
#define INVALID_M2P_ENTRY (~0UL)

struct domain {
    void *shared_info;
};

struct page_info;

typedef enum {
    XENMAPSPACE_shared_info,
    XENMAPSPACE_grant_table,
    XENMAPSPACE_gmfn,
    XENMAPSPACE_gmfn_foreign
} xenmapspace_t;

typedef enum {
    p2m_mmio_direct,
    p2m_ram_rw,
    p2m_ram_ro,
    p2m_ram_logdirty
} p2m_type_t;

union add_to_physmap_extra {
    domid_t foreign_domid;
    struct page_info **ppage;
};

#define PAGE_ORDER_4K 0
#define SHARED_M2P(gfn) (0)

static inline bool mfn_eq(mfn_t a, mfn_t b) { return a == b; }
static inline unsigned long mfn_x(mfn_t mfn) { return mfn; }
static inline unsigned long gfn_x(gfn_t gfn) { return gfn; }
static inline bool mfn_valid(mfn_t mfn) { return !mfn_eq(mfn, INVALID_MFN); }
static inline gfn_t _gfn(unsigned long gfn) { return (gfn_t)gfn; }

static inline mfn_t virt_to_mfn(void *v) { return (mfn_t)(uintptr_t)v; }
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline bool is_special_page(struct page_info *page) { return false; }
static inline bool p2m_is_shared(p2m_type_t t) { return false; }

static inline void put_page(struct page_info *page) {}
static inline void put_gfn(struct domain *d, unsigned long gfn) {}

static inline mfn_t get_gfn_unshare(struct domain *d, unsigned long gfn, p2m_type_t *t) { return INVALID_MFN; }
static inline mfn_t get_gfn(struct domain *d, unsigned long gfn, p2m_type_t *t) { return INVALID_MFN; }
static inline unsigned long get_gpfn_from_mfn(unsigned long mfn) { return INVALID_M2P_ENTRY; }
static inline struct page_info *get_page_from_mfn(mfn_t mfn, struct domain *d) { return NULL; }

static inline int gnttab_map_frame(struct domain *d, unsigned long idx, gfn_t gpfn, mfn_t *mfn) { return 0; }
static inline int p2m_add_foreign(struct domain *d, unsigned long idx, unsigned long gfn, domid_t domid) { return 0; }
static inline int guest_physmap_remove_page(struct domain *d, gfn_t gpfn, mfn_t mfn, unsigned int order) { return 0; }
static inline int guest_remove_page(struct domain *d, unsigned long gfn) { return 0; }
static inline int guest_physmap_add_page(struct domain *d, gfn_t gpfn, mfn_t mfn, unsigned int order) { return 0; }

#define unlikely(x) (x)
#define ASSERT(x) ((void)0)