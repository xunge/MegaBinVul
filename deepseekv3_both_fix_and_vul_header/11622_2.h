#include <stdint.h>
#include <string.h>

typedef unsigned __int128 __uint128_t;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint32_t __u32;
typedef uint64_t __u64;

struct kvm_vcpu;
struct kvm_one_reg {
    __u64 id;
    __u64 addr;
};
struct kvm_regs {
    u32 regs[64]; // Dummy array to make sizeof work
};

#define KVM_REG_ARM_CORE_REG(x) 0
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

#define KVM_REG_SIZE(id) sizeof(u32)
#define __user

static inline struct kvm_regs *vcpu_gp_regs(struct kvm_vcpu *vcpu) { return (struct kvm_regs *)0; }
static inline u64 core_reg_offset_from_id(__u64 id) { return 0; }
static inline int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }