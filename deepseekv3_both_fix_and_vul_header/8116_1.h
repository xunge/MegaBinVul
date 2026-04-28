#include <stddef.h>
#include <errno.h>
#include <string.h>

#define unlikely(x) (x)
#define likely(x) (x)
#define MEM_LOG(fmt, ...)

#define _PAGE_PRESENT (1UL << 0)
#define L4_DISALLOW_MASK 0
#define FASTPATH_FLAG_WHITELIST 0

enum {
    l4
};

struct vcpu {
    struct domain *domain;
};

struct domain {
};

typedef struct {
} l4_pgentry_t;

static inline int is_guest_l4_slot(struct domain *d, unsigned long slot) { return 1; }
static inline unsigned long pgentry_ptr_to_slot(l4_pgentry_t *p) { return 0; }
static inline unsigned long l4e_get_flags(l4_pgentry_t e) { return 0; }
static inline int l4e_has_changed(l4_pgentry_t o, l4_pgentry_t n, unsigned long mask) { return 0; }
static inline void adjust_guest_l4e(l4_pgentry_t e, struct domain *d) {}
static inline int UPDATE_ENTRY(int t, l4_pgentry_t *p, l4_pgentry_t o, l4_pgentry_t n, unsigned long pfn, struct vcpu *v, int pa) { return 1; }
static inline int get_page_from_l4e(l4_pgentry_t e, unsigned long pfn, struct domain *d, int flags) { return 0; }
static inline void put_page_from_l4e(l4_pgentry_t e, unsigned long pfn, int flags, int put) {}

static inline int __copy_from_user(void *dst, const void *src, size_t size) { memcpy(dst, src, size); return 0; }