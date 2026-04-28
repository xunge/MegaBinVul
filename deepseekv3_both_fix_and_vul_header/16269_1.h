#include <stddef.h>
#include <stdbool.h>

struct kvm_ioapic {
    union kvm_ioapic_redirect_entry *redirtbl;
    void *kvm;
};

struct kvm_vcpu;

union kvm_ioapic_redirect_entry {
    struct {
        unsigned dest_id;
        unsigned dest_mode;
        unsigned vector;
        unsigned trig_mode;
    } fields;
};

#define APIC_DEST_NOSHORT 0
#define kvm_for_each_vcpu(i, vcpu, kvm) for (i = 0, vcpu = NULL; i < 0; i++)

static inline bool kvm_apic_match_dest(struct kvm_vcpu *vcpu, void *arg, int short_hand,
                                      unsigned dest_id, unsigned dest_mode) {
    return false;
}

static inline bool kvm_apic_pending_eoi(struct kvm_vcpu *vcpu, unsigned vector) {
    return false;
}

static inline void rtc_irq_eoi(struct kvm_ioapic *ioapic, struct kvm_vcpu *vcpu, unsigned vector) {}

static inline void kvm_ioapic_update_eoi_one(struct kvm_vcpu *vcpu, struct kvm_ioapic *ioapic,
                                            unsigned trig_mode, int irq) {}