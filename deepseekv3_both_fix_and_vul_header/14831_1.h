#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define XEN_GUEST_HANDLE_PARAM(type) type*
#define XENOPROF_last_op 20
#define NONPRIV_OP(op) ((op) < 10)
#define XSM_HOOK 0
#define PMU_OWNER_XENOPROF 1
#define VIRQ_XENOPROF 16
#define XENLOG_DEBUG 0

#define EINVAL 22
#define EPERM 1
#define EBUSY 16
#define EFAULT 14
#define ENOSYS 38

typedef int ret_t;
typedef uint16_t domid_t;

enum xenoprof_ops {
    XENOPROF_init,
    XENOPROF_get_buffer,
    XENOPROF_reset_active_list,
    XENOPROF_reset_passive_list,
    XENOPROF_set_active,
    XENOPROF_set_passive,
    XENOPROF_reserve_counters,
    XENOPROF_counter,
    XENOPROF_setup_events,
    XENOPROF_enable_virq,
    XENOPROF_start,
    XENOPROF_stop,
    XENOPROF_disable_virq,
    XENOPROF_release_counters,
    XENOPROF_shutdown,
    XENOPROF_set_backtrace,
    XENOPROF_ibs_counter,
    XENOPROF_get_ibs_caps
};

enum xenoprof_state {
    XENOPROF_INITIALIZED,
    XENOPROF_COUNTERS_RESERVED,
    XENOPROF_READY,
    XENOPROF_PROFILING
};

struct domain {
    int domain_id;
    struct xenoprof *xenoprof;
    struct domain *domain;
};

struct vcpu {};
struct xenoprof {};

typedef struct {
    int lock;
} spinlock_t;

extern struct domain *current;
extern struct domain *xenoprof_primary_profiler;
extern int xenoprof_state;
extern int adomains;
extern int pdomains;
extern int activated;
extern int backtrace_depth;
extern int ibs_caps;
extern struct domain *active_domains[];
extern struct domain *passive_domains[];
extern int active_ready[];
extern spinlock_t xenoprof_lock;

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void send_guest_vcpu_virq(struct vcpu *v, int virq) { (void)v; (void)virq; }
static inline int gdprintk(int level, const char *fmt, ...) { return 0; }

int printk(const char *fmt, ...);
int xsm_profile(int hook, struct domain *d, int op);
int acquire_pmu_ownership(int owner);
int xenoprof_op_init(XEN_GUEST_HANDLE_PARAM(void) arg);
int xenoprof_op_get_buffer(XEN_GUEST_HANDLE_PARAM(void) arg);
void reset_active_list(void);
void reset_passive_list(void);
int copy_from_guest(void *dst, XEN_GUEST_HANDLE_PARAM(void) src, int count);
int add_active_list(domid_t domid);
int add_passive_list(XEN_GUEST_HANDLE_PARAM(void) arg);
int xenoprof_arch_reserve_counters(void);
int xenoprof_arch_counter(XEN_GUEST_HANDLE_PARAM(void) arg);
int xenoprof_arch_setup_events(void);
void xenoprof_arch_enable_virq(void);
void xenoprof_reset_stat(void);
void xenoprof_reset_buf(struct domain *d);
int set_active(struct domain *d);
int xenoprof_arch_start(void);
void xenoprof_arch_stop(void);
int is_active(struct domain *d);
int reset_active(struct domain *d);
void unshare_xenoprof_page_with_guest(struct xenoprof *x);
void release_pmu_ownship(int owner);
void xenoprof_arch_release_counters(void);
void xenoprof_arch_disable_virq(void);
int xenoprof_backtrace_supported(void);
int xenoprof_arch_ibs_counter(XEN_GUEST_HANDLE_PARAM(void) arg);

#define for_each_vcpu(d, v) for ((v) = NULL; (v) == NULL; (v) = (void*)1)