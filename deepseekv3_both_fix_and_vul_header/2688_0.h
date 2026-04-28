#include <stdint.h>

#define KVM_IRQFD_FLAG_DEASSIGN 0x1
#define KVM_IRQFD_FLAG_RESAMPLE 0x2
#define KVM_MAX_IRQ_ROUTES 4096
#define EINVAL 22

struct kvm;
struct kvm_irqfd {
    uint32_t flags;
    uint32_t gsi;
};

int kvm_irqfd_deassign(struct kvm *kvm, struct kvm_irqfd *args);
int kvm_irqfd_assign(struct kvm *kvm, struct kvm_irqfd *args);