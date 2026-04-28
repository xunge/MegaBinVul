#include <stdbool.h>
#include <stdint.h>

typedef bool bool_t;
typedef uint32_t event_word_t;
typedef unsigned int evtchn_port_t;

struct domain;

struct evtchn {
    evtchn_port_t port;
};

#define EVTCHN_FIFO_LINKED 0

static const event_word_t *evtchn_fifo_word_from_port(const struct domain *d, evtchn_port_t port);
static bool_t guest_test_bit(const struct domain *d, unsigned int bit, const event_word_t *word);