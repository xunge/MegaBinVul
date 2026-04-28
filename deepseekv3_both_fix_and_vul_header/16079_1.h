#include <stddef.h>

#define EINVAL 22
#define EAGAIN 11

struct domain {
    struct domain *domain;
    unsigned int controller_pause_count;
    unsigned int active_evtchns;
    unsigned int xen_evtchns;
    int evtchn_fifo;
    void *event_lock;
};

extern struct domain *current;

void evtchn_close(struct domain *d, unsigned int i, int flag);
int port_is_valid(struct domain *d, unsigned int i);
void evtchn_fifo_destroy(struct domain *d);
void evtchn_2l_init(struct domain *d);
void spin_lock(void *lock);
void spin_unlock(void *lock);