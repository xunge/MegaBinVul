#include <stdbool.h>
#include <stdatomic.h>

struct evtchn_fifo_control_block {
    _Atomic unsigned long ready;
};

#define DEFINE_PER_CPU(type, name) \
    type name[1]

DEFINE_PER_CPU(struct evtchn_fifo_control_block, cpu_control_block);

#define per_cpu(var, cpu) (&(var[cpu]))

static inline unsigned long xchg(_Atomic unsigned long *ptr, unsigned long val) {
    return atomic_exchange(ptr, val);
}

static inline unsigned find_first_bit(const unsigned long *addr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        if (*addr & (1UL << i)) {
            return i;
        }
    }
    return size;
}

extern void consume_one_event(unsigned cpu, struct evtchn_fifo_control_block *control_block, 
                            unsigned q, unsigned long *ready, bool drop);

#define EVTCHN_FIFO_MAX_QUEUES 64