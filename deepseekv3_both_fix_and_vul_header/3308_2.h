#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint32_t u32;
typedef uint64_t gpa_t;
#define KVM_APIC_CHECK_VAPIC 0
#define EINVAL 22

struct kvm;
struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        struct {
            void *vapic_cache;
            gpa_t vapic_addr;
        } *apic;
        unsigned long apic_attention;
    } arch;
};

static inline void __set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

static inline void __clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

int kvm_gfn_to_hva_cache_init(struct kvm *kvm, void *cache, gpa_t gpa, size_t size);