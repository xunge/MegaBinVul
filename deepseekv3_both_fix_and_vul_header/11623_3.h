#include <stdint.h>
#include <errno.h>
#include <string.h>

typedef uint32_t u32;
typedef uint32_t __u32;
typedef uint64_t __u64;

#define __user

struct kvm_vcpu;
struct kvm_one_reg {
    __u64 id;
    __u64 addr;
};
struct kvm_regs {
    __u32 regs[64]; // Simplified placeholder
};

#define KVM_REG_SIZE(id) ((id) & 0xffff)
#define ENOENT 2
#define EINVAL 22
#define EFAULT 14

static inline struct kvm_regs *vcpu_gp_regs(struct kvm_vcpu *vcpu) { return 0; }
static inline int core_reg_offset_from_id(__u64 id) { return 0; }
static inline int validate_core_offset(const struct kvm_one_reg *reg) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}