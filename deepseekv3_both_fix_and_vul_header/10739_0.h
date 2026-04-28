#include <stdbool.h>
#include <stdint.h>

typedef int bool_t;
typedef uint32_t evtchn_port_t;

struct domain;
struct evtchn {
    evtchn_port_t port;
};

typedef uint32_t event_word_t;

#define EVTCHN_FIFO_PENDING 0
#define unlikely(x) (x)

static event_word_t *evtchn_fifo_word_from_port(struct domain *d, evtchn_port_t port);

static bool_t test_bit(unsigned int nr, const volatile void *addr);