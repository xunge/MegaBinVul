#include <stddef.h>

#define POD_SWEEP_STRIDE 64
#define POD_SWEEP_LIMIT 1024

typedef unsigned long p2m_type_t;
typedef unsigned long p2m_access_t;

struct p2m_domain {
    struct {
        unsigned long reclaim_single;
        unsigned long max_guest;
        unsigned long count;
    } pod;
    int (*get_entry)(struct p2m_domain *, unsigned long, p2m_type_t *, p2m_access_t *, int, void *, void *);
};

#define BUG_ON(condition) ((void)0)

static void p2m_lock(struct p2m_domain *p2m);
static void p2m_unlock(struct p2m_domain *p2m);
static void p2m_pod_zero_check(struct p2m_domain *p2m, unsigned long *gfns, unsigned long j);
static int p2m_is_ram(p2m_type_t t);