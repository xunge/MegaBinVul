#include <stdint.h>

#define GUEST_DR7 0
#define DR7_GD 0
#define KVM_GUESTDBG_USE_HW_BP 0
#define DB_VECTOR 0
#define KVM_EXIT_DEBUG 0
#define DR6_BD 0
#define EXIT_QUALIFICATION 0
#define DEBUG_REG_ACCESS_NUM 0
#define DEBUG_REG_ACCESS_REG(x) 0
#define TYPE_MOV_FROM_DR 0
#define X86_CR4_DE 0
#define UD_VECTOR 0
#define GP_VECTOR 0
#define DR6_VOLATILE 0
#define DR6_FIXED_1 0
#define DR7_VOLATILE 0
#define DR7_FIXED_1 0
#define DR7_BP_EN_MASK 0
#define GUEST_CS_BASE 0
#define GUEST_RIP 0

struct kvm_vcpu_arch {
    unsigned long dr6;
    unsigned long dr7;
    unsigned long db[4];
    unsigned long eff_db[4];
    unsigned long cr4;
    unsigned long switch_db_regs;
    unsigned long regs[16];
};

struct kvm_vcpu {
    unsigned long guest_debug;
    struct kvm_vcpu_arch arch;
};

struct kvm_run_debug_arch {
    unsigned long dr6;
    unsigned long dr7;
    unsigned long pc;
    unsigned long exception;
};

struct kvm_run {
    struct {
        struct kvm_run_debug_arch arch;
    } debug;
    unsigned long exit_reason;
};

static unsigned long vmcs_readl(int field) { return 0; }
static void vmcs_writel(int field, unsigned long value) {}
static void kvm_queue_exception(struct kvm_vcpu *vcpu, int vector) {}
static void kvm_register_write(struct kvm_vcpu *vcpu, int reg, unsigned long val) {}
static void skip_emulated_instruction(struct kvm_vcpu *vcpu) {}