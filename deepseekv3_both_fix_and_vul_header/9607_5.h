#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define bool_t bool

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            uint32_t ready;
        } *control_block;
        struct evtchn_fifo_queue *queue;
    } *evtchn_fifo;
};

struct domain;

struct evtchn {
    unsigned int port;
    unsigned int priority;
    unsigned int notify_vcpu_id;
    unsigned int last_vcpu_id;
    unsigned int last_priority;
    int pending;
};

struct evtchn_fifo_queue {
    unsigned int tail;
    unsigned int *head;
    unsigned int priority;
    unsigned long lock;
};

typedef unsigned int event_word_t;

#define EVTCHN_FIFO_PENDING 0
#define EVTCHN_FIFO_MASKED 1
#define EVTCHN_FIFO_LINKED 2

#define unlikely(x) (x)
#define test_and_set_bit(nr, addr) (0)
#define test_bit(nr, addr) (0)
#define write_atomic(ptr, val) (*(ptr) = (val))
#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define printk(fmt, ...) ((void)0)

static event_word_t *evtchn_fifo_word_from_port(struct domain *d, unsigned int port) { return NULL; }
static bool evtchn_fifo_set_link(struct domain *d, event_word_t *word, unsigned int port) { return false; }
static struct evtchn_fifo_queue *lock_old_queue(struct domain *d, struct evtchn *evtchn, unsigned long *flags) { return NULL; }
static void vcpu_mark_events_pending(struct vcpu *v) {}
static void evtchn_check_pollers(struct domain *d, unsigned int port) {}