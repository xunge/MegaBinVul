#include <stdbool.h>
#include <stddef.h>

struct domain;
struct evtchn;

#define ASSERT(cond) ((void)0)
#define likely(x) (x)

enum evtchn_state {
    ECS_INTERDOMAIN
};

struct evtchn {
    int lock;
    enum evtchn_state state;
    union {
        struct {
            struct domain *remote_dom;
            int remote_port;
        } interdomain;
    } u;
    int notify_vcpu_id;
};

static inline bool port_is_valid(struct domain *d, int port) { return true; }
static inline struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static inline bool consumer_is_xen(struct evtchn *chn) { return true; }
static inline void evtchn_port_set_pending(struct domain *d, int vcpu_id, struct evtchn *chn) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}