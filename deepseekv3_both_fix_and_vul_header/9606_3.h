#include <stdint.h>
#include <stddef.h>

struct domain;

#define EVTCHN_FIFO_PRIORITY_MIN 0
#define EVTCHN_FIFO_NR_QUEUES (EVTCHN_FIFO_PRIORITY_MIN + 1)
#define EINVAL 22
#define ENOMEM 12

struct evtchn_fifo_queue {
    unsigned int head;
    unsigned int tail;
};

struct evtchn_fifo_vcpu {
    void *control_block;
    struct evtchn_fifo_queue queue[EVTCHN_FIFO_NR_QUEUES];
};

struct vcpu {
    struct domain *domain;
    struct evtchn_fifo_vcpu *evtchn_fifo;
};

void *xzalloc(size_t size);
#define xzalloc(type) ((type *)xzalloc(sizeof(type)))
int map_guest_page(struct domain *d, uint64_t gfn, void **virt);
void xfree(void *ptr);
void init_queue(struct vcpu *v, struct evtchn_fifo_queue *q, unsigned int priority);