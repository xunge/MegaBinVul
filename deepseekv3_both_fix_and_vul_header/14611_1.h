#include <stdbool.h>
#include <stdatomic.h>
#include <stdint.h>

#define APIC_DEFAULT_PHYS_BASE 0xfee00000
#define MSR_IA32_APICBASE_ENABLE (1<<11)
#define MSR_IA32_APICBASE_BSP (1<<8)
#define KVM_APIC_LVT_NUM 6
#define APIC_LVTT 0x320
#define APIC_LVT_MASKED (1<<16)
#define APIC_LVT0 0x350
#define APIC_MODE_EXTINT 7
#define APIC_TASKPRI 0x80
#define APIC_ESR 0x280
#define APIC_ICR 0x300
#define APIC_ICR2 0x310
#define APIC_TDCR 0x3e0
#define APIC_TMICT 0x380
#define APIC_IRR 0x200
#define APIC_ISR 0x100
#define APIC_TMR 0x180
#define KVM_X86_QUIRK_LINT0_REENABLED 1

typedef uint64_t u64;

struct hrtimer {
    int dummy;
};

struct kvm_vcpu {
    struct {
        unsigned long apic_base;
        struct kvm_lapic *apic;
        struct {
            u64 msr_val;
        } pv_eoi;
        bool apicv_active;
        int apic_arb_prio;
        int apic_attention;
    } arch;
    int vcpu_id;
    struct kvm *kvm;
};

struct kvm_lapic {
    struct kvm_vcpu *vcpu;
    unsigned long base_address;
    int highest_isr_cache;
    struct {
        struct hrtimer timer;
        atomic_int pending;
    } lapic_timer;
};

struct kvm {
    int quirks;
};

static inline bool kvm_vcpu_is_reset_bsp(struct kvm_vcpu *vcpu) { return false; }
static inline bool kvm_check_has_quirk(struct kvm *kvm, int quirk) { return false; }
static inline void kvm_apic_set_xapic_id(struct kvm_lapic *apic, int id) {}
static inline void kvm_apic_set_version(struct kvm_vcpu *vcpu) {}
static inline void kvm_lapic_set_reg(struct kvm_lapic *apic, int reg, int val) {}
static inline void apic_update_lvtt(struct kvm_lapic *apic) {}
static inline int kvm_lapic_get_reg(struct kvm_lapic *apic, int reg) { return 0; }
static inline void apic_manage_nmi_watchdog(struct kvm_lapic *apic, int val) {}
static inline void kvm_apic_set_dfr(struct kvm_lapic *apic, unsigned int val) {}
static inline void apic_set_spiv(struct kvm_lapic *apic, int val) {}
static inline bool apic_x2apic_mode(struct kvm_lapic *apic) { return false; }
static inline void kvm_apic_set_ldr(struct kvm_lapic *apic, int val) {}
static inline void kvm_apic_update_apicv(struct kvm_vcpu *vcpu) {}
static inline void update_divide_count(struct kvm_lapic *apic) {}
static inline void apic_update_ppr(struct kvm_lapic *apic) {}
static inline void kvm_recalculate_apic_map(struct kvm *kvm) {}
static inline void hrtimer_cancel(struct hrtimer *timer) {}
static inline void kvm_x86_apicv_post_state_restore(struct kvm_vcpu *vcpu) {}
static inline void kvm_x86_hwapic_irr_update(struct kvm_vcpu *vcpu, int val) {}
static inline void kvm_x86_hwapic_isr_update(struct kvm_vcpu *vcpu, int val) {}
static inline void kvm_lapic_set_base(struct kvm_vcpu *vcpu, u64 val) {}

#define SET_APIC_DELIVERY_MODE(lvt, mode) (((lvt) & ~0x700) | ((mode) << 8))

static inline void atomic_set(atomic_int *v, int i) {
    atomic_store(v, i);
}

#define static_call(name) name