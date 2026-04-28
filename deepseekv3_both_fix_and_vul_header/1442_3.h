#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t u64;

union hv_stimer_config {
    uint64_t as_uint64;
    struct {
        bool enable:1;
        bool periodic:1;
        bool lazy:1;
        bool direct_mode:1;
        uint8_t sintx:4;
    };
};

struct kvm_vcpu {
    int vcpu_id;
};

struct kvm_vcpu_hv_stimer {
    union hv_stimer_config config;
    int index;
};

struct kvm_vcpu_hv_synic {
    bool active;
};

struct hv_vcpu_cpuid_cache {
    uint32_t features_edx;
};

struct kvm_vcpu_hv {
    bool enforce_cpuid;
    struct hv_vcpu_cpuid_cache cpuid_cache;
};

#define HV_STIMER_DIRECT_MODE_AVAILABLE (1 << 0)

static inline struct kvm_vcpu *hv_stimer_to_vcpu(struct kvm_vcpu_hv_stimer *stimer) { return NULL; }
static inline struct kvm_vcpu_hv *to_hv_vcpu(struct kvm_vcpu *vcpu) { return NULL; }
static inline struct kvm_vcpu_hv_synic *to_hv_synic(struct kvm_vcpu *vcpu) { return NULL; }
static inline void stimer_cleanup(struct kvm_vcpu_hv_stimer *stimer) {}
static inline void stimer_mark_pending(struct kvm_vcpu_hv_stimer *stimer, bool periodic) {}
static inline void trace_kvm_hv_stimer_set_config(int vcpu_id, int index, u64 config, bool host) {}

#define unlikely(x) (x)