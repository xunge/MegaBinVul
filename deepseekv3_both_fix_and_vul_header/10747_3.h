#include <stdbool.h>
#include <stddef.h>

typedef unsigned int evtchn_port_t;

#define BITS_PER_EVTCHN_WORD(d) (sizeof(unsigned long) * 8)

struct domain {
    struct {
        unsigned long evtchn_pending;
    } shared_info;
};

struct evtchn {
    evtchn_port_t port;
};

#define shared_info(d, field) (d->shared_info.field)
#define test_bit(nr, addr) (*(addr) & (1UL << (nr)))
#define ASSERT(cond) ((void)0)

typedef bool bool_t;