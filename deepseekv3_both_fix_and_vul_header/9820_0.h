#include <stdint.h>
#include <string.h>

struct kvm_vcpu_events {
    struct {
        uint8_t injected;
        uint8_t nr;
        uint8_t has_error_code;
        uint8_t pad;
        uint32_t error_code;
    } exception;
    struct {
        uint8_t injected;
        uint8_t nr;
        uint8_t soft;
        uint8_t shadow;
    } interrupt;
    struct {
        uint8_t injected;
        uint8_t pending;
        uint8_t masked;
        uint8_t pad;
    } nmi;
    uint32_t sipi_vector;
    uint32_t flags;
    uint8_t reserved[32];
};

struct kvm_vcpu {
    struct {
        struct {
            uint8_t pending;
            uint8_t nr;
            uint8_t has_error_code;
            uint32_t error_code;
        } exception;
        struct {
            uint8_t pending;
            uint8_t nr;
            uint8_t soft;
        } interrupt;
        uint8_t nmi_injected;
        uint8_t nmi_pending;
        uint32_t sipi_vector;
    } arch;
};

struct kvm_x86_ops {
    uint8_t (*get_interrupt_shadow)(struct kvm_vcpu *, uint32_t);
    uint8_t (*get_nmi_mask)(struct kvm_vcpu *);
};

extern struct kvm_x86_ops *kvm_x86_ops;

#define KVM_X86_SHADOW_INT_MOV_SS 0x01
#define KVM_X86_SHADOW_INT_STI 0x02
#define KVM_VCPUEVENT_VALID_NMI_PENDING 0x01
#define KVM_VCPUEVENT_VALID_SIPI_VECTOR 0x02
#define KVM_VCPUEVENT_VALID_SHADOW 0x04

static int kvm_exception_is_soft(unsigned int nr);