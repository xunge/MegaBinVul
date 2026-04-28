#include <stddef.h>
#include <stdint.h>

#define unlikely(x) (x)

typedef uint32_t event_word_t;

struct domain {
    struct evtchn_fifo *evtchn_fifo;
};

struct evtchn_fifo {
    unsigned int num_evtchns;
    event_word_t **event_array;
};

#define EVTCHN_FIFO_EVENT_WORDS_PER_PAGE 64