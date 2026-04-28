#include <stdint.h>
#include <stddef.h>

#define KVM_APIC_PV_EOI_PENDING 0
#define KVM_APIC_CHECK_VAPIC 1

typedef uint32_t u32;
typedef uint8_t u8;

struct gfn_to_hva_cache {
    uint64_t gpa;
    void *hva;
    size_t len;
};

struct kvm_apic {
    void *vapic_page;
    unsigned long vapic_addr;
    struct gfn_to_hva_cache vapic_cache;
};

struct kvm;

struct kvm_vcpu_arch {
    struct kvm_apic *apic;
    unsigned long apic_attention;
};

struct kvm_vcpu {
    struct kvm *kvm;
    struct kvm_vcpu_arch arch;
};

static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void apic_sync_pv_eoi_from_guest(struct kvm_vcpu *vcpu, struct kvm_apic *apic) {}
static inline void apic_set_tpr(struct kvm_apic *apic, u8 tpr) {}
static inline int kvm_read_guest_cached(struct kvm *kvm, struct gfn_to_hva_cache *ghc, void *data, unsigned len) { return 0; }
static inline void *kmap_atomic(void *page) { return NULL; }
static inline void kunmap_atomic(void *addr) {}
static inline size_t offset_in_page(unsigned long addr) { return 0; }