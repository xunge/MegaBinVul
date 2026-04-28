#include <stdbool.h>
#include <stddef.h>

struct domain {
    bool is_dying;
    int event_lock;
    unsigned int active_evtchns;
};

#define BUG_ON(cond) 
#define ASSERT(cond) 

static inline void spin_barrier(int *lock) {}
static inline bool port_is_valid(struct domain *d, unsigned int port) { return false; }
static inline void evtchn_close(struct domain *d, unsigned int port, int flags) {}
static inline void clear_global_virq_handlers(struct domain *d) {}
static inline void evtchn_fifo_destroy(struct domain *d) {}