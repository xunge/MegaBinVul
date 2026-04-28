#include <stdint.h>

#define INTERCEPT_CR0_READ 0
#define INTERCEPT_CR3_READ 0
#define INTERCEPT_CR4_READ 0
#define INTERCEPT_CR0_WRITE 0
#define INTERCEPT_CR3_WRITE 0
#define INTERCEPT_CR4_WRITE 0
#define INTERCEPT_CR8_WRITE 0
#define PF_VECTOR 0
#define UD_VECTOR 0
#define MC_VECTOR 0
#define AC_VECTOR 0
#define DB_VECTOR 0
#define INTERCEPT_INTR 0
#define INTERCEPT_NMI 0
#define INTERCEPT_SMI 0
#define INTERCEPT_SELECTIVE_CR0 0
#define INTERCEPT_RDPMC 0
#define INTERCEPT_CPUID 0
#define INTERCEPT_INVD 0
#define INTERCEPT_HLT 0
#define INTERCEPT_INVLPG 0
#define INTERCEPT_INVLPGA 0
#define INTERCEPT_IOIO_PROT 0
#define INTERCEPT_MSR_PROT 0
#define INTERCEPT_TASK_SWITCH 0
#define INTERCEPT_SHUTDOWN 0
#define INTERCEPT_VMRUN 0
#define INTERCEPT_VMMCALL 0
#define INTERCEPT_VMLOAD 0
#define INTERCEPT_VMSAVE 0
#define INTERCEPT_STGI 0
#define INTERCEPT_CLGI 0
#define INTERCEPT_SKINIT 0
#define INTERCEPT_WBINVD 0
#define INTERCEPT_MONITOR 0
#define INTERCEPT_MWAIT 0
#define INTERCEPT_XSETBV 0
#define INTERCEPT_PAUSE 0
#define V_INTR_MASKING_MASK 0
#define SVM_SELECTOR_READ_MASK 0
#define SVM_SELECTOR_P_MASK 0
#define SVM_SELECTOR_S_MASK 0
#define SVM_SELECTOR_CODE_MASK 0
#define SEG_TYPE_LDT 0
#define SEG_TYPE_BUSY_TSS16 0
#define X86_CR0_NW 0
#define X86_CR0_CD 0
#define X86_CR0_ET 0
#define X86_CR4_PAE 0
#define X86_FEATURE_PAUSEFILTER 0
#define VCPU_REGS_RIP 0

struct vmcb_control_area {
    uint64_t iopm_base_pa;
    uint64_t msrpm_base_pa;
    uint32_t int_ctl;
    uint32_t nested_ctl;
    uint32_t pause_filter_count;
};

struct vmcb_save_area {
    struct {
        uint16_t selector;
        uint64_t base;
        uint32_t attrib;
        uint32_t limit;
    } cs, es, ss, ds, fs, gs;
    struct {
        uint32_t limit;
    } gdtr, idtr;
    struct {
        uint16_t selector;
        uint64_t base;
        uint32_t limit;
        uint32_t attrib;
    } ldtr, tr;
    uint64_t dr6;
    uint64_t rip;
    uint64_t cr0;
    uint64_t cr3;
    uint64_t cr4;
    uint64_t g_pat;
};

struct vmcb {
    struct vmcb_control_area control;
    struct vmcb_save_area save;
};

struct vcpu_svm {
    struct {
        int fpu_active;
        struct {
            int hflags;
            uint64_t pat;
            uint64_t regs[16];
        } arch;
    } vcpu;
    struct vmcb *vmcb;
    uint64_t *msrpm;
    uint32_t asid_generation;
    struct {
        uint64_t vmcb;
    } nested;
};

extern int npt_enabled;
extern uint64_t iopm_base;

void set_cr_intercept(struct vcpu_svm *svm, int intercept);
void set_dr_intercepts(struct vcpu_svm *svm);
void set_exception_intercept(struct vcpu_svm *svm, int vector);
void set_intercept(struct vcpu_svm *svm, int intercept);
void init_seg(void *seg);
void init_sys_seg(void *seg, int type);
void svm_set_efer(void *vcpu, uint64_t efer);
void kvm_set_rflags(void *vcpu, uint64_t rflags);
void svm_set_cr0(void *vcpu, uint64_t cr0);
void kvm_mmu_reset_context(void *vcpu);
void clr_intercept(struct vcpu_svm *svm, int intercept);
void clr_exception_intercept(struct vcpu_svm *svm, int vector);
void clr_cr_intercept(struct vcpu_svm *svm, int intercept);
void mark_all_dirty(struct vmcb *vmcb);
void enable_gif(struct vcpu_svm *svm);
int boot_cpu_has(int feature);
uint64_t __pa(void *addr);