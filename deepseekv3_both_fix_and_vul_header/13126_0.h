#include <string.h>

struct kvm_vcpu {
    struct {
        unsigned long db[4];
        unsigned long dr7;
    } arch;
};

struct kvm_debugregs {
    unsigned long db[4];
    unsigned long dr6;
    unsigned long dr7;
    unsigned long flags;
    unsigned long reserved[8];
};

void kvm_get_dr(struct kvm_vcpu *vcpu, int dr, unsigned long *val);