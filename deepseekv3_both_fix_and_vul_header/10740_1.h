#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define _VPF_blocked 0
#define SCHEDULE_SOFTIRQ 0
#define TRC_SCHED_BLOCK 0
#define CONFIG_X86 0

typedef uint32_t evtchn_port_t;

struct timer {
    unsigned long expires;
};

struct vcpu {
    long pause_flags;
    int poll_evtchn;
    int vcpu_id;
    struct domain *domain;
    struct timer poll_timer;
};

struct domain {
    unsigned long *poll_mask;
    int domain_id;
    int max_evtchns;
};

struct sched_poll {
    unsigned int nr_ports;
    void *ports;
    unsigned long timeout;
};

#define EINVAL 22
#define EFAULT 14

static struct vcpu *current;
static int local_events_need_delivery(void) { return 0; }
static void set_bit(int nr, volatile void *addr) {}
static void clear_bit(int nr, volatile void *addr) {}
static int test_bit(int nr, volatile void *addr) { return 0; }
static void arch_vcpu_block(struct vcpu *v) {}
static void smp_mb(void) {}
static int __copy_from_guest_offset(void *dst, void *src, unsigned int offset, unsigned int size) { return 0; }
static int evtchn_port_is_pending(struct domain *d, int port) { return 0; }
static int evtchn_from_port(struct domain *d, int port) { return 0; }
static void set_timer(struct timer *timer, unsigned long expires) {}
static void raise_softirq(int softirq) {}
#define TRACE_2D(a, b, c) do {} while (0)
#define guest_handle_okay(a, b) 1