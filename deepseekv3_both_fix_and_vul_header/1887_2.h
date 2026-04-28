#include <stdint.h>
#include <stddef.h>

typedef uint64_t shadow_l1e_t;
typedef uint64_t mfn_t;

struct domain {
    // dummy definition
};
struct page_info {
    // dummy definition
};

typedef enum {
    p2m_grant_map_rw,
    p2m_grant_map_ro
} p2m_type_t;

#define ASSERT(cond) ((void)0)
#define mfn_valid(mfn) (0)
#define mfn_to_page(mfn) (NULL)
#define mfn_x(mfn) (0)
#define page_get_owner(pg) (NULL)
#define page_refcounting_suppressed(pg) (0)
#define sh_l1e_is_magic(sl1e) (0)
#define shadow_l1e_get_mfn(sl1e) ((mfn_t){0})
#define shadow_l1e_get_flags(sl1e) (0)
#define shadow_mode_refcounts(d) (0)
#define get_page_from_l1e(sl1e, d, owner) (0)
#define SHADOW_PRINTK(fmt, ...) ((void)0)
#define SH_PRI_pte ""
#define PRI_mfn ""
#define unlikely(cond) (cond)
#define perfc_incr(counter) ((void)0)
#define _PAGE_RW (1UL << 1)
#define dom_io NULL
#define XSM_TARGET 0
#define xsm_priv_mapping(XSM_TARGET, d, owner) (0)