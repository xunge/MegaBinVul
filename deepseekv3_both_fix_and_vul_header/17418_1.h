#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef unsigned long gva_t;

struct kvm_vcpu {
    struct {
        struct {
            int emulate_ctxt;
        } arch;
    };
};

#define VMXERR_UNSUPPORTED_VMCS_COMPONENT 0
#define EXIT_QUALIFICATION 0
#define VMX_INSTRUCTION_INFO 0

unsigned long vmcs_readl(int);
u32 vmcs_read32(int);
int nested_vmx_check_permission(struct kvm_vcpu *);
int nested_vmx_check_vmcs12(struct kvm_vcpu *);
int kvm_skip_emulated_instruction(struct kvm_vcpu *);
unsigned long kvm_register_readl(struct kvm_vcpu *, int);
int vmcs12_read_any(struct kvm_vcpu *, unsigned long, u64 *);
void nested_vmx_failValid(struct kvm_vcpu *, int);
void kvm_register_writel(struct kvm_vcpu *, int, u64);
int get_vmx_mem_address(struct kvm_vcpu *, unsigned long, u32, bool, gva_t *);
int kvm_write_guest_virt_system(void *, gva_t, void *, int, void *);
int is_long_mode(struct kvm_vcpu *);
void nested_vmx_succeed(struct kvm_vcpu *);