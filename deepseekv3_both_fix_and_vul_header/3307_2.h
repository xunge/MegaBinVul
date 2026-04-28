#include <stdint.h>
#include <stddef.h>

#define BIT(nr) (1UL << (nr))
#define test_bit(nr, addr) (*(addr) & BIT(nr))

typedef uint32_t u32;
typedef uint64_t gpa_t;

struct page {
    unsigned long flags;
};

struct gfn_to_hva_cache {
    gpa_t gpa;
    unsigned long hva;
    unsigned long len;
};

struct kvm_lapic {
    u32 regs[256];
    struct page *vapic_page;
    gpa_t vapic_addr;
    struct gfn_to_hva_cache vapic_cache;
};

struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        struct kvm_lapic *apic;
        unsigned long apic_attention;
        struct page *vapic_page;
        gpa_t vapic_addr;
    } arch;
};

struct kvm {
    int dummy;
};

#define APIC_TASKPRI 0x80
#define KVM_APIC_CHECK_VAPIC 0

static inline int apic_find_highest_irr(struct kvm_lapic *apic) { return 0; }
static inline int apic_find_highest_isr(struct kvm_lapic *apic) { return 0; }
static inline u32 kvm_apic_get_reg(struct kvm_lapic *apic, int reg) { return 0; }
static inline void apic_sync_pv_eoi_to_guest(struct kvm_vcpu *vcpu, struct kvm_lapic *apic) {}
static inline void kvm_write_guest_cached(struct kvm *kvm, struct gfn_to_hva_cache *ghc, void *data, unsigned long len) {}
static inline void *kmap_atomic(struct page *page) { return NULL; }
static inline void kunmap_atomic(void *addr) {}
static inline size_t offset_in_page(gpa_t addr) { return 0; }