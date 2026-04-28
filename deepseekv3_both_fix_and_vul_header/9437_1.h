#include <stdint.h>

struct kvm_vcpu;
struct msr_data {
    uint32_t index;
    uint64_t data;
};

struct kvm_x86_ops {
    int (*set_msr)(struct kvm_vcpu *, struct msr_data *);
};

extern struct kvm_x86_ops *kvm_x86_ops;

static inline int is_noncanonical_address(uint64_t addr) {
    return 0;
}

static inline uint64_t get_canonical(uint64_t addr) {
    return addr;
}

#define MSR_FS_BASE 0xC0000100
#define MSR_GS_BASE 0xC0000101
#define MSR_KERNEL_GS_BASE 0xC0000102
#define MSR_CSTAR 0xC0000083
#define MSR_LSTAR 0xC0000082
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_IA32_SYSENTER_ESP 0x175