#include <stdbool.h>
#include <stddef.h>

typedef unsigned int evtchn_port_t;

struct domain {
    struct {
        unsigned long evtchn_pending;
    } shared_info;
};

struct evtchn {
    evtchn_port_t port;
};

#define BITS_PER_EVTCHN_WORD(d) (sizeof(unsigned long) * 8)

#define shared_info(d, field) ((d)->shared_info.field)

#define guest_test_bit(d, nr, addr) \
    (test_bit((nr), (addr)))

#define test_bit(nr, addr) \
    (!!(((const unsigned long *)(addr))[(nr) / BITS_PER_LONG] & \
        (1UL << ((nr) % BITS_PER_LONG))))

#define BITS_PER_LONG (sizeof(unsigned long) * 8)

#define ASSERT(cond) ((void)0)