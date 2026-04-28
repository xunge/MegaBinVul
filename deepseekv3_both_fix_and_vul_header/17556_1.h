#include <stddef.h>

struct domain;
typedef struct xenoprof_buf xenoprof_buf_t;
struct xenoprof_buf {
    int event_head;
    int event_tail;
};

enum {
    event_head,
    event_tail
};

static int xenoprof_buf(struct domain *d, xenoprof_buf_t *buf, int field) {
    return field == event_head ? buf->event_head : buf->event_tail;
}