#include <stdatomic.h>
#include <stdbool.h>

#define BUG_ON(cond) 
#define ASSERT(cond) 
#define DOMDYING_dead 0
#define ERESTART (-1)

struct domain {
    bool is_dying;
    atomic_int valid_evtchns;
    int active_evtchns;
    int event_lock;
};

void spin_barrier(int *lock);
int port_is_valid(struct domain *d, unsigned int port);
void evtchn_close(struct domain *d, unsigned int port, int flags);
void clear_global_virq_handlers(struct domain *d);
void evtchn_fifo_destroy(struct domain *d);
int hypercall_preempt_check(void);