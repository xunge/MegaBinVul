#include <stdbool.h>
#include <stddef.h>

struct domain;
typedef unsigned int evtchn_port_t;
struct evtchn {
    evtchn_port_t port;
};
typedef unsigned int event_word_t;

#define EVTCHN_FIFO_PENDING 0

static const event_word_t *evtchn_fifo_word_from_port(const struct domain *d, evtchn_port_t port) {
    return NULL;
}
static bool guest_test_bit(const struct domain *d, unsigned int bit, const event_word_t *word) {
    return false;
}