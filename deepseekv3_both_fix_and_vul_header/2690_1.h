#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;

struct kvm_vcpu {
    struct {
        uint64_t dr7;
        uint64_t tsc_offset;
        uint64_t pat;
        uint64_t efer;
        uint64_t cr0_guest_owned_bits;
        struct {
            void (*inject_page_fault)(struct kvm_vcpu *vcpu);
        } *walk_mmu;
    } arch;
};

struct vmcs12;
struct vcpu_vmx;

#define GUEST_ES_SELECTOR 0
#define GUEST_CS_SELECTOR 0
#define GUEST_SS_SELECTOR 0
#define GUEST_DS_SELECTOR 0
#define GUEST_FS_SELECTOR 0
#define GUEST_GS_SELECTOR 0
#define GUEST_LDTR_SELECTOR 0
#define GUEST_TR_SELECTOR 0
#define GUEST_ES_LIMIT 0
#define GUEST_CS_LIMIT 0
#define GUEST_SS_LIMIT 0
#define GUEST_DS_LIMIT 0
#define GUEST_FS_LIMIT 0
#define GUEST_GS_LIMIT 0
#define GUEST_LDTR_LIMIT 0
#define GUEST_TR_LIMIT 0
#define GUEST_GDTR_LIMIT 0
#define GUEST_IDTR_LIMIT 0
#define GUEST_ES_AR_BYTES 0
#define GUEST_CS_AR_BYTES 0
#define GUEST_SS_AR_BYTES 0
#define GUEST_DS_AR_BYTES 0
#define GUEST_FS_AR_BYTES 0
#define GUEST_GS_AR_BYTES 0
#define GUEST_LDTR_AR_BYTES 0
#define GUEST_TR_AR_BYTES 0
#define GUEST_ES_BASE 0
#define GUEST_CS_BASE 0
#define GUEST_SS_BASE 0
#define GUEST_DS_BASE 0
#define GUEST_FS_BASE 0
#define GUEST_GS_BASE 0
#define GUEST_LDTR_BASE 0
#define GUEST_TR_BASE 0
#define GUEST_GDTR_BASE 0
#define GUEST_IDTR_BASE 0
#define GUEST_IA32_DEBUGCTL 0
#define VM_ENTRY_INTR_INFO_FIELD 0
#define VM_ENTRY_EXCEPTION_ERROR_CODE 0
#define VM_ENTRY_INSTRUCTION_LEN 0
#define GUEST_INTERRUPTIBILITY_INFO 0
#define GUEST_SYSENTER_CS 0
#define GUEST_PENDING_DBG_EXCEPTIONS 0
#define GUEST_SYSENTER_ESP 0
#define GUEST_SYSENTER_EIP 0
#define XSS_EXIT_BITMAP 0
#define VMCS_LINK_POINTER 0
#define PIN_BASED_VM_EXEC_CONTROL 0
#define POSTED_INTR_NV 0
#define PAGE_FAULT_ERROR_CODE_MASK 0
#define PAGE_FAULT_ERROR_CODE_MATCH 0
#define SECONDARY_VM_EXEC_CONTROL 0
#define VM_FUNCTION_CONTROL 0
#define EOI_EXIT_BITMAP0 0
#define EOI_EXIT_BITMAP1 0
#define EOI_EXIT_BITMAP2 0
#define EOI_EXIT_BITMAP3 0
#define GUEST_INTR_STATUS 0
#define APIC_ACCESS_ADDR 0
#define VM_EXIT_MSR_STORE_COUNT 0
#define VM_EXIT_MSR_LOAD_COUNT 0
#define VM_EXIT_MSR_LOAD_ADDR 0
#define VM_ENTRY_MSR_LOAD_COUNT 0
#define VM_ENTRY_MSR_LOAD_ADDR 0
#define VIRTUAL_APIC_PAGE_ADDR 0
#define TPR_THRESHOLD 0
#define CPU_BASED_VM_EXEC_CONTROL 0
#define CR0_GUEST_HOST_MASK 0
#define VM_EXIT_CONTROLS 0
#define GUEST_IA32_PAT 0
#define GUEST_BNDCFGS 0
#define TSC_OFFSET 0
#define VIRTUAL_PROCESSOR_ID 0
#define PML_ADDRESS 0
#define GUEST_PML_INDEX 0
#define CR0_READ_SHADOW 0
#define CR4_READ_SHADOW 0
#define GUEST_PDPTR0 0
#define GUEST_PDPTR1 0
#define GUEST_PDPTR2 0
#define GUEST_PDPTR3 0

#define VM_ENTRY_LOAD_DEBUG_CONTROLS 0
#define PIN_BASED_VMX_PREEMPTION_TIMER 0
#define PIN_BASED_POSTED_INTR 0
#define SECONDARY_EXEC_VIRTUALIZE_APIC_ACCESSES 0
#define SECONDARY_EXEC_ENABLE_INVPCID 0
#define SECONDARY_EXEC_RDTSCP 0
#define SECONDARY_EXEC_XSAVES 0
#define SECONDARY_EXEC_VIRTUAL_INTR_DELIVERY 0
#define SECONDARY_EXEC_APIC_REGISTER_VIRT 0
#define SECONDARY_EXEC_ENABLE_VMFUNC 0
#define SECONDARY_EXEC_ENABLE_PML 0
#define CPU_BASED_VIRTUAL_INTR_PENDING 0
#define CPU_BASED_VIRTUAL_NMI_PENDING 0
#define CPU_BASED_TPR_SHADOW 0
#define CPU_BASED_USE_IO_BITMAPS 0
#define CPU_BASED_UNCOND_IO_EXITING 0
#define CPU_BASED_USE_TSC_OFFSETING 0
#define CPU_BASED_ACTIVATE_SECONDARY_CONTROLS 0
#define VM_ENTRY_LOAD_IA32_EFER 0
#define VM_ENTRY_IA32E_MODE 0
#define VM_ENTRY_LOAD_IA32_PAT 0
#define VM_ENTRY_LOAD_BNDCFGS 0
#define GUEST_INTR_STATE_NMI 0
#define ENTRY_FAIL_DEFAULT 0
#define PML_ENTITY_NUM 0
#define POSTED_INTR_NESTED_VECTOR 0
#define EFER_LMA 0
#define EFER_LME 0
#define VCPU_REGS_RSP 0
#define VCPU_REGS_RIP 0

struct vmcs_config {
    uint32_t pin_based_exec_ctrl;
    uint32_t vmexit_ctrl;
    uint32_t vmentry_ctrl;
};

struct vmcs12 {
    uint16_t guest_es_selector;
    uint16_t guest_cs_selector;
    uint16_t guest_ss_selector;
    uint16_t guest_ds_selector;
    uint16_t guest_fs_selector;
    uint16_t guest_gs_selector;
    uint16_t guest_ldtr_selector;
    uint16_t guest_tr_selector;
    uint32_t guest_es_limit;
    uint32_t guest_cs_limit;
    uint32_t guest_ss_limit;
    uint32_t guest_ds_limit;
    uint32_t guest_fs_limit;
    uint32_t guest_gs_limit;
    uint32_t guest_ldtr_limit;
    uint32_t guest_tr_limit;
    uint32_t guest_gdtr_limit;
    uint32_t guest_idtr_limit;
    uint32_t guest_es_ar_bytes;
    uint32_t guest_cs_ar_bytes;
    uint32_t guest_ss_ar_bytes;
    uint32_t guest_ds_ar_bytes;
    uint32_t guest_fs_ar_bytes;
    uint32_t guest_gs_ar_bytes;
    uint32_t guest_ldtr_ar_bytes;
    uint32_t guest_tr_ar_bytes;
    uint64_t guest_es_base;
    uint64_t guest_cs_base;
    uint64_t guest_ss_base;
    uint64_t guest_ds_base;
    uint64_t guest_fs_base;
    uint64_t guest_gs_base;
    uint64_t guest_ldtr_base;
    uint64_t guest_tr_base;
    uint64_t guest_gdtr_base;
    uint64_t guest_idtr_base;
    uint64_t guest_ia32_debugctl;
    uint32_t vm_entry_intr_info_field;
    uint32_t vm_entry_exception_error_code;
    uint32_t vm_entry_instruction_len;
    uint32_t guest_interruptibility_info;
    uint32_t guest_sysenter_cs;
    uint64_t guest_pending_dbg_exceptions;
    uint64_t guest_sysenter_esp;
    uint64_t guest_sysenter_eip;
    uint64_t xss_exit_bitmap;
    uint32_t pin_based_vm_exec_control;
    uint32_t cpu_based_vm_exec_control;
    uint32_t secondary_vm_exec_control;
    uint32_t vm_entry_controls;
    uint32_t vm_exit_controls;
    uint64_t eoi_exit_bitmap0;
    uint64_t eoi_exit_bitmap1;
    uint64_t eoi_exit_bitmap2;
    uint64_t eoi_exit_bitmap3;
    uint16_t guest_intr_status;
    uint32_t page_fault_error_code_mask;
    uint32_t page_fault_error_code_match;
    uint64_t guest_ia32_pat;
    uint64_t guest_bndcfgs;
    uint64_t tsc_offset;
    uint16_t virtual_processor_id;
    uint64_t guest_cr0;
    uint64_t guest_cr3;
    uint64_t guest_cr4;
    uint64_t guest_ia32_efer;
    uint64_t guest_pdptr0;
    uint64_t guest_pdptr1;
    uint64_t guest_pdptr2;
    uint64_t guest_pdptr3;
    uint64_t guest_rflags;
    uint64_t guest_rsp;
    uint64_t guest_rip;
    uint64_t guest_dr7;
    uint32_t tpr_threshold;
    uint32_t posted_intr_nv;
    uint32_t cr0_guest_host_mask;
};

struct vcpu_vmx {
    struct kvm_vcpu vcpu;
    struct {
        uint64_t vmcs01_debugctl;
        uint32_t last_vpid;
        uint16_t vpid02;
        bool pi_pending;
        bool preemption_timer_expired;
        uint8_t posted_intr_nv;
    } nested;
    uint64_t hv_deadline_tsc;
    uint32_t secondary_exec_control;
    uint64_t host_rsp;
    struct {
        void *host;
        void *guest;
        uint32_t nr;
    } msr_autoload;
    struct {
        bool nmi_known_unmasked;
    } *loaded_vmcs;
    void *pml_pg;
    uint16_t vpid;
};

extern struct vmcs_config vmcs_config;
extern bool enable_ept;
extern bool enable_vpid;
extern bool enable_pml;
extern bool kvm_has_tsc_control;

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline void vmcs_write16(uint32_t field, uint16_t val) {}
static inline void vmcs_write32(uint32_t field, uint32_t val) {}
static inline void vmcs_writel(uint32_t field, uint64_t val) {}
static inline void vmcs_write64(uint32_t field, uint64_t val) {}
static inline void kvm_set_dr(struct kvm_vcpu *vcpu, int dr, uint64_t val) {}
static inline bool nested_cpu_has_xsaves(struct vmcs12 *vmcs12) { return false; }
static inline bool nested_cpu_has_posted_intr(struct vmcs12 *vmcs12) { return false; }
static inline bool nested_cpu_has_preemption_timer(struct vmcs12 *vmcs12) { return false; }
static inline void vmx_start_preemption_timer(struct kvm_vcpu *vcpu) {}
static inline bool cpu_has_secondary_exec_ctrls() { return false; }
static inline bool nested_cpu_has(struct vmcs12 *vmcs12, uint32_t bit) { return false; }
static inline bool nested_cpu_has2(struct vmcs12 *vmcs12, uint32_t bit) { return false; }
static inline void vmx_set_constant_host_state(struct vcpu_vmx *vmx) {}
static inline uint32_t vmx_exec_control(struct vcpu_vmx *vmx) { return 0; }
static inline void update_exception_bitmap(struct kvm_vcpu *vcpu) {}
static inline void vm_entry_controls_init(struct vcpu_vmx *vmx, uint32_t val) {}
static inline void set_cr4_guest_host_mask(struct vcpu_vmx *vmx) {}
static inline void decache_tsc_multiplier(struct vcpu_vmx *vmx) {}
static inline bool nested_cpu_has_vpid(struct vmcs12 *vmcs12) { return false; }
static inline void __vmx_flush_tlb(struct kvm_vcpu *vcpu, uint16_t vpid) {}
static inline void vmx_flush_tlb(struct kvm_vcpu *vcpu) {}
static inline bool nested_cpu_has_ept(struct vmcs12 *vmcs12) { return false; }
static inline bool nested_ept_init_mmu_context(struct kvm_vcpu *vcpu) { return false; }
static inline void vmx_flush_tlb_ept_only(struct kvm_vcpu *vcpu) {}
static inline void vmx_set_cr0(struct kvm_vcpu *vcpu, uint64_t val) {}
static inline uint64_t nested_read_cr0(struct vmcs12 *vmcs12) { return 0; }
static inline void vmx_set_cr4(struct kvm_vcpu *vcpu, uint64_t val) {}
static inline uint64_t nested_read_cr4(struct vmcs12 *vmcs12) { return 0; }
static inline void vmx_set_efer(struct kvm_vcpu *vcpu, uint64_t val) {}
static inline bool nested_vmx_load_cr3(struct kvm_vcpu *vcpu, uint64_t cr3, bool nested_ept, u32 *entry_failure_code) { return false; }
static inline void vmx_inject_page_fault_nested(struct kvm_vcpu *vcpu) {}
static inline void kvm_register_write(struct kvm_vcpu *vcpu, int reg, uint64_t val) {}
static inline void vmx_set_rflags(struct kvm_vcpu *vcpu, uint64_t val) {}
static inline uint64_t __pa(void *ptr) { return 0; }