#include <stdint.h>
#include <stdbool.h>

typedef uint64_t gpa_t;
typedef uint64_t u64;
typedef uint32_t u32;

#define FEATURE_CONTROL_LOCKED 0x1
#define FEATURE_CONTROL_VMXON_ENABLED_OUTSIDE_SMX 0x4
#define UD_VECTOR 6
#define VMXERR_VMXON_IN_VMX_ROOT_OPERATION 1
#define VMCS12_REVISION 0x1
#define X86_CR4_VMXE (1UL << 13)
#define PAGE_ALIGNED(addr) (!((addr) & (4096-1)))

struct kvm_vcpu;
struct vcpu_vmx {
    struct {
        bool vmxon;
        gpa_t vmxon_ptr;
    } nested;
    u64 msr_ia32_feature_control;
};

struct page;

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return (struct vcpu_vmx *)vcpu; }
static inline int kvm_read_cr4_bits(struct kvm_vcpu *vcpu, unsigned long mask) { return 0; }
static inline void kvm_queue_exception(struct kvm_vcpu *vcpu, unsigned nr) {}
static inline int kvm_skip_emulated_instruction(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_inject_gp(struct kvm_vcpu *vcpu, unsigned int error_code) {}
static inline int nested_vmx_get_vmptr(struct kvm_vcpu *vcpu, gpa_t *vmptr) { return 0; }
static inline struct page *kvm_vcpu_gpa_to_page(struct kvm_vcpu *vcpu, gpa_t gpa) { return 0; }
static inline void kvm_release_page_clean(struct page *page) {}
static inline void nested_vmx_failValid(struct kvm_vcpu *vcpu, u32 reason) {}
static inline void nested_vmx_failInvalid(struct kvm_vcpu *vcpu) {}
static inline int enter_vmx_operation(struct kvm_vcpu *vcpu) { return 0; }
static inline void nested_vmx_succeed(struct kvm_vcpu *vcpu) {}
static inline unsigned long cpuid_maxphyaddr(struct kvm_vcpu *vcpu) { return 0; }
static inline void *kmap(struct page *page) { return 0; }
static inline void kunmap(struct page *page) {}
static inline int is_error_page(struct page *page) { return 0; }