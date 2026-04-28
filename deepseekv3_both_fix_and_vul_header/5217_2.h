#include <stdint.h>
#include <string.h>

typedef uint32_t gva_t;
typedef uint32_t u32;
#define PFERR_USER_MASK 0

struct kvm_vcpu;
struct x86_exception {
    int dummy;  // minimal definition to allow sizeof
};
struct kvm_x86_ops {
    int (*get_cpl)(struct kvm_vcpu *);
};

extern struct kvm_x86_ops *kvm_x86_ops;

int kvm_read_guest_virt_helper(gva_t addr, void *val, unsigned int bytes,
                              struct kvm_vcpu *vcpu, u32 access,
                              struct x86_exception *exception);