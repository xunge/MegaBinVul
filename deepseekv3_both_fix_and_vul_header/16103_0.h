#include <stdint.h>

#define BITS_PER_EVTCHN_WORD(d) (sizeof(unsigned long) * 8)

struct domain {
    void *evtchn_port_ops;
    unsigned int max_evtchns;
};

extern void *evtchn_port_ops_2l;