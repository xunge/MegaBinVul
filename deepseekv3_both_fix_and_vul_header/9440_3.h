#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct kvm_vcpu;

struct vcpu_vmx {
    u32 exit_reason;
    u32 idt_vectoring_info;
    struct {
        bool nested_run_pending;
    } nested;
    bool fail;
};

struct vmcs12 {
    u32 guest_cr0;
    u32 exception_bitmap;
};

#define VM_EXIT_INTR_INFO 0
#define EXIT_QUALIFICATION 0
#define VM_EXIT_INTR_ERROR_CODE 0
#define VM_INSTRUCTION_ERROR 0
#define KVM_ISA_VMX 0
#define VCPU_REGS_RAX 0
#define INTR_INFO_VECTOR_MASK 0
#define X86_CR0_TS 0

#define EXIT_REASON_EXCEPTION_NMI 0
#define EXIT_REASON_EXTERNAL_INTERRUPT 1
#define EXIT_REASON_TRIPLE_FAULT 2
#define EXIT_REASON_PENDING_INTERRUPT 3
#define EXIT_REASON_NMI_WINDOW 4
#define EXIT_REASON_TASK_SWITCH 5
#define EXIT_REASON_CPUID 6
#define EXIT_REASON_HLT 7
#define EXIT_REASON_INVD 8
#define EXIT_REASON_INVLPG 9
#define EXIT_REASON_RDPMC 10
#define EXIT_REASON_RDTSC 11
#define EXIT_REASON_VMCALL 12
#define EXIT_REASON_VMCLEAR 13
#define EXIT_REASON_VMLAUNCH 14
#define EXIT_REASON_VMPTRLD 15
#define EXIT_REASON_VMPTRST 16
#define EXIT_REASON_VMREAD 17
#define EXIT_REASON_VMRESUME 18
#define EXIT_REASON_VMWRITE 19
#define EXIT_REASON_VMOFF 20
#define EXIT_REASON_VMON 21
#define EXIT_REASON_INVEPT 22
#define EXIT_REASON_INVVPID 23
#define EXIT_REASON_CR_ACCESS 24
#define EXIT_REASON_DR_ACCESS 25
#define EXIT_REASON_IO_INSTRUCTION 26
#define EXIT_REASON_MSR_READ 27
#define EXIT_REASON_MSR_WRITE 28
#define EXIT_REASON_INVALID_STATE 29
#define EXIT_REASON_MWAIT_INSTRUCTION 30
#define EXIT_REASON_MONITOR_INSTRUCTION 31
#define EXIT_REASON_PAUSE_INSTRUCTION 32
#define EXIT_REASON_MCE_DURING_VMENTRY 33
#define EXIT_REASON_TPR_BELOW_THRESHOLD 34
#define EXIT_REASON_APIC_ACCESS 35
#define EXIT_REASON_EPT_VIOLATION 36
#define EXIT_REASON_EPT_MISCONFIG 37
#define EXIT_REASON_WBINVD 38
#define EXIT_REASON_XSETBV 39

#define CPU_BASED_VIRTUAL_INTR_PENDING 0
#define CPU_BASED_VIRTUAL_NMI_PENDING 0
#define CPU_BASED_HLT_EXITING 0
#define CPU_BASED_INVLPG_EXITING 0
#define CPU_BASED_RDPMC_EXITING 0
#define CPU_BASED_RDTSC_EXITING 0
#define CPU_BASED_MOV_DR_EXITING 0
#define CPU_BASED_MWAIT_EXITING 0
#define CPU_BASED_MONITOR_EXITING 0
#define CPU_BASED_PAUSE_EXITING 0
#define CPU_BASED_TPR_SHADOW 0
#define SECONDARY_EXEC_PAUSE_LOOP_EXITING 0
#define SECONDARY_EXEC_VIRTUALIZE_APIC_ACCESSES 0
#define SECONDARY_EXEC_WBINVD_EXITING 0

static inline u32 vmcs_read32(int field) { return 0; }
static inline u32 vmcs_readl(int field) { return 0; }
static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline struct vmcs12 *get_vmcs12(struct kvm_vcpu *vcpu) { return NULL; }
static inline u32 kvm_rip_read(struct kvm_vcpu *vcpu) { return 0; }
static inline u32 kvm_register_read(struct kvm_vcpu *vcpu, int reg) { return 0; }
static inline bool is_exception(u32 intr_info) { return false; }
static inline bool is_page_fault(u32 intr_info) { return false; }
static inline bool is_no_device(u32 intr_info) { return false; }
static inline bool nested_cpu_has(struct vmcs12 *vmcs12, int feature) { return false; }
static inline bool nested_cpu_has2(struct vmcs12 *vmcs12, int feature) { return false; }
static inline bool nested_vmx_exit_handled_cr(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) { return false; }
static inline bool nested_vmx_exit_handled_io(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12) { return false; }
static inline bool nested_vmx_exit_handled_msr(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12, u32 exit_reason) { return false; }
static inline int pr_info_ratelimited(const char *fmt, ...) { return 0; }
static inline int trace_kvm_nested_vmexit(u32 rip, u32 exit_reason, u32 qualification, u32 idt_info, u32 intr_info, u32 error_code, u32 isa) { return 0; }
static inline bool unlikely(bool x) { return x; }

bool enable_ept = false;