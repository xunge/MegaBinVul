#include <stddef.h>
#include <stdint.h>

typedef uint32_t evtchn_port_t;

struct list_head {
    struct list_head *next, *prev;
};

struct irq_info {
    evtchn_port_t evtchn;
    struct list_head eoi_list;
    unsigned int eoi_cpu;
    unsigned int eoi_time;
    unsigned int irq_epoch;
};

#define VALID_EVTCHN(evtchn) ((evtchn) != 0)

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

extern unsigned int irq_epoch;
extern unsigned int per_cpu(unsigned int, unsigned int);
extern void lateeoi_list_add(struct irq_info *info);
extern void unmask_evtchn(evtchn_port_t evtchn);