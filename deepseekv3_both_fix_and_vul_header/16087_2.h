#include <stddef.h>
#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define EINVAL 22
#define ENOENT 2
#define EEXIST 17

typedef uint32_t evtchn_port_t;

typedef struct {
    int virq;
    int vcpu;
    evtchn_port_t port;
} evtchn_bind_virq_t;

struct evtchn {
    int state;
    int notify_vcpu_id;
    union {
        int virq;
    } u;
    int lock;
};

struct vcpu {
    evtchn_port_t *virq_to_evtchn;
};

struct domain {
    struct vcpu **vcpus;
    int event_lock;
    struct domain *domain;
};

extern struct domain *current;

#define ECS_VIRQ 0

static inline int array_index_nospec(int index, int size) {
    return index;
}

static inline int virq_is_global(int virq) {
    return 0;
}

static inline struct vcpu *domain_vcpu(struct domain *d, int vcpu) {
    return NULL;
}

static inline int evtchn_allocate_port(struct domain *d, evtchn_port_t port) {
    return 0;
}

static inline int get_free_port(struct domain *d) {
    return 0;
}

static inline struct evtchn *evtchn_from_port(struct domain *d, evtchn_port_t port) {
    return NULL;
}

static inline void evtchn_port_init(struct domain *d, struct evtchn *chn) {
}

#define spin_lock(lock) 
#define spin_unlock(lock) 
#define ERROR_EXIT(code) do { rc = code; goto out; } while (0)