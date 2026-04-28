#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint16_t u16;

struct hrtimer {
    int dummy;
};

struct kvm_vcpu {
    struct {
        struct {
            bool nmi_injected;
            unsigned long tsc_offset;
            unsigned long l1_tsc_offset;
            unsigned long tsc_scaling_ratio;
            unsigned long l1_tsc_scaling_ratio;
            int mp_state;
        } arch;
    };
};

struct vcpu_vmx {
    struct {
        bool fail;
        struct {
            bool mtf_pending;
            bool nested_run_pending;
            struct hrtimer preemption_timer;
            int l1_tpr_threshold;
            bool change_vmcs01_virtual_apic_mode;
            bool update_vmcs01_cpu_dirty_logging;
            bool reload_vmcs01_apic_access_page;
            bool update_vmcs01_apicv_status;
            bool need_vmcs12_to_shadow_sync;
            void *hv_evmcs_vmptr;
            void *pi_desc;
            struct {
                bool dummy;
            } apic_access_page_map;
            struct {
                bool dummy;
            } virtual_apic_map;
            struct {
                bool dummy;
            } pi_desc_map;
        } nested;
        struct {
            struct {
                int nr;
            } host;
            struct {
                int nr;
            } guest;
        } msr_autoload;
        struct {
            bool dummy;
        } vmcs01;
    };
};

struct vmcs12 {
    u32 vm_exit_reason;
    unsigned long exit_qualification;
    u32 idt_vectoring_info_field;
    u32 vm_exit_intr_info;
    u32 vm_exit_intr_error_code;
};

#define VM_INSTRUCTION_ERROR 0
#define VM_EXIT_MSR_LOAD_COUNT 0
#define VM_ENTRY_MSR_LOAD_COUNT 0
#define TSC_OFFSET 0
#define TSC_MULTIPLIER 0
#define TPR_THRESHOLD 0

extern bool enable_ept;
extern bool enable_shadow_vmcs;
extern bool nested_early_check;

#define KVM_MP_STATE_RUNNABLE 0
#define KVM_REQ_GET_NESTED_STATE_PAGES 0
#define KVM_REQ_APIC_PAGE_RELOAD 0
#define KVM_REQ_APICV_UPDATE 0
#define X86_FEATURE_SPEC_CTRL 0
#define EXIT_REASON_EXTERNAL_INTERRUPT 0
#define KVM_ISA_VMX 0
#define VMXERR_ENTRY_INVALID_CONTROL_FIELD 0
#define INTR_INFO_VALID_MASK 0
#define INTR_TYPE_EXT_INTR 0
#define SECONDARY_EXEC_TSC_SCALING 0
#define CPU_BASED_USE_TSC_OFFSETTING 0

struct {
    bool has_tsc_control;
} kvm_caps;

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline struct vmcs12 *get_vmcs12(struct kvm_vcpu *vcpu) { return NULL; }
static inline bool kvm_check_request(int req, struct kvm_vcpu *vcpu) { return false; }
static inline void kvm_service_local_tlb_flush_requests(struct kvm_vcpu *vcpu) {}
static inline bool is_pae_paging(struct kvm_vcpu *vcpu) { return false; }
static inline void vmx_ept_load_pdptrs(struct kvm_vcpu *vcpu) {}
static inline void leave_guest_mode(struct kvm_vcpu *vcpu) {}
static inline bool nested_cpu_has_preemption_timer(struct vmcs12 *vmcs12) { return false; }
static inline void hrtimer_cancel(struct hrtimer *timer) {}
static inline bool nested_cpu_has(struct vmcs12 *vmcs12, u32 flag) { return false; }
static inline bool nested_cpu_has2(struct vmcs12 *vmcs12, u32 flag) { return false; }
static inline void sync_vmcs02_to_vmcs12(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) {}
static inline void prepare_vmcs12(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12, u32 reason, u32 info, unsigned long qual) {}
static inline void nested_flush_cached_shadow_vmcs12(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) {}
static inline void kvm_clear_exception_queue(struct kvm_vcpu *vcpu) {}
static inline void kvm_clear_interrupt_queue(struct kvm_vcpu *vcpu) {}
static inline void vmx_switch_vmcs(struct kvm_vcpu *vcpu, void *vmcs) {}
static inline bool guest_cpuid_has(struct kvm_vcpu *vcpu, int feature) { return false; }
static inline void indirect_branch_prediction_barrier(void) {}
static inline void vmcs_write32(u32 field, u32 value) {}
static inline void vmcs_write64(u32 field, u64 value) {}
static inline void vmx_set_virtual_apic_mode(struct kvm_vcpu *vcpu) {}
static inline void vmx_update_cpu_dirty_logging(struct kvm_vcpu *vcpu) {}
static inline void kvm_vcpu_unmap(struct kvm_vcpu *vcpu, void *map, bool dirty) {}
static inline void kvm_make_request(int req, struct kvm_vcpu *vcpu) {}
static inline bool evmptr_is_valid(void *ptr) { return false; }
static inline bool nested_exit_intr_ack_set(struct kvm_vcpu *vcpu) { return false; }
static inline int kvm_cpu_get_interrupt(struct kvm_vcpu *vcpu) { return 0; }
static inline void trace_kvm_nested_vmexit_inject(u32 reason, unsigned long qual, u32 info, u32 intr_info, u32 error, int isa) {}
static inline void load_vmcs12_host_state(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) {}
static inline bool nested_vmx_fail(struct kvm_vcpu *vcpu, u32 reason) { return false; }
static inline void nested_vmx_restore_host_state(struct kvm_vcpu *vcpu) {}
static inline u32 vmcs_read32(u32 field) { return 0; }
static inline bool likely(bool x) { return x; }
static inline void WARN_ON_ONCE(bool condition) {}
static inline void WARN_ON(bool condition) {}
static inline void nested_get_evmcs_page(struct kvm_vcpu *vcpu) {}