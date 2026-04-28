#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct kvm_vcpu {
    struct {
        uint32_t regs[16];
    } arch;
};

struct msr_data {
    uint64_t data;
    uint32_t index;
    bool host_initiated;
};

#define VCPU_REGS_RCX 0
#define VCPU_REGS_RAX 1
#define VCPU_REGS_RDX 2

int vmx_set_msr(struct kvm_vcpu *vcpu, struct msr_data *msr);
void trace_kvm_msr_write_ex(u32 ecx, u64 data);
void trace_kvm_msr_write(u32 ecx, u64 data);
void kvm_inject_gp(struct kvm_vcpu *vcpu, int err);
void skip_emulated_instruction(struct kvm_vcpu *vcpu);