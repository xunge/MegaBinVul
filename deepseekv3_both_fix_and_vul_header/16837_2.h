#include <stdbool.h>
#include <stdint.h>

#define __init
#define IS_ENABLED(x) false
#define BUILD_BUG_ON(x) 
#define barrier() __asm__ __volatile__("": : :"memory")

enum ind_thunk {
    THUNK_DEFAULT,
    THUNK_NONE,
    THUNK_RETPOLINE,
    THUNK_JMP,
    THUNK_LFENCE
};

#define X86_VENDOR_AMD    0
#define X86_VENDOR_HYGON  1

#define X86_FEATURE_IBRSB           (0*32+26)
#define X86_FEATURE_IBRS            (0*32+14)
#define X86_FEATURE_STIBP           (0*32+27)
#define X86_FEATURE_AMD_STIBP       (0*32+28)
#define X86_FEATURE_SSBD            (0*32+31)
#define X86_FEATURE_AMD_SSBD        (0*32+24)
#define X86_FEATURE_PSFD            (0*32+28)
#define X86_FEATURE_INTEL_PSFD      (0*32+29)
#define X86_FEATURE_L1D_FLUSH       (0*32+28)
#define X86_FEATURE_MD_CLEAR        (0*32+10)
#define X86_FEATURE_SC_MSR_PV       (0*32+ 0)
#define X86_FEATURE_SC_MSR_HVM      (0*32+ 1)
#define X86_FEATURE_SC_RSB_PV       (0*32+ 2)
#define X86_FEATURE_SC_RSB_HVM      (0*32+ 3)
#define X86_FEATURE_SC_RSB_IDLE     (0*32+ 4)
#define X86_FEATURE_SC_MSR_IDLE     (0*32+ 5)
#define X86_FEATURE_SC_VERW_IDLE    (0*32+ 6)
#define X86_FEATURE_SC_NO_BRANCH_HARDEN (0*32+ 7)
#define X86_FEATURE_IND_THUNK_LFENCE (0*32+ 8)
#define X86_FEATURE_IND_THUNK_JMP   (0*32+ 9)
#define X86_FEATURE_XEN_SMEP        (0*32+11)

#define X86_CR4_CET                 (1UL << 23)

#define MSR_SPEC_CTRL               0x00000048

#define SCF_ist_sc_msr              (1U << 0)
#define SCF_ist_rsb                 (1U << 1)
#define SCF_use_shadow              (1U << 2)

#define SPEC_CTRL_IBRS              (1U << 0)
#define SPEC_CTRL_STIBP             (1U << 1)
#define SPEC_CTRL_SSBD              (1U << 2)
#define SPEC_CTRL_PSFD              (1U << 3)

#define SVM_FEATURE_SPEC_CTRL       (1U << 0)

#define MCU_OPT_CTRL_RNGDS_MITG_DIS (1U << 0)

#define TAINT_CPU_OUT_OF_SPEC       (1U << 0)

#define XENLOG_WARNING              "XENLOG_WARNING"

struct cpu_info {
    unsigned int shadow_spec_ctrl;
    unsigned int spec_ctrl_flags;
    unsigned int last_spec_ctrl;
};

struct cpuinfo_x86 {
    unsigned int x86_vendor;
    unsigned int x86;
    unsigned int extended_cpuid_level;
};

extern struct cpuinfo_x86 boot_cpu_data;

extern bool check_smt_enabled(void);
extern bool boot_cpu_has(int feature);
extern bool cpu_has_bug_l1tf;
extern bool cpu_has_bug_mds;
extern bool cpu_has_bug_msbds_only;
extern bool cpu_has_bug_taa;
extern bool cpu_has_amd_ssbd;
extern bool cpu_has_virt_ssbd;
extern bool cpu_has_svm_spec_ctrl;
extern bool cpu_has_svm;
extern bool cpu_has_eibrs;
extern bool cpu_has_skip_l1dfl;
extern bool cpu_has_mds_no;
extern bool cpu_has_taa_no;
extern bool cpu_has_rtm;
extern bool cpu_has_hle;
extern bool cpu_has_tsx_ctrl;
extern bool cpu_has_srbds_ctrl;
extern bool cpu_has_fb_clear;
extern bool cpu_has_hypervisor;
extern bool rtm_disabled;
extern bool pv_shim;
extern bool opt_pv32;
extern bool opt_unpriv_mmio;
extern bool opt_smt;
extern bool opt_rsb_pv;
extern bool opt_rsb_hvm;
extern bool opt_md_clear_pv;
extern bool opt_md_clear_hvm;
extern bool opt_fb_clear_mmio;
extern bool opt_eager_fpu;
extern bool opt_branch_harden;
extern bool opt_msr_sc_pv;
extern bool opt_msr_sc_hvm;
extern bool opt_l1d_flush;
extern bool opt_srb_lock;
extern bool opt_psfd;
extern bool opt_ssbd;
extern bool opt_stibp;
extern int opt_ibrs;
extern int opt_thunk;
extern int opt_tsx;
extern int opt_pv_l1tf_hwdom;
extern int opt_pv_l1tf_domu;
extern unsigned int default_xen_spec_ctrl;
extern unsigned int default_spec_ctrl_flags;
extern bool bsp_delay_spec_ctrl;
extern bool amd_virt_spec_ctrl;
extern bool amd_legacy_ssbd;

extern uint64_t read_cr4(void);
extern void wrmsrl(uint32_t msr, uint64_t val);
extern void printk(const char *fmt, ...);
extern void add_taint(unsigned int taint);
extern void setup_force_cpu_cap(int feature);
extern void warning_add(const char *msg);
extern bool retpoline_calculations(void);
extern bool rsb_is_full_width(void);
extern bool should_use_eager_fpu(void);
extern void init_shadow_spec_ctrl_state(void);
extern void xpti_init_default(void);
extern void l1tf_calculations(void);
extern void mds_calculations(void);
extern void srso_calculations(bool hw_smt_enabled);
extern void ibpb_calculations(void);
extern void gds_calculations(void);
extern void print_details(enum ind_thunk thunk);
extern bool amd_setup_legacy_ssbd(void);
extern void tsx_init(void);
extern void set_in_mcu_opt_ctrl(uint32_t mask, uint32_t val);
extern unsigned int cpuid_edx(unsigned int op);
extern struct cpu_info *get_cpu_info(void);