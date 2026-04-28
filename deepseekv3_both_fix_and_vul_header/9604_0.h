#include <stddef.h>

struct vcpu {
    struct evtchn_fifo *evtchn_fifo;
};

struct evtchn_fifo {
    struct evtchn_fifo_control_block *control_block;
};

struct evtchn_fifo_control_block {
    unsigned int *head;
};

struct evtchn_fifo_queue {
    int lock;
    unsigned int priority;
    unsigned int *head;
};

static inline void spin_lock_init(int *lock);