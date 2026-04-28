#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef int bool_t;
typedef uint32_t event_word_t;
typedef unsigned int evtchn_port_t;

struct domain;
struct evtchn {
    evtchn_port_t port;
};

#define EVTCHN_FIFO_MASKED 0
#define unlikely(x) (x)

static inline event_word_t *evtchn_fifo_word_from_port(struct domain *d, evtchn_port_t port) { return NULL; }
static inline bool_t test_bit(unsigned int nr, const volatile event_word_t *addr) { return 0; }