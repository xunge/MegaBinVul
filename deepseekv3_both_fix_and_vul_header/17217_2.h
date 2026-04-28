#include <stdbool.h>
#include <stdint.h>

#define STATE_IOREQ_NONE 0
#define STATE_IORESP_READY 1
#define STATE_IOREQ_READY 2
#define STATE_IOREQ_INPROCESS 3
#define XENLOG_ERR 0

typedef uint32_t evtchn_port_t;

struct domain {
    // minimal domain structure
};

struct vcpu {
    struct domain *domain;
};

struct hvm_ioreq_vcpu {
    bool pending;
    evtchn_port_t ioreq_evtchn;
    struct vcpu *vcpu;
};

typedef struct {
    unsigned int state;
    unsigned long data;
} ioreq_t;

static inline void smp_rmb(void) {
    asm volatile("" ::: "memory");
}

void hvm_io_assist(struct hvm_ioreq_vcpu *sv, unsigned long data);
void wait_on_xen_event_channel(evtchn_port_t port, bool condition);
void gdprintk(int level, const char *fmt, ...);
void domain_crash(struct domain *d);