#include <stdint.h>
#include <stdbool.h>

#define EXIT_QUALIFICATION 0
#define VMX_INSTRUCTION_INFO 0

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t gva_t;

struct x86_exception {
    // Minimal definition
};

struct vmx_nested_state {
    u64 current_vmptr;
};

struct vmx {
    struct vmx_nested_state nested;
};

struct kvm_vcpu_arch {
    struct x86_exception emulate_ctxt;
};

struct kvm_vcpu {
    struct kvm_vcpu_arch arch;
};

static inline struct vmx *to_vmx(struct kvm_vcpu *vcpu) {
    return (struct vmx *)0;
}

static inline unsigned long vmcs_readl(unsigned long field) {
    return 0;
}

static inline u32 vmcs_read32(unsigned long field) {
    return 0;
}

static inline int nested_vmx_check_permission(struct kvm_vcpu *vcpu) {
    return 0;
}

static inline int get_vmx_mem_address(struct kvm_vcpu *vcpu, unsigned long exit_qual,
                                    u32 instr_info, bool write, gva_t *gva) {
    return 0;
}

static inline int kvm_write_guest_virt_system(struct x86_exception *ctxt, gva_t gva,
                                            void *data, unsigned int size,
                                            struct x86_exception *e) {
    return 0;
}

static inline void kvm_inject_page_fault(struct kvm_vcpu *vcpu, struct x86_exception *e) {
}

static inline void nested_vmx_succeed(struct kvm_vcpu *vcpu) {
}

static inline int kvm_skip_emulated_instruction(struct kvm_vcpu *vcpu) {
    return 0;
}