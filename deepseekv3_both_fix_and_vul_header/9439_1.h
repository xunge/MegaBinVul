#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;

struct kvm_vcpu;
struct vcpu_vmx {
    u32 exit_reason;
    struct {
        bool nested_run_pending;
    } nested;
    bool fail;
};
struct vmcs12 {
    u32 exception_bitmap;
    u32 pin_based_vm_exec_control;
};

#define VM_EXIT_INTR_INFO 0
#define VM_INSTRUCTION_ERROR 0
#define INTR_INFO_VECTOR_MASK 0

#define EXIT_REASON_EXCEPTION_NMI 0
#define EXIT_REASON_EXTERNAL_INTERRUPT 1
#define EXIT_REASON_TRIPLE_FAULT 2
#define EXIT_REASON_PENDING_INTERRUPT 7
#define EXIT_REASON_NMI_WINDOW 8
#define EXIT_REASON_TASK_SWITCH 9
#define EXIT_REASON_CPUID 10
#define EXIT_REASON_HLT 12
#define EXIT_REASON_INVD 13
#define EXIT_REASON_INVLPG 14
#define EXIT_REASON_RDPMC 15
#define EXIT_REASON_RDTSC 16
#define EXIT_REASON_VMCALL 18
#define EXIT_REASON_VMCLEAR 19
#define EXIT_REASON_VMLAUNCH 20
#define EXIT_REASON_VMPTRLD 21
#define EXIT_REASON_VMPTRST 22
#define EXIT_REASON_VMREAD 23
#define EXIT_REASON_VMRESUME 24
#define EXIT_REASON_VMWRITE 25
#define EXIT_REASON_VMOFF 26
#define EXIT_REASON_VMON 27
#define EXIT_REASON_INVEPT 28
#define EXIT_REASON_CR_ACCESS 29
#define EXIT_REASON_DR_ACCESS 30
#define EXIT_REASON_IO_INSTRUCTION 31
#define EXIT_REASON_MSR_READ 32
#define EXIT_REASON_MSR_WRITE 33
#define EXIT_REASON_INVALID_STATE 34
#define EXIT_REASON_MWAIT_INSTRUCTION 36
#define EXIT_REASON_MONITOR_INSTRUCTION 37
#define EXIT_REASON_PAUSE_INSTRUCTION 38
#define EXIT_REASON_MCE_DURING_VMENTRY 39
#define EXIT_REASON_TPR_BELOW_THRESHOLD 40
#define EXIT_REASON_APIC_ACCESS 41
#define EXIT_REASON_EPT_VIOLATION 42
#define EXIT_REASON_EPT_MISCONFIG 43
#define EXIT_REASON_PREEMPTION_TIMER 44
#define EXIT_REASON_WBINVD 45
#define EXIT_REASON_XSETBV 46

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
#define SECONDARY_EXEC_PAUSE_LOOP_EXITING 0
#define SECONDARY_EXEC_VIRTUALIZE_APIC_ACCESSES 0
#define PIN_BASED_VMX_PREEMPTION_TIMER 0
#define SECONDARY_EXEC_WBINVD_EXITING 0

static u32 vmcs_read32(int field);
static bool is_exception(u32 intr_info);
static bool is_page_fault(u32 intr_info);
static bool enable_ept;
static bool nested_cpu_has(struct vmcs12 *vmcs12, int flag);
static bool nested_cpu_has2(struct vmcs12 *vmcs12, int flag);
static bool nested_vmx_exit_handled_cr(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12);
static bool nested_vmx_exit_handled_io(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12);
static bool nested_vmx_exit_handled_msr(struct kvm_vcpu *vcpu, struct vmcs12 *vmcs12, u32 exit_reason);
static int pr_info_ratelimited(const char *fmt, ...);
static struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu);
static struct vmcs12 *get_vmcs12(struct kvm_vcpu *vcpu);
#define unlikely(x) (x)