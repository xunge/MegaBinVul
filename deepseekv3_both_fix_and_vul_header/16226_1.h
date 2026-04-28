#include <stdint.h>
#include <stddef.h>

typedef uint64_t xen_ulong_t;
typedef uint32_t evtchn_port_t;

#define VIRQ_TIMER 0
#define BITS_PER_LONG (sizeof(long) * 8)
#define BITS_PER_EVTCHN_WORD (sizeof(xen_ulong_t) * 8)

struct shared_info;
struct vcpu_info {
    xen_ulong_t evtchn_pending_sel;
};

extern struct shared_info *HYPERVISOR_shared_info;

#define __this_cpu_read(var) (var)
#define __this_cpu_write(var, val) (var = val)

extern unsigned int current_word_idx;
extern unsigned int current_bit_idx;
extern struct vcpu_info *xen_vcpu;

#define MASK_LSBS(v, idx) ((v) & ~((1UL << (idx)) - 1))
#define EVTCHN_FIRST_BIT(w) (__builtin_ffsl(w) - 1)

static inline xen_ulong_t xchg_xen_ulong(xen_ulong_t *ptr, xen_ulong_t val);
static inline int irq_from_virq(unsigned int cpu, unsigned int virq);
static inline evtchn_port_t evtchn_from_irq(int irq);
static inline xen_ulong_t active_evtchns(unsigned int cpu, struct shared_info *s, int word_idx);
static inline int get_evtchn_to_irq(evtchn_port_t port);
static inline void generic_handle_irq(int irq);