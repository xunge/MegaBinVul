#include <stddef.h>
#include <errno.h>
#include <pthread.h>

typedef pthread_mutex_t spinlock_t;

struct evtchn {
    int state;
    int notify_vcpu_id;
    spinlock_t lock;
};

struct domain {
    spinlock_t event_lock;
};

struct task_struct {
    struct domain *domain;
};

extern struct task_struct *current;

#define ECS_IPI 0
#define ERROR_EXIT(x) do { rc = x; goto out; } while (0)

typedef struct {
    int vcpu;
    int port;
} evtchn_bind_ipi_t;

static inline struct domain_vcpu *domain_vcpu(struct domain *d, int vcpu) { return NULL; }
static inline int get_free_port(struct domain *d) { return 0; }
static inline struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static inline void evtchn_port_init(struct domain *d, struct evtchn *chn) {}
static inline void spin_lock(spinlock_t *lock) { pthread_mutex_lock(lock); }
static inline void spin_unlock(spinlock_t *lock) { pthread_mutex_unlock(lock); }