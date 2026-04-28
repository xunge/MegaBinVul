#include <stdint.h>
#include <stddef.h>

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define XSM_TARGET 0
#define HVM_NR_PARAMS 256
#define EFAULT 1
#define EINVAL 2
#define ESRCH 3
#define ENOSYS 4
#define XENLOG_DEBUG 0
#define HVMOP_set_param 0
#define HVMOP_get_param 1

typedef uint16_t domid_t;

struct xen_hvm_param {
    domid_t  domid;
    uint32_t index;
    uint64_t value;
};

struct hvm_domain {
    uint64_t params[HVM_NR_PARAMS];
};

struct arch_domain {
    struct hvm_domain hvm_domain;
};

struct domain {
    struct arch_domain arch;
    domid_t domid;
};

extern int copy_from_guest(void *dst, void *src, size_t len);
extern int copy_to_guest(void *dst, void *src, size_t len);
extern struct domain *rcu_lock_domain_by_any_id(domid_t domid);
extern void rcu_unlock_domain(struct domain *d);
extern long xsm_hvm_param(int xsm_flags, struct domain *d, unsigned long op);
extern void gdprintk(int level, const char *fmt, ...);