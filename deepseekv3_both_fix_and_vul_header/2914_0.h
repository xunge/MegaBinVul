#include <stdbool.h>

#define EINVAL 22

struct kvm_vcpu {
    struct {
        bool pv_time_enabled;
        bool pvclock_set_guest_stopped_request;
        void *time_page;
    } arch;
};

#define KVM_REQ_CLOCK_UPDATE 0

static inline void kvm_make_request(int req, struct kvm_vcpu *vcpu) {}