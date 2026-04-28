#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef unsigned long mfn_t;
typedef uint32_t hvmmem_access_t;

typedef enum {
    p2m_access_n,
    p2m_access_r,
    p2m_access_w,
    p2m_access_rw,
    p2m_access_x,
    p2m_access_rx,
    p2m_access_wx,
    p2m_access_rwx,
    p2m_access_rx2rw,
    p2m_access_n2rwx
} p2m_access_t;

typedef enum {
    HVMMEM_access_default
} hvmmem_access_default_t;

typedef enum {
    p2m_type_min,
    p2m_type_ram,
    p2m_type_mmio,
    p2m_type_mmio_direct,
    p2m_type_foreign,
    p2m_type_grant,
    p2m_type_dev,
    p2m_type_pod,
    p2m_type_unknown,
    p2m_type_max
} p2m_type_t;

struct domain;
struct p2m_domain {
    p2m_access_t default_access;
    mfn_t (*get_entry)(struct p2m_domain *, unsigned long, p2m_type_t *, p2m_access_t *, int, void *);
    int (*set_entry)(struct p2m_domain *, unsigned long, mfn_t, int, p2m_type_t, p2m_access_t);
};

#define PAGE_ORDER_4K 0

struct p2m_domain *p2m_get_hostp2m(struct domain *d);
void p2m_lock(struct p2m_domain *p2m);
void p2m_unlock(struct p2m_domain *p2m);