#include <stdbool.h>
#include <stdint.h>

#define __init
#define MSR_ARCH_CAPABILITIES 0x10a
#define MSR_SPEC_CTRL 0x48
#define X86_FEATURE_IBRSB 0
#define X86_FEATURE_IBRS 0
#define X86_CR4_CET 0
#define XENLOG_WARNING ""
#define SPEC_CTRL_IBRS (1 << 0)
#define SPEC_CTRL_STIBP (1 << 1)
#define SPEC_CTRL_SSBD (1 << 2)
#define CONFIG_INDIRECT_THUNK 0
#define X86_FEATURE_IND_THUNK_LFENCE 0
#define X86_FEATURE_IND_THUNK_JMP 0
#define SCF_ist_wrmsr (1 << 0)
#define SCF_ist_rsb (1 << 1)
#define SCF_use_shadow (1 << 2)
#define X86_FEATURE_SC_MSR_PV 0
#define X86_FEATURE_SC_MSR_HVM 0
#define SVM_FEATURE_SPEC_CTRL 0
#define X86_FEATURE_SSBD 0
#define X86_FEATURE_AMD_SSBD 0
#define RO_MPT_VIRT_START 0
#define PML4_ADDR(x) 0
#define X86_FEATURE_XEN_SMEP 0
#define X86_FEATURE_SC_RSB_PV 0
#define X86_FEATURE_SC_RSB_HVM 0
#define X86_FEATURE_IBPB 0
#define X86_FEATURE_SC_MSR_IDLE 0
#define X86_FEATURE_L1D_FLUSH 0
#define ARCH_CAPS_SKIP_L1DFL (1 << 0)
#define X86_FEATURE_SC_NO_BRANCH_HARDEN 0
#define X86_FEATURE_MD_CLEAR 0
#define ARCH_CAPS_TSX_CTRL (1 << 1)
#define ARCH_CAPS_MDS_NO (1 << 2)
#define ARCH_CAPS_TAA_NO (1 << 3)
#define ARCH_CAPS_FB_CLEAR (1 << 4)
#define MCU_OPT_CTRL_RNGDS_MITG_DIS 0
#define X86_FEATURE_SC_VERW_IDLE 0

enum ind_thunk {
    THUNK_DEFAULT,
    THUNK_NONE,
    THUNK_RETPOLINE,
    THUNK_LFENCE,
    THUNK_JMP
};

struct cpu_info {
    unsigned int shadow_spec_ctrl;
    unsigned int spec_ctrl_flags;
    unsigned int last_spec_ctrl;
};

struct cpu_data {
    unsigned int extended_cpuid_level;
};

extern bool cpu_has_arch_caps;
extern bool cpu_has_bug_l1tf;
extern bool cpu_has_bug_mds;
extern bool cpu_has_bug_msbds_only;
extern bool cpu_has_hypervisor;
extern bool cpu_has_rtm;
extern bool cpu_has_hle;
extern bool cpu_has_srbds_ctrl;
extern bool pv_shim;
extern bool rtm_disabled;
extern int opt_ibrs;
extern int opt_thunk;
extern int opt_msr_sc_pv;
extern int opt_msr_sc_hvm;
extern int opt_ssbd;
extern int opt_rsb_pv;
extern int opt_rsb_hvm;
extern int opt_ibpb;
extern int opt_eager_fpu;
extern int opt_pv_l1tf_hwdom;
extern int opt_pv_l1tf_domu;
extern int opt_l1d_flush;
extern int opt_branch_harden;
extern int opt_smt;
extern int opt_md_clear_pv;
extern int opt_md_clear_hvm;
extern int opt_tsx;
extern int opt_srb_lock;
extern int opt_unpriv_mmio;
extern int opt_fb_clear_mmio;
extern int opt_pv32;
extern unsigned int default_xen_spec_ctrl;
extern unsigned int default_spec_ctrl_flags;
extern bool bsp_delay_spec_ctrl;
extern struct cpu_data boot_cpu_data;

#define IS_ENABLED(option) (option)

void rdmsrl(unsigned int msr, uint64_t *val);
bool check_smt_enabled(void);
bool boot_cpu_has(unsigned int feature);
unsigned long read_cr4(void);
void printk(const char *fmt, ...);
bool retpoline_safe(uint64_t caps);
void setup_force_cpu_cap(unsigned int feature);
unsigned int cpuid_edx(unsigned int op);
void BUILD_BUG_ON(int condition);
bool rsb_is_full_width(void);
bool should_use_eager_fpu(void);
void init_shadow_spec_ctrl_state(void);
void xpti_init_default(uint64_t caps);
void l1tf_calculations(uint64_t caps);
void mds_calculations(uint64_t caps);
void warning_add(const char *msg);
void tsx_init(void);
void set_in_mcu_opt_ctrl(unsigned int ctrl, unsigned int val);
void print_details(enum ind_thunk thunk, uint64_t caps);
struct cpu_info *get_cpu_info(void);
void barrier(void);
void wrmsrl(unsigned int msr, unsigned int val);