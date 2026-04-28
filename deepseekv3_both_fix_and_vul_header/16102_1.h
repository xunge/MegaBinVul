#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define _VPF_blocked 0
#define SCHEDULE_SOFTIRQ 0
#define TRC_SCHED_BLOCK 0
#define CONFIG_X86 0

struct timer {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct vcpu {
    long vcpu_id;
    int poll_evtchn;
    unsigned long pause_flags;
    struct domain *domain;
    struct timer poll_timer;
};

struct domain {
    unsigned long *poll_mask;
    int domain_id;
    unsigned int max_evtchns;
};

struct sched_poll {
    unsigned int nr_ports;
    void *ports;
    unsigned long timeout;
};

typedef uint32_t evtchn_port_t;

extern struct vcpu *current;
extern int local_events_need_delivery(void);
extern void set_bit(int nr, volatile unsigned long *addr);
extern void clear_bit(int nr, volatile unsigned long *addr);
extern int test_bit(int nr, const volatile unsigned long *addr);
extern void smp_mb(void);
extern void arch_vcpu_block(struct vcpu *v);
extern int __copy_from_guest_offset(void *dst, void *src, unsigned int offset, unsigned int len);
extern int guest_handle_okay(void *hnd, unsigned int count);
extern int evtchn_port_is_pending(struct domain *d, evtchn_port_t port);
extern void set_timer(struct timer *timer, unsigned long timeout);
extern void raise_softirq(int nr);
extern void TRACE_2D(int event, int id1, int id2);