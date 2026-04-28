#include <stdbool.h>

#define __init

enum ind_thunk {
    THUNK_DEFAULT,
    THUNK_RETPOLINE,
    THUNK_JMP,
    THUNK_LFENCE,
    THUNK_NONE
};

#define X86_FEATURE_IBRSB            (0*32+26)
#define X86_FEATURE_IBRS             (0*32+14)
#define X86_FEATURE_STIBP            (0*32+27)
#define X86_FEATURE_AMD_STIBP        (0*32+28)
#define X86_FEATURE_SSBD            (0*32+31)
#define X86_FEATURE_AMD_SSBD        (0*32+24)
#define X86_FEATURE_PSFD            (0*32+0)
#define X86_FEATURE_INTEL_PSFD      (0*32+0)
#define X86_FEATURE_XEN_SMEP        (0*32+7)
#define X86_FEATURE_SC_MSR_PV       (0*32+0)
#define X86_FEATURE_SC_MSR_HVM      (0*32+0)
#define X86_FEATURE_SC_RSB_PV       (0*32+0)
#define X86_FEATURE_SC_RSB_HVM      (0*32+0)
#define X86_FEATURE_SC_RSB_IDLE     (0*32+0)
#define X86_FEATURE_SC_MSR_IDLE     (0*32+0)
#define X86_FEATURE_SC_NO_BRANCH_HARDEN (0*32+0)
#define X86_FEATURE_SC_VERW_IDLE    (0*32+0)
#define X86_FEATURE_MD_CLEAR        (0*32+0)
#define X86_FEATURE_L1D_FLUSH       (0*32+0)
#define X86_FEATURE_FB_CLEAR        (0*32+0)
#define X86_FEATURE_IND_THUNK_LFENCE (0*32+0)
#define X86_FEATURE_IND_THUNK_JMP   (0*32+0)

#define X86_CR4_CET                 (1UL << 23)

#define MSR_SPEC_CTRL               0x00000048

#define SPEC_CTRL_IBRS              (1UL << 0)
#define SPEC_CTRL_STIBP             (1UL << 1)
#define SPEC_CTRL_SSBD              (1UL << 2)
#define SPEC_CTRL_PSFD              (1UL << 3)

#define SCF_ist_sc_msr              (1U << 0)
#define SCF_ist_rsb                 (1U << 1)
#define SCF_use_shadow              (1U << 2)

#define SVM_FEATURE_SPEC_CTRL       (1U << 0)

#define TAINT_CPU_OUT_OF_SPEC       (1U << 0)

#define XENLOG_WARNING              "XENLOG_WARNING"

#define CONFIG_INDIRECT_THUNK       1

#define MCU_OPT_CTRL_RNGDS_MITG_DIS (1U << 0)

#define X86_VENDOR_AMD              0
#define X86_VENDOR_HYGON            1

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
extern bool cpu_has_bug_taa;
extern bool cpu_has_bug_l1tf;
extern bool cpu_has_bug_mds;
extern bool cpu_has_bug_msbds_only;
extern bool cpu_has_amd_ssbd;
extern bool cpu_has_virt_ssbd;
extern bool cpu_has_svm_spec_ctrl;
extern bool cpu_has_svm;
extern bool cpu_has_eibrs;
extern bool cpu_has_skip_l1dfl;
extern bool cpu_has_mds_no;
extern bool cpu_has_taa_no;
extern bool cpu_has_rtm;
extern bool cpu_has_tsx_ctrl;
extern bool cpu_has_srbds_ctrl;
extern bool cpu_has_hle;
extern bool cpu_has_fb_clear;
extern bool cpu_has_hypervisor;
extern bool amd_legacy_ssbd;
extern bool amd_virt_spec_ctrl;
extern bool pv_shim;
extern bool opt_pv32;
extern bool opt_unpriv_mmio;
extern bool rtm_disabled;

extern int opt_ibrs;
extern int opt_thunk;
extern int opt_stibp;
extern int opt_ssbd;
extern int opt_psfd;
extern int opt_rsb_pv;
extern int opt_rsb_hvm;
extern int opt_eager_fpu;
extern int opt_smt;
extern int opt_pv_l1tf_hwdom;
extern int opt_pv_l1tf_domu;
extern int opt_l1d_flush;
extern int opt_branch_harden;
extern int opt_md_clear_pv;
extern int opt_md_clear_hvm;
extern int opt_fb_clear_mmio;
extern int opt_tsx;
extern int opt_srb_lock;
extern int opt_msr_sc_pv;
extern int opt_msr_sc_hvm;

extern unsigned int default_xen_spec_ctrl;
extern unsigned int default_spec_ctrl_flags;
extern bool bsp_delay_spec_ctrl;

extern unsigned long read_cr4(void);
extern void wrmsrl(unsigned int msr, unsigned long val);
extern void printk(const char *fmt, ...);
extern void add_taint(unsigned int taint);
extern bool retpoline_calculations(void);
extern bool rsb_is_full_width(void);
extern void setup_force_cpu_cap(int feature);
extern bool amd_setup_legacy_ssbd(void);
extern void init_shadow_spec_ctrl_state(void);
extern void xpti_init_default(void);
extern void l1tf_calculations(void);
extern void mds_calculations(void);
extern void srso_calculations(bool hw_smt_enabled);
extern void ibpb_calculations(void);
extern bool should_use_eager_fpu(void);
extern void tsx_init(void);
extern void set_in_mcu_opt_ctrl(unsigned int ctrl, unsigned int mask);
extern void print_details(enum ind_thunk thunk);
extern void warning_add(const char *msg);
extern unsigned int cpuid_edx(unsigned int op);
extern struct cpu_info *get_cpu_info(void);
extern void barrier(void);

#define IS_ENABLED(option) option
#define BUILD_BUG_ON(condition) ((void)0)
#define PML4_ADDR(i) ((unsigned long)(i) << 39)
#define RO_MPT_VIRT_START 0xffff800000000000UL