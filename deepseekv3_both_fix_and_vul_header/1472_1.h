#include <stdint.h>
#include <stdbool.h>

#define INTR_INFO_VECTOR_MASK 0x000000ff

typedef uint32_t u32;

typedef struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        bool at_instruction_boundary;
    } arch;
} kvm_vcpu;

typedef struct kvm {
    // placeholder for kvm structure
} kvm;

typedef struct gate_desc {
    uint32_t offset_low;
    uint32_t offset_high;
} gate_desc;

extern gate_desc *host_idt_base;

u32 vmx_get_intr_info(struct kvm_vcpu *vcpu);
bool is_external_intr(u32 intr_info);
void handle_interrupt_nmi_irqoff(struct kvm_vcpu *vcpu, unsigned long offset);
unsigned long gate_offset(gate_desc *desc);
int KVM_BUG(bool condition, struct kvm *kvm, const char *fmt, ...);