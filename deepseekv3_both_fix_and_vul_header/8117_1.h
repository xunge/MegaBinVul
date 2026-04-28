#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define unlikely(x) (x)
#define likely(x) (x)
#define MEM_LOG(fmt, ...)
#define BUG()

#define _PAGE_PRESENT (1UL << 0)
#define FASTPATH_FLAG_WHITELIST 0

typedef uint64_t l3_pgentry_t;

struct vcpu {
    struct domain *domain;
};

struct domain {
    int dummy;
};

enum {
    l3
};

static inline int is_guest_l3_slot(unsigned long slot) { return 0; }
static inline unsigned long pgentry_ptr_to_slot(l3_pgentry_t *pl3e) { return 0; }
static inline int is_pv_32bit_domain(struct domain *d) { return 0; }
static inline unsigned long l3e_get_flags(l3_pgentry_t l3e) { return 0; }
static inline unsigned long l3_disallow_mask(struct domain *d) { return 0; }
static inline int l3e_has_changed(l3_pgentry_t old, l3_pgentry_t new, unsigned long mask) { return 0; }
static inline void adjust_guest_l3e(l3_pgentry_t l3e, struct domain *d) {}
static inline int UPDATE_ENTRY(int level, l3_pgentry_t *pl3e, l3_pgentry_t ol3e, l3_pgentry_t nl3e, unsigned long pfn, struct vcpu *vcpu, int preserve_ad) { return 0; }
static inline int get_page_from_l3e(l3_pgentry_t l3e, unsigned long pfn, struct domain *d, int partial) { return 0; }
static inline int create_pae_xen_mappings(struct domain *d, l3_pgentry_t *pl3e) { return 0; }
static inline void put_page_from_l3e(l3_pgentry_t l3e, unsigned long pfn, int partial, int put) {}

static inline int __copy_from_user(void *dst, const void *src, size_t size) { return 0; }