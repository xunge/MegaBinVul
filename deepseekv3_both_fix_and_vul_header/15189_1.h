#include <stdint.h>

#define VCPU_REGS_RAX 0
#define VCPU_REGS_RBX 1
#define VCPU_REGS_RCX 2
#define VCPU_REGS_RDX 3
#define VCPU_REGS_RSI 4

#define KVM_HC_VAPIC_POLL_IRQ 0
#define KVM_HC_MMU_OP 1

#define KVM_EPERM 1
#define KVM_ENOSYS 2

struct kvm_vcpu_stats {
    unsigned long hypercalls;
};

struct kvm_vcpu {
    struct kvm_vcpu_stats stat;
};

struct kvm_x86_ops {
    int (*get_cpl)(struct kvm_vcpu *vcpu);
};

extern struct kvm_x86_ops *kvm_x86_ops;

unsigned long kvm_register_read(struct kvm_vcpu *vcpu, int reg);
void kvm_register_write(struct kvm_vcpu *vcpu, int reg, unsigned long val);
int is_long_mode(struct kvm_vcpu *vcpu);
int kvm_pv_mmu_op(struct kvm_vcpu *vcpu, unsigned long a0, unsigned long hc_gpa, unsigned long *ret);
unsigned long hc_gpa(struct kvm_vcpu *vcpu, unsigned long a1, unsigned long a2);
void trace_kvm_hypercall(unsigned long nr, unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3);