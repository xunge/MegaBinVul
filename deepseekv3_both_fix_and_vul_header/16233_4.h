#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

struct vcpu_info {
    int evtchn_upcall_pending;
};

struct evtchn_loop_ctrl {
    int dummy;
};

extern struct vcpu_info *xen_vcpu;
extern int irq_epoch;
extern struct rwlock evtchn_rwlock;

#define __this_cpu_read(var) (var)
#define __this_cpu_inc(var) ((var)++)
#define smp_processor_id() 0
#define read_lock(lock) 
#define read_unlock(lock) 
#define BUG_ON(cond) 
#define virt_rmb() 
#define irqs_disabled() 0

static inline void xen_evtchn_handle_events(int cpu, ...) {
    va_list args;
    va_start(args, cpu);
    if (va_arg(args, struct evtchn_loop_ctrl*)) {
        /* handle with ctrl parameter */
    }
    va_end(args);
}