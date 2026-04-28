#include <stdint.h>
#include <stdbool.h>

typedef uint32_t bool_t;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;

struct cpu_user_regs {
    uint64_t eip;
    uint32_t _eax;
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
    uint32_t esi;
    uint32_t edi;
    uint32_t error_code;
    uint64_t rdx;
    uint64_t rip;
};

struct domain {
    bool debugger_attached;
};

struct hvm_vcpu {
    uint64_t guest_cr[16];
    uint64_t hw_cr[16];
};

struct hvm_svm {
    struct vmcb_struct *vmcb;
    uint32_t cached_insn_len;
};

struct arch_vcpu {
    struct hvm_vcpu hvm_vcpu;
    struct hvm_svm hvm_svm;
    uint64_t gdbsx_vcpu_event;
};

struct vcpu {
    struct domain *domain;
    struct arch_vcpu arch;
};

typedef struct {
    uint32_t bytes;
    struct {
        uint8_t type;
        uint8_t vector;
        uint8_t v;
    } fields;
} eventinj_t;

struct vmcb_struct {
    uint64_t exitcode;
    uint64_t exitinfo1;
    uint64_t exitinfo2;
    uint64_t rip;
    uint64_t nextrip;
    uint32_t guest_ins_len;
    struct {
        uint32_t bytes;
    } cleanbits;
    eventinj_t exitintinfo;
    eventinj_t eventinj;
    uint8_t interrupt_shadow;
};

struct nestedvcpu {
    struct vmcb_struct *nv_vvmcx;
    uint32_t nv_vmswitch_in_progress;
};

typedef struct {
    uint32_t bytes;
    struct {
        uint8_t tpr;
        uint8_t irq;
        uint8_t v;
    } fields;
} vintr_t;

enum nestedhvm_vmexits {
    NESTEDHVM_VMEXIT_CONTINUE,
    NESTEDHVM_VMEXIT_HOST,
    NESTEDHVM_VMEXIT_INJECT,
    NESTEDHVM_VMEXIT_DONE,
    NESTEDHVM_VMEXIT_FATALERROR,
    NESTEDHVM_VMEXIT_ERROR
};

enum hvm_task_switch_reason {
    TSW_iret,
    TSW_jmp,
    TSW_call_or_int
};

#define VMEXIT_INVALID 0
#define VMEXIT_INTR 1
#define VMEXIT_NMI 2
#define VMEXIT_SMI 3
#define VMEXIT_EXCEPTION_DB 4
#define VMEXIT_EXCEPTION_BP 5
#define VMEXIT_EXCEPTION_NM 6
#define VMEXIT_EXCEPTION_PF 7
#define VMEXIT_EXCEPTION_UD 8
#define VMEXIT_EXCEPTION_MC 9
#define VMEXIT_EXCEPTION_AC 10
#define VMEXIT_VINTR 11
#define VMEXIT_INVD 12
#define VMEXIT_WBINVD 13
#define VMEXIT_TASK_SWITCH 14
#define VMEXIT_CPUID 15
#define VMEXIT_HLT 16
#define VMEXIT_IOIO 17
#define VMEXIT_CR0_READ 18
#define VMEXIT_CR15_READ 19
#define VMEXIT_CR0_WRITE 20
#define VMEXIT_CR15_WRITE 21
#define VMEXIT_INVLPG 22
#define VMEXIT_INVLPGA 23
#define VMEXIT_VMMCALL 24
#define VMEXIT_DR0_READ 25
#define VMEXIT_DR7_READ 26
#define VMEXIT_DR0_WRITE 27
#define VMEXIT_DR7_WRITE 28
#define VMEXIT_MSR 29
#define VMEXIT_SHUTDOWN 30
#define VMEXIT_RDTSCP 31
#define VMEXIT_RDTSC 32
#define VMEXIT_MONITOR 33
#define VMEXIT_MWAIT 34
#define VMEXIT_VMRUN 35
#define VMEXIT_VMLOAD 36
#define VMEXIT_VMSAVE 37
#define VMEXIT_STGI 38
#define VMEXIT_CLGI 39
#define VMEXIT_SKINIT 40
#define VMEXIT_XSETBV 41
#define VMEXIT_NPF 42
#define VMEXIT_IRET 43
#define VMEXIT_PAUSE 44
#define VMEXIT_NPF_PERFC 45

#define TRAP_debug 1
#define TRAP_alignment_check 17
#define TRAP_gp_fault 13
#define TRAP_invalid_op 6
#define TRAP_int3 3

#define PFEC_page_present 0x01

#define GENERAL1_INTERCEPT_VINTR 0x00000001
#define GENERAL1_INTERCEPT_IRET 0x00000002

#define APIC_TASKPRI 0x80

#define IOREQ_READ 0
#define IOREQ_WRITE 1

#define HVM_HCALL_preempted 0
#define HVM_HCALL_invalidate 1

#define TRC_HVM_NESTEDFLAG 0x80000000
#define TRC_SHADOW 0

#define INSTR_INT3 0
#define INSTR_INVLPGA 1
#define INSTR_VMCALL 2
#define INSTR_XSETBV 3

#define HVM_DELIVER_NO_ERROR_CODE 0

#define XENLOG_ERR 0
#define XENLOG_G_ERR 1
#define XENLOG_INFO 2
#define DBG_LEVEL_VMMU 0

#define PRIx64 "llx"

#define BUG() 
#define BUG_ON(cond) 

#define HVMTRACE_ND(event, flags, cycles, n, ...) 
#define HVMTRACE_0D(event) 
#define HVMTRACE_1D(event, arg) 
#define HVMTRACE_2D(event, arg1, arg2) 
#define HVMTRACE_LONG_2D(event, arg1, arg2) 
#define TRC_PAR_LONG(x) (x)

#define HVM_DBG_LOG(level, fmt, ...) 

#define perfc_incra(counter, value) 

#define gdprintk(level, fmt, ...) 
#define printk(level, fmt, ...) 

#define domain_crash(domain) 
#define domain_pause_for_debugger() 

#define cpu_has_svm_cleanbits 0
#define cpu_has_svm_decode 0

#define nestedhvm_enabled(v) 0
#define nestedhvm_vcpu_in_guestmode(v) 0
#define hvm_long_mode_enabled(v) 0
#define paging_mode_hap(v) 0

#define unlikely(cond) (cond)
#define likely(cond) (cond)

#define current ((struct vcpu *)0)

#define vlapic_set_reg(vlapic, reg, value) 
#define vlapic_get_reg(vlapic, reg) 0
#define vcpu_vlapic(v) ((void *)0)

#define vmcb_get_cr3(vmcb) 0
#define vmcb_get_vintr(vmcb) (vintr_t){0}
#define vmcb_set_vintr(vmcb, intr) 
#define vmcb_get_general1_intercepts(vmcb) 0
#define vmcb_set_general1_intercepts(vmcb, intercepts) 

#define hvm_invalidate_regs_fields(regs) 
#define hvm_event_needs_reinjection(type, vector) 0
#define hvm_maybe_deassert_evtchn_irq() 
#define hvm_inject_page_fault(error_code, va) 
#define hvm_inject_hw_exception(trap, error_code) 
#define hvm_do_hypercall(regs) 0
#define hvm_triple_fault() 
#define hvm_msr_tsc_aux(v) 0
#define hvm_handle_xsetbv(reg, value) 0
#define hvm_task_switch(selector, reason, errcode) 

#define paging_fault(va, regs) 0
#define paging_update_nestedmode(v) 
#define p2m_pt_handle_deferred_changes(gpa) 0

#define handle_pio(port, bytes, dir) 0
#define handle_mmio() 0

#define send_invalidate_req() 

#define svm_vmcb_dump(func, vmcb) 
#define svm_fpu_dirty_intercept() 
#define svm_vmexit_ud_intercept(regs) 
#define svm_vmexit_mce_intercept(v, regs) 
#define svm_vmexit_do_invalidate_cache(regs) 
#define svm_vmexit_do_cpuid(regs) 
#define svm_vmexit_do_hlt(vmcb, regs) 
#define svm_vmexit_do_cr_access(vmcb, regs) 
#define svm_invlpg_intercept(va) 
#define svm_invlpga_intercept(v, eax, ecx) 
#define svm_dr_access(v, regs) 
#define svm_do_msr_access(regs) 
#define svm_vmexit_do_rdtsc(regs) 
#define svm_vmexit_do_vmrun(regs, v, eax) 
#define svm_vmexit_do_vmload(vmcb, regs, v, eax) 
#define svm_vmexit_do_vmsave(vmcb, regs, v, eax) 
#define svm_vmexit_do_stgi(regs, v) 
#define svm_vmexit_do_clgi(regs, v) 
#define svm_vmexit_do_pause(regs) 
#define svm_crash_or_fault(v) 
#define svm_do_nested_pgfault(v, regs, exitinfo1, exitinfo2) 

#define __get_instruction_length(v, type) 0
#define __update_guest_eip(regs, len) 

#define nestedsvm_check_intercepts(v, regs, reason) NESTEDHVM_VMEXIT_CONTINUE
#define nestedsvm_vmexit_n2n1(v, regs) NESTEDHVM_VMEXIT_CONTINUE
#define nestedsvm_vmexit_defer(v, reason, info1, info2) 
#define vcpu_nestedhvm(v) ((struct nestedvcpu){0})

#define trace_will_trace_event(event) 0