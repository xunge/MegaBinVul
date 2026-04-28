#include <stdint.h>
#include <string.h>

#define unlikely(x) (x)
#define likely(x) (x)
#define __test_and_set_bit(nr, addr) (0)
#define __copy_from_guest(dst, src, nr) (0)
#define __copy_to_guest(dst, src, nr) (0)
#define __copy_field_to_guest(dst, src, field) (0)
#define guest_handle_okay(hnd, nr) (1)
#define guest_handle_add_offset(hnd, nr) 
#define XEN_GUEST_HANDLE_PARAM(type) void*
#define XENLOG_INFO 0
#define gdprintk(level, fmt, ...) 
#define trace_multicall_call(entry) 
#define perfc_incr(counter) 
#define perfc_add(counter, val) 
#define hypercall_preempt_check() (0)
#define hypercall_create_continuation(op, fmt, ...) (0)
#define hypercall_cancel_continuation() 
#define __HYPERVISOR_multicall 0
#define NDEBUG

typedef int ret_t;

struct multicall_entry {
    int result;
};

enum mc_disposition {
    mc_continue,
    mc_exit,
    mc_preempt
};

struct mc_state {
    unsigned long flags;
    struct multicall_entry call;
    int result;
};

struct task_struct {
    struct mc_state mc_state;
    int hcall_preempted;
} *current;

ret_t arch_do_multicall_call(struct mc_state *mcs);
void xlat_multicall_entry(struct mc_state *mcs);

#define _MCSF_in_multicall 0
#define EINVAL 1
#define EFAULT 2