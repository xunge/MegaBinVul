#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint64_t u64;

struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        struct {
            void *ops;
        } emulate_ctxt;
        int mp_state;
        void *pio_data;
        void *mce_banks;
        int mcg_cap;
        void *wbinvd_dirty_mask;
        int ia32_tsc_adjust_msr;
        bool pv_time_enabled;
    } arch;
};

struct kvm {
    int dummy;
};

struct page;

#define BUG_ON(condition) ((void)0)
#define GFP_KERNEL 0
#define __GFP_ZERO 0
#define ENOMEM 1
#define KVM_MP_STATE_RUNNABLE 0
#define KVM_MP_STATE_UNINITIALIZED 1
#define KVM_MAX_MCE_BANKS 32

static struct { int dummy; } kvm_no_apic_vcpu;
static unsigned int max_tsc_khz;
static const void *emulate_ops;

static inline struct page *alloc_page(int flags) { return NULL; }
static inline void free_page(unsigned long addr) {}
static inline void *page_address(struct page *page) { return NULL; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(const void *obj) {}
static inline bool zalloc_cpumask_var(void **mask, int flags) { return false; }
static inline void free_cpumask_var(void *mask) {}
static inline void static_key_slow_inc(void *key) {}

static inline int kvm_mmu_create(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_mmu_destroy(struct kvm_vcpu *vcpu) {}
static inline int kvm_create_lapic(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_free_lapic(struct kvm_vcpu *vcpu) {}
static inline void kvm_set_tsc_khz(struct kvm_vcpu *vcpu, unsigned int khz) {}
static inline void kvm_async_pf_hash_reset(struct kvm_vcpu *vcpu) {}
static inline void kvm_pmu_init(struct kvm_vcpu *vcpu) {}
static inline int fx_init(struct kvm_vcpu *vcpu) { return 0; }

static inline bool irqchip_in_kernel(struct kvm *kvm) { return false; }
static inline bool kvm_vcpu_is_bsp(struct kvm_vcpu *vcpu) { return false; }