#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef uint16_t u16;
typedef uint32_t u32;

struct kvm {
    struct {
        pthread_mutex_t apic_map_lock;
        struct kvm_apic_map *apic_map;
    } arch;
};

struct kvm_vcpu {
    struct {
        struct kvm_lapic *apic;
    } arch;
};

struct kvm_lapic {
    int id;
    uint32_t regs[256];
};

struct kvm_apic_map {
    uint8_t ldr_bits;
    uint8_t cid_shift;
    uint16_t cid_mask;
    uint16_t lid_mask;
    struct kvm_lapic *phys_map[256];
    struct kvm_lapic *logical_map[256][16];
};

#define KVM_X2APIC_CID_BITS 16
#define APIC_DFR 0xe0
#define APIC_DFR_CLUSTER 0x0FFFFFFF
#define APIC_LDR 0xd0
#define GFP_KERNEL 0

static inline int kvm_apic_present(struct kvm_vcpu *vcpu) { return vcpu && vcpu->arch.apic; }
static inline int apic_x2apic_mode(struct kvm_lapic *apic) { return 0; }
static inline int kvm_apic_sw_enabled(struct kvm_lapic *apic) { return 1; }
static inline u32 kvm_apic_get_reg(struct kvm_lapic *apic, int reg) { return apic ? apic->regs[reg] : 0; }
static inline int kvm_apic_id(struct kvm_lapic *apic) { return apic ? apic->id : 0; }
static inline u16 apic_cluster_id(struct kvm_apic_map *map, u32 ldr) { return 0; }
static inline u16 apic_logical_id(struct kvm_apic_map *map, u32 ldr) { return 0; }
static inline void kvm_vcpu_request_scan_ioapic(struct kvm *kvm) {}

static inline void *kzalloc(size_t size, int flags) {
    void *ptr = malloc(size);
    if (ptr) memset(ptr, 0, size);
    return ptr;
}

static inline void mutex_lock(pthread_mutex_t *lock) {
    pthread_mutex_lock(lock);
}

static inline void mutex_unlock(pthread_mutex_t *lock) {
    pthread_mutex_unlock(lock);
}

static inline void kfree_rcu(void *ptr, void *unused) {
    free(ptr);
}

#define kvm_for_each_vcpu(i, vcpu, kvm) \
    for (i = 0, vcpu = NULL; i < 1; i++)

#define rcu_assign_pointer(p, v) do { (p) = (v); } while (0)
#define rcu_dereference_protected(p, c) (p)
#define lockdep_is_held(lock) (1)
#define rcu (void*)0