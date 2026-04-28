#include <stdbool.h>
#include <stddef.h>

typedef unsigned int evtchn_port_t;

extern unsigned int nr_irqs;
extern const struct irq_info *info_for_irq(unsigned int irq);

struct irq_info {
    evtchn_port_t evtchn;
};

#define likely(x) __builtin_expect(!!(x), 1)
#define WARN(condition, format...) ({ \
    int __ret_warn_on = !!(condition); \
    if (__builtin_expect(__ret_warn_on, 0)) \
        printf(format); \
    __ret_warn_on; \
})