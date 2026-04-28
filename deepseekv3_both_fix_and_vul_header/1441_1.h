#include <stdbool.h>
#include <stdint.h>

typedef uint64_t u64;

struct kvm_vcpu {
    int vcpu_id;
};

struct kvm_vcpu_hv_synic {
    bool active;
};

struct kvm_vcpu_hv_stimer {
    u64 count;
    int index;
    struct {
        bool enable;
        bool auto_enable;
    } config;
};

struct kvm_vcpu *hv_stimer_to_vcpu(struct kvm_vcpu_hv_stimer *stimer);
struct kvm_vcpu_hv_synic *to_hv_synic(struct kvm_vcpu *vcpu);
void stimer_cleanup(struct kvm_vcpu_hv_stimer *stimer);
void stimer_mark_pending(struct kvm_vcpu_hv_stimer *stimer, bool arg);
void trace_kvm_hv_stimer_set_count(int vcpu_id, int index, u64 count, bool host);