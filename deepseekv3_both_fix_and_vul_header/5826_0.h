#include <stdbool.h>

struct kvm_vcpu {
    struct {
        struct {
            bool pending_events;
        } *apic;
    } arch;
};