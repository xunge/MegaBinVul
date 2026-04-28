#include <stdint.h>
#include <stddef.h>

struct kvm_vcpu;
struct vcpu_vmx;

#define PIN_BASED_VM_EXEC_CONTROL 0
#define SECONDARY_VM_EXEC_CONTROL 0
#define SECONDARY_EXEC_APIC_REGISTER_VIRT 0
#define SECONDARY_EXEC_VIRTUAL_INTR_DELIVERY 0

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline void vmcs_write32(uint32_t field, uint32_t val) {}
static inline uint32_t vmx_pin_based_exec_ctrl(struct vcpu_vmx *vmx) { return 0; }
static inline int cpu_has_secondary_exec_ctrls(void) { return 0; }
static inline int kvm_vcpu_apicv_active(struct kvm_vcpu *vcpu) { return 0; }
static inline void vmcs_set_bits(uint32_t field, uint32_t bits) {}
static inline void vmcs_clear_bits(uint32_t field, uint32_t bits) {}
static inline int cpu_has_vmx_msr_bitmap(void) { return 0; }
static inline void vmx_set_msr_bitmap(struct kvm_vcpu *vcpu) {}