#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define KVM_REG_SIZE(id) ((id) & 0xffff)
#define KVM_REG_ARM_CORE_PSTATE (offsetof(struct kvm_regs, pstate) / sizeof(uint32_t))
#define PSR_AA32_MODE_MASK 0x0000001f
#define PSR_AA32_MODE_USR 0x00000010
#define PSR_AA32_MODE_FIQ 0x00000011
#define PSR_AA32_MODE_IRQ 0x00000012
#define PSR_AA32_MODE_SVC 0x00000013
#define PSR_AA32_MODE_ABT 0x00000017
#define PSR_AA32_MODE_UND 0x0000001b
#define PSR_MODE_EL0t 0x00000000
#define PSR_MODE_EL1t 0x00000004
#define PSR_MODE_EL1h 0x00000005
#define ENOENT 2
#define EINVAL 22
#define EFAULT 14

typedef uint32_t __u32;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t __u64;

struct kvm_vcpu;
struct kvm_regs {
    uint64_t regs[31];
    uint64_t sp;
    uint64_t pc;
    uint64_t pstate;
};

struct kvm_one_reg {
    __u64 id;
    __u64 addr;
};

static inline struct kvm_regs *vcpu_gp_regs(struct kvm_vcpu *vcpu) { 
    static struct kvm_regs dummy_regs;
    return &dummy_regs; 
}
static int core_reg_offset_from_id(__u64 id) { return id % 100; }
static int validate_core_offset(const struct kvm_one_reg *reg) { return 0; }
static int copy_from_user(void *to, const void *from, unsigned long n) { 
    memcpy(to, from, n);
    return 0;
}

#define __user
#define __uint128_t unsigned __int128
#define KVM_REG_ARM_CORE_REG(x) KVM_REG_ARM_CORE_PSTATE