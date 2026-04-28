#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define XENLOG_G_ERR ""
#define PRI_gfn "lx"
#define unlikely(x) (x)
#define ERESTART (-1)

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef unsigned int p2m_type_t;
typedef unsigned int p2m_access_t;

struct domain {
    int domain_id;
};

struct p2m_domain {
    gfn_t lowest_mapped_gfn;
    gfn_t max_mapped_gfn;
};

#define p2m_access_rwx 0
#define p2m_invalid 0

static inline gfn_t gfn_add(gfn_t gfn, unsigned long offset) { return gfn + offset; }
static inline unsigned long gfn_x(gfn_t gfn) { return gfn; }
static inline gfn_t gfn_next_boundary(gfn_t gfn, unsigned int order) { return gfn + (1UL << order); }
static inline bool mfn_eq(mfn_t mfn1, mfn_t mfn2) { return mfn1 == mfn2; }
static inline mfn_t INVALID_MFN = 0;

struct p2m_domain *p2m_get_hostp2m(struct domain *d);
void p2m_write_lock(struct p2m_domain *p2m);
void p2m_write_unlock(struct p2m_domain *p2m);
mfn_t p2m_get_entry(struct p2m_domain *p2m, gfn_t gfn, p2m_type_t *t, p2m_access_t *a, unsigned int *order, bool *q);
int __p2m_set_entry(struct p2m_domain *p2m, gfn_t gfn, unsigned int order, mfn_t mfn, p2m_type_t t, p2m_access_t a);
bool hypercall_preempt_check(void);
int printk(const char *fmt, ...);