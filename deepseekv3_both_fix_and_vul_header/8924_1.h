#include <stdint.h>

#define PF_VECTOR 14
#define UD_VECTOR 6
#define MC_VECTOR 18
#define NM_VECTOR 7
#define DB_VECTOR 1
#define AC_VECTOR 17
#define BP_VECTOR 3

#define KVM_GUESTDBG_ENABLE 0x00000001
#define KVM_GUESTDBG_USE_SW_BP 0x00000002

#define EXCEPTION_BITMAP 0x00004004

typedef uint32_t u32;

struct kvm_vcpu {
    u32 guest_debug;
    u32 fpu_active;
};

struct vmx_rmode {
    u32 vm86_active;
};

struct vmcs12 {
    u32 exception_bitmap;
};

struct vmx {
    struct vmx_rmode rmode;
};

static struct vmx* to_vmx(struct kvm_vcpu *vcpu) { return (struct vmx*)vcpu; }
static int is_guest_mode(struct kvm_vcpu *vcpu) { return 0; }
static struct vmcs12* get_vmcs12(struct kvm_vcpu *vcpu) { return (struct vmcs12*)vcpu; }
static void vmcs_write32(u32 field, u32 value) {}

extern int enable_ept;