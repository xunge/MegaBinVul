#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define CC(cond) (cond)
#define PAGE_MASK (~(4096UL-1))
#define X86_CR0_PG (1UL << 31)
#define X86_CR0_PE (1UL << 0)
#define X86_CR4_PAE (1UL << 5)
#define VM_ENTRY_IA32E_MODE (1UL << 9)
#define VM_ENTRY_LOAD_DEBUG_CONTROLS (1UL << 2)
#define VM_ENTRY_LOAD_IA32_PAT (1UL << 14)
#define VM_ENTRY_LOAD_IA32_PERF_GLOBAL_CTRL (1UL << 13)
#define VM_ENTRY_LOAD_IA32_EFER (1UL << 15)
#define VM_ENTRY_LOAD_BNDCFGS (1UL << 16)
#define EFER_LMA (1UL << 10)
#define EFER_LME (1UL << 8)
#define MSR_IA32_BNDCFGS_RSVD (0xffffffffUL << 12)
#define EINVAL 22

enum vm_entry_failure_code {
    ENTRY_FAIL_DEFAULT,
    ENTRY_FAIL_VMCS_LINK_PTR
};

struct kvm_vcpu;
struct vmcs12;
struct vmx;

struct vmcs12 {
    unsigned long vm_entry_controls;
    unsigned long guest_cr0;
    unsigned long guest_cr4;
    unsigned long guest_dr7;
    unsigned long guest_ia32_pat;
    uint64_t guest_ia32_perf_global_ctrl;
    uint64_t guest_ia32_efer;
    unsigned long guest_bndcfgs;
};

struct vmx {
    struct {
        bool nested_run_pending;
    } nested;
};

static inline struct vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline bool nested_guest_cr0_valid(struct kvm_vcpu *vcpu, unsigned long cr0) { return false; }
static inline bool nested_guest_cr4_valid(struct kvm_vcpu *vcpu, unsigned long cr4) { return false; }
static inline bool kvm_dr7_valid(unsigned long dr7) { return false; }
static inline bool kvm_pat_valid(unsigned long pat) { return false; }
static inline bool nested_vmx_check_vmcs_link_ptr(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) { return false; }
static inline bool kvm_valid_perf_global_ctrl(void *pmu, uint64_t perf_global_ctrl) { return false; }
static inline void *vcpu_to_pmu(struct kvm_vcpu *vcpu) { return NULL; }
static inline bool kvm_valid_efer(struct kvm_vcpu *vcpu, uint64_t efer) { return false; }
static inline bool is_noncanonical_address(unsigned long addr, struct kvm_vcpu *vcpu) { return false; }
static inline bool nested_check_guest_non_reg_state(struct vmcs12 *vmcs12) { return false; }