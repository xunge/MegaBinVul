#include <stdbool.h>
#include <errno.h>

struct domain {
    unsigned int controller_pause_count;
    unsigned int next_evtchn;
    unsigned int active_evtchns;
    unsigned int xen_evtchns;
    bool evtchn_fifo;
    void *event_lock;
};

struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

int port_is_valid(struct domain *d, unsigned int i);
void evtchn_close(struct domain *d, unsigned int i, int flag);
bool hypercall_preempt_check(void);
void evtchn_fifo_destroy(struct domain *d);
void evtchn_2l_init(struct domain *d);
void spin_lock(void *lock);
void spin_unlock(void *lock);