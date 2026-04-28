#include <stdbool.h>

typedef bool bool_t;
typedef unsigned int evtchn_port_t;

struct domain;
struct evtchn {
    evtchn_port_t port;
};

typedef unsigned int event_word_t;

const event_word_t *evtchn_fifo_word_from_port(const struct domain *d, evtchn_port_t port);
bool_t guest_test_bit(const struct domain *d, int bit, const event_word_t *word);

#define EVTCHN_FIFO_MASKED 0