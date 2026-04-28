#include <stdint.h>

#define EXIT_REASON_MCE_DURING_VMENTRY 0
#define EXIT_REASON_EXCEPTION_NMI 0
#define VM_EXIT_INTR_INFO 0
#define INTR_INFO_INTR_TYPE_MASK 0
#define INTR_TYPE_NMI_INTR 0
#define INTR_INFO_VALID_MASK 0

typedef uint32_t u32;

struct vcpu {
    int dummy;
};

struct vcpu_vmx {
    u32 exit_reason;
    u32 exit_intr_info;
    struct vcpu vcpu;
};

static u32 vmcs_read32(u32 field) { return 0; }
static int is_machine_check(u32 exit_intr_info) { return 0; }
static void kvm_machine_check(void) {}
static void kvm_before_handle_nmi(struct vcpu *vcpu) {}
static void kvm_after_handle_nmi(struct vcpu *vcpu) {}