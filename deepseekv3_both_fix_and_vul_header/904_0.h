#include <stdbool.h>
#include <stddef.h>

struct domain;
struct p2m_domain;

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef unsigned int p2m_type_t;

#define INVALID_MFN ((mfn_t){0})
#define gfn_x(gfn) ((unsigned long)(gfn))
#define gfn_eq(a, b) ((a) == (b))
#define gfn_add(gfn, n) ((gfn_t)((gfn) + (n)))
#define gfn_max(a, b) ((a) > (b) ? (a) : (b))
#define gfn_min(a, b) ((a) < (b) ? (a) : (b))
#define gfn_next_boundary(gfn, order) ((gfn_t)((gfn) + (1UL << (order))))
#define mfn_x(mfn) ((unsigned long)(mfn))
#define mfn_eq(a, b) ((a) == (b))
#define mfn_add(mfn, n) ((mfn_t)((mfn) + (n)))

#define ERESTART 512

struct p2m_domain {
    gfn_t lowest_mapped_gfn;
    gfn_t max_mapped_gfn;
};

static inline void p2m_read_lock(struct p2m_domain *p2m) {}
static inline void p2m_read_unlock(struct p2m_domain *p2m) {}
static inline struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return NULL; }
static inline mfn_t p2m_get_entry(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *t, unsigned int *level, unsigned int *order, bool *valid) { return INVALID_MFN; }
static inline bool p2m_is_any_ram(p2m_type_t t) { return false; }
static inline void flush_page_to_ram(mfn_t mfn, bool sync) {}
static inline void invalidate_icache(void) {}
static inline bool softirq_pending(unsigned int cpu) { return false; }
static inline unsigned int smp_processor_id(void) { return 0; }