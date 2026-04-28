#include <stddef.h>

#define TRAP_int3 3
#define TRAP_debug 1

struct vcpu {
    struct {
        struct {
            struct {
                unsigned long exception_bitmap;
            } hvm_vmx;
            struct {
                int debug_state_latch;
            } hvm_vcpu;
        } arch;
    };
};

extern int cpu_has_monitor_trap_flag;

void vmx_vmcs_enter(struct vcpu *v);
void vmx_update_exception_bitmap(struct vcpu *v);
void vmx_vmcs_exit(struct vcpu *v);