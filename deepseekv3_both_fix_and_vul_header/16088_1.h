#include <stddef.h>

#define EINVAL 22
#define EPERM 1
#define EEXIST 17
#define ENOMEM 12

struct evtchn {
    int state;
    int lock;
    union {
        struct {
            int irq;
        } pirq;
    } u;
};

struct domain {
    int nr_pirqs;
    struct vcpu **vcpu;
    int event_lock;
};

struct vcpu {
};

struct pirq {
    int evtchn;
};

typedef struct {
    int pirq;
    int flags;
    int port;
} evtchn_bind_pirq_t;

#define BIND_PIRQ__WILL_SHARE (1 << 0)

#define ECS_PIRQ 1

struct current_struct {
    struct domain *domain;
};

static struct current_struct *current;

static int is_hvm_domain(struct domain *d) { return 0; }
static int pirq_access_permitted(struct domain *d, int pirq) { return 0; }
static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}
static int pirq_to_evtchn(struct domain *d, int pirq) { return 0; }
static int get_free_port(struct domain *d) { return 0; }
static struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static struct pirq *pirq_get_info(struct domain *d, int pirq) { return NULL; }
static void pirq_cleanup_check(struct pirq *info, struct domain *d) {}
static int pirq_guest_bind(struct vcpu *v, struct pirq *info, int will_share) { return 0; }
static void link_pirq_port(int port, struct evtchn *chn, struct vcpu *v) {}
static void evtchn_port_init(struct domain *d, struct evtchn *chn) {}
static void arch_evtchn_bind_pirq(struct domain *d, int pirq) {}
static void check_free_port(struct domain *d, int port) {}

#define ERROR_EXIT(code) do { rc = code; goto out; } while (0)