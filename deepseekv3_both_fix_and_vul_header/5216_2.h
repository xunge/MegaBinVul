#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

struct kvm_vcpu {
    struct {
        struct {
            int guest_mmu;
        } arch;
    };
};

struct hrtimer {
    // minimal hrtimer definition
};

struct loaded_vmcs {
    // minimal loaded_vmcs definition
};

struct page {
    // minimal page definition
};

struct vcpu_vmx {
    struct {
        bool vmxon;
        struct {
            bool vmxon;
        } smm;
        int vpid02;
        int posted_intr_nv;
        uint64_t current_vmptr;
        void *cached_vmcs12;
        void *cached_shadow_vmcs12;
        struct page *apic_access_page;
        struct page *virtual_apic_page;
        struct page *pi_desc_page;
        void *pi_desc;
        struct hrtimer preemption_timer;
        struct loaded_vmcs vmcs02;
    } nested;
    struct {
        void *shadow_vmcs;
    } vmcs01;
};

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static void free_vpid(int vpid) {}
static void vmx_disable_shadow_vmcs(struct vcpu_vmx *vmx) {}
static void vmcs_clear(void *vmcs) {}
static void free_vmcs(void *vmcs) {}
static void kfree(const void *objp) {}
static void kvm_release_page_dirty(struct page *page) {}
static void kunmap(struct page *page) {}
static void kvm_mmu_free_roots(struct kvm_vcpu *vcpu, void *mmu, int roots) {}
static void nested_release_evmcs(struct kvm_vcpu *vcpu) {}
static void free_loaded_vmcs(struct loaded_vmcs *vmcs) {}
static void hrtimer_cancel(struct hrtimer *timer) {}

#define KVM_MMU_ROOTS_ALL 0
extern bool enable_shadow_vmcs;