#include <stddef.h>
#include <stdbool.h>

enum mc_disposition {
    mc_exit,
    mc_continue,
    mc_preempt
};

struct vcpu {
    // dummy definition
};

struct multicall_entry {
    unsigned long op;
    long result;
    unsigned long args[6];
};

struct compat_multicall_entry {
    unsigned long op;
    long result;
    unsigned long args[6];
};

struct mc_state {
    struct multicall_entry call;
    struct compat_multicall_entry compat_call;
};

struct pv_hypercall_table_entry {
    long (*native)(unsigned long, unsigned long, unsigned long,
                   unsigned long, unsigned long, unsigned long);
    long (*compat)(unsigned long, unsigned long, unsigned long,
                   unsigned long, unsigned long, unsigned long);
};

extern struct vcpu *current;
extern struct pv_hypercall_table_entry pv_hypercall_table[256];

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define unlikely(x) (x)
#define likely(x) (x)
#define __HYPERVISOR_iret 0
#define CONFIG_COMPAT 1
#define ENOSYS 38

bool is_pv_32bit_vcpu(struct vcpu *vcpu);
void *guest_cpu_user_regs(void);
bool guest_kernel_mode(struct vcpu *vcpu, void *regs);