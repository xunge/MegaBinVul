#include <stdbool.h>
#include <stddef.h>

struct kvm_ioapic {
    union kvm_ioapic_redirect_entry *redirtbl;
    struct kvm *kvm;
    struct {
        int pending_eoi;
        void *dest_map;
    } rtc_status;
    unsigned int irr;
};

union kvm_ioapic_redirect_entry {
    struct {
        unsigned int dest_id;
        unsigned int vector;
        unsigned int dest_mode;
        unsigned int trig_mode;
        unsigned int delivery_mode;
        unsigned int mask;
        unsigned int remote_irr;
    } fields;
};

struct kvm_lapic_irq {
    unsigned int dest_id;
    unsigned int vector;
    unsigned int dest_mode;
    unsigned int trig_mode;
    unsigned int delivery_mode;
    unsigned int level;
    unsigned int shorthand;
};

struct kvm;

#define IOAPIC_EDGE_TRIG 0
#define IOAPIC_LEVEL_TRIG 1
#define RTC_GSI 8

#define BUG_ON(condition) ((void)0)

static void ioapic_debug(const char *fmt, ...) { (void)fmt; }

int kvm_irq_delivery_to_apic(struct kvm *kvm, void *null, struct kvm_lapic_irq *irqe, void *dest_map);