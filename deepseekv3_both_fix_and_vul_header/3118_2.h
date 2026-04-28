#include <stddef.h>
#include <errno.h>

#define KVM_ARM_VCPU_INIT 0xae
#define KVM_SET_ONE_REG 0xab
#define KVM_GET_ONE_REG 0xac
#define KVM_GET_REG_LIST 0xb0

struct file {
    void *private_data;
};

struct kvm_vcpu;

struct kvm_vcpu_init {
    unsigned long features;
    unsigned long target;
};

struct kvm_one_reg {
    unsigned long id;
    unsigned long addr;
};

struct kvm_reg_list {
    unsigned long n;
    unsigned long reg[];
};

#define __user

static inline int copy_from_user(void *to, const void __user *from, size_t n) {
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, size_t n) {
    return 0;
}

long kvm_vcpu_set_target(struct kvm_vcpu *vcpu, struct kvm_vcpu_init *init);
long kvm_arm_set_reg(struct kvm_vcpu *vcpu, struct kvm_one_reg *reg);
long kvm_arm_get_reg(struct kvm_vcpu *vcpu, struct kvm_one_reg *reg);
unsigned long kvm_arm_num_regs(struct kvm_vcpu *vcpu);
long kvm_arm_copy_reg_indices(struct kvm_vcpu *vcpu, unsigned long *indices);