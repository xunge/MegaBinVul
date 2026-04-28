#include <stdint.h>

#define INTERCEPT_CR0_READ 0
#define INTERCEPT_CR3_READ 1
#define INTERCEPT_CR4_READ 2
#define INTERCEPT_CR0_WRITE 3
#define INTERCEPT_CR3_WRITE 4
#define INTERCEPT_CR4_WRITE 5
#define INTERCEPT_CR8_WRITE 6

#define PF_VECTOR 14
#define UD_VECTOR 6
#define MC_VECTOR 18
#define AC_VECTOR 17

#define INTERCEPT_INTR 0
#define INTERCEPT_NMI 1
#define INTERCEPT_SMI 2
#define INTERCEPT_SELECTIVE_CR0 3
#define INTERCEPT_RDPMC 4
#define INTERCEPT_CPUID 5
#define INTERCEPT_INVD 6
#define INTERCEPT_HLT 7
#define INTERCEPT_INVLPG 8
#define INTERCEPT_INVLPGA 9
#define INTERCEPT_IOIO_PROT 10
#define INTERCEPT_MSR_PROT 11
#define INTERCEPT_TASK_SWITCH 12
#define INTERCEPT_SHUTDOWN 13
#define INTERCEPT_VMRUN 14
#define INTERCEPT_VMMCALL 15
#define INTERCEPT_VMLOAD 16
#define INTERCEPT_VMSAVE 17
#define INTERCEPT_STGI 18
#define INTERCEPT_CLGI 19
#define INTERCEPT_SKINIT 20
#define INTERCEPT_WBINVD 21
#define INTERCEPT_MONITOR 22
#define INTERCEPT_MWAIT 23
#define INTERCEPT_XSETBV 24
#define INTERCEPT_PAUSE 25

#define SVM_SELECTOR_READ_MASK (1 << 2)
#define SVM_SELECTOR_P_MASK (1 << 7)
#define SVM_SELECTOR_S_MASK (1 << 4)
#define SVM_SELECTOR_CODE_MASK (1 << 3)

#define V_INTR_MASKING_MASK (1 << 24)

#define SEG_TYPE_LDT 2
#define SEG_TYPE_BUSY_TSS16 3

#define X86_CR0_NW (1 << 29)
#define X86_CR0_CD (1 << 30)
#define X86_CR0_ET (1 << 4)
#define X86_CR4_PAE (1 << 5)

#define X86_FEATURE_PAUSEFILTER (1 << 10)

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
        uint32_t base;
        uint32_t limit;
        uint32_t attrib;
    } cs, es, ss, ds, fs, gs;
    struct {
        uint16_t limit;
        uint32_t base;
    } gdtr, idtr;
    struct {
        uint16_t selector;
        uint32_t base;
        uint32_t limit;
        uint32_t attrib;
    } ldtr, tr;
    uint64_t cr3;
    uint64_t cr4;
    uint64_t g_pat;
    uint64_t dr6;
    uint64_t rip;
};

struct vmcb {
    struct vmcb_control_area control;
    struct vmcb_save_area save;
};

struct vcpu_svm {
    struct {
        int fpu_active;
        struct {
            uint32_t hflags;
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

static inline uint64_t __pa(void *addr) { return (uint64_t)addr; }

static void set_cr_intercept(struct vcpu_svm *svm, int intercept) {}
static void set_dr_intercepts(struct vcpu_svm *svm) {}
static void set_exception_intercept(struct vcpu_svm *svm, int vector) {}
static void set_intercept(struct vcpu_svm *svm, int intercept) {}
static void clr_intercept(struct vcpu_svm *svm, int intercept) {}
static void clr_exception_intercept(struct vcpu_svm *svm, int vector) {}
static void clr_cr_intercept(struct vcpu_svm *svm, int intercept) {}
static void init_seg(void *seg) {}
static void init_sys_seg(void *seg, int type) {}
static void svm_set_efer(void *vcpu, uint64_t efer) {}
static void kvm_set_rflags(void *vcpu, uint64_t rflags) {}
static void svm_set_cr0(void *vcpu, uint64_t cr0) {}
static void kvm_mmu_reset_context(void *vcpu) {}
static void mark_all_dirty(struct vmcb *vmcb) {}
static void enable_gif(struct vcpu_svm *svm) {}

static inline int boot_cpu_has(int feature) { return 0; }