#include <stdbool.h>
#include <stdint.h>

struct kvm_vcpu {
    struct {
        uint64_t apic_base;
    } arch;
};

extern bool is_guest_mode(struct kvm_vcpu *vcpu);
extern bool is_long_mode(struct kvm_vcpu *vcpu);
extern bool cpu_has_secondary_exec_ctrls(void);
extern uint32_t vmcs_read32(uint32_t field);
extern void vmcs_write64(uint64_t field, uint64_t value);
extern unsigned long *vmx_msr_bitmap_nested;
extern unsigned long *vmx_msr_bitmap_longmode_x2apic;
extern unsigned long *vmx_msr_bitmap_legacy_x2apic;
extern unsigned long *vmx_msr_bitmap_longmode;
extern unsigned long *vmx_msr_bitmap_legacy;
extern uint64_t __pa(unsigned long *addr);

#define SECONDARY_VM_EXEC_CONTROL 0
#define SECONDARY_EXEC_VIRTUALIZE_X2APIC_MODE 0
#define MSR_BITMAP 0
#define X2APIC_ENABLE (1 << 10)