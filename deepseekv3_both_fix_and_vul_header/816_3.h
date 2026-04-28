#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define ASSERT(cond) assert(cond)
#define gdprintk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;
typedef uint64_t dfn_t;

#define INVALID_M2P_ENTRY (~0UL)
#define INVALID_MFN INVALID_M2P_ENTRY

#define gfn_x(gfn) (gfn)
#define mfn_x(mfn) (mfn)
#define dfn_x(dfn) (dfn)
#define _gfn(gfn) (gfn)
#define _mfn(mfn) (mfn)
#define _dfn(dfn) (dfn)

#define gfn_add(gfn, offset) (gfn + offset)
#define mfn_add(mfn, offset) (mfn + offset)
#define dfn_add(dfn, offset) (dfn + offset)

#define gfn_eq(a, b) ((a) == (b))
#define mfn_eq(a, b) ((a) == (b))
#define dfn_eq(a, b) ((a) == (b))

#define P2M_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)

enum p2m_type {
    p2m_invalid,
    p2m_ram_rw,
    p2m_ram_paging_out,
    p2m_populate_on_demand,
    p2m_grant_table_rw,
    p2m_foreign,
    p2m_shared
};

typedef enum p2m_type p2m_type_t;
typedef uint8_t p2m_access_t;

#define p2m_is_foreign(_t) ((_t) == p2m_foreign)
#define p2m_is_shared(_t) ((_t) == p2m_shared)
#define p2m_is_grant(_t) ((_t) == p2m_grant_table_rw)
#define p2m_is_ram(_t) ((_t) == p2m_ram_rw)
#define p2m_is_paged(_t) ((_t) == p2m_ram_paging_out)
#define p2m_is_paging(_t) ((_t) == p2m_ram_paging_out)

#define IOMMUF_readable (1 << 0)
#define IOMMUF_writable (1 << 1)

#define PGT_writable_page 0
#define EINVAL 22
#define XENLOG_ERR 0
#define XENLOG_WARNING 0
#define BUG_ON(cond) assert(!(cond))
#define atomic_dec(ptr) (*(ptr))--

struct domain {
    unsigned long domain_id;
    int paged_pages;
    struct p2m_domain *hostp2m;
};

struct p2m_domain {
    struct domain *domain;
    p2m_access_t default_access;
    mfn_t (*get_entry)(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *t,
                      p2m_access_t *a, int q, bool *r, bool *w);
    int (*set_entry)(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn,
                    unsigned int page_order, p2m_type_t t, p2m_access_t a);
    struct {
        int entry_count;
    } pod;
};

struct page_info {
    struct domain *owner;
};

static struct domain *dom_cow = NULL;

static inline bool mfn_valid(mfn_t mfn) { return mfn != INVALID_MFN; }

struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return d->hostp2m; }
bool paging_mode_translate(const struct domain *d) { return true; }
bool need_iommu_pt_sync(const struct domain *d) { return false; }
int get_page_and_type(struct page_info *page, struct domain *domain, unsigned int type) { return 1; }
void put_page_and_type(struct page_info *page) {}
void p2m_lock(struct p2m_domain *p2m) {}
void p2m_unlock(struct p2m_domain *p2m) {}
mfn_t p2m_get_entry(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *t, p2m_access_t *a, int q, bool *r, bool *w) { return INVALID_MFN; }
int p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, mfn_t mfn, unsigned int page_order, p2m_type_t t, p2m_access_t a) { return 0; }
void set_gpfn_from_mfn(unsigned long mfn, unsigned long pfn) {}
unsigned long mfn_to_gfn(struct domain *d, mfn_t mfn) { return mfn; }
struct page_info *mfn_to_page(mfn_t mfn) { static struct page_info page; return &page; }
struct domain *page_get_owner(const struct page_info *page) { return page->owner; }
void domain_crash(struct domain *d) {}
int mem_sharing_unshare_page(struct domain *d, unsigned long gfn, bool nosleep) { return 0; }
int mem_sharing_notify_enomem(struct domain *d, unsigned long gfn, bool allow_sleep) { return 0; }
void p2m_remove_page(struct p2m_domain *p2m, unsigned long gfn, unsigned long mfn, unsigned int page_order) {}
void pod_lock(struct p2m_domain *p2m) {}
void pod_unlock(struct p2m_domain *p2m) {}
int iommu_legacy_map(struct domain *d, dfn_t dfn, mfn_t mfn, unsigned int page_order, unsigned int flags) { return 0; }