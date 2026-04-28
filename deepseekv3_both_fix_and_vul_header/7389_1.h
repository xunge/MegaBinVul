#include <stdint.h>
#include <stdbool.h>

#define __init

enum ind_thunk {
    THUNK_DEFAULT,
    THUNK_NONE,
    THUNK_RETPOLINE,
    THUNK_JMP,
    THUNK_LFENCE
};

#define X86_FEATURE_IBRSB         (1 << 0)
#define X86_FEATURE_IBRS          (1 << 1)
#define X86_FEATURE_SSBD          (1 << 2)
#define X86_FEATURE_AMD_SSBD      (1 << 3)
#define X86_FEATURE_XEN_SMEP      (1 << 4)
#define X86_FEATURE_IBPB          (1 << 5)
#define X86_FEATURE_L1D_FLUSH     (1 << 6)
#define X86_FEATURE_MD_CLEAR      (1 << 7)
#define X86_FEATURE_IND_THUNK_LFENCE (1 << 8)
#define X86_FEATURE_IND_THUNK_JMP    (1 << 9)
#define X86_FEATURE_SC_MSR_PV     (1 << 10)
#define X86_FEATURE_SC_MSR_HVM    (1 << 11)
#define X86_FEATURE_SC_MSR_IDLE   (1 << 12)
#define X86_FEATURE_SC_RSB_PV     (1 << 13)
#define X86_FEATURE_SC_RSB_HVM    (1 << 14)
#define X86_FEATURE_SC_NO_BRANCH_HARDEN (1 << 15)
#define X86_FEATURE_SC_VERW_PV    (1 << 16)
#define X86_FEATURE_SC_VERW_IDLE  (1 << 17)
#define X86_FEATURE_SC_VERW_HVM   (1 << 18)

#define MSR_ARCH_CAPABILITIES     0x10a
#define MSR_SPEC_CTRL             0x48
#define MSR_TSX_CTRL              0x122

#define X86_CR4_CET               (1 << 23)

#define ARCH_CAPS_SKIP_L1DFL      (1 << 0)
#define ARCH_CAPS_MDS_NO          (1 << 1)
#define ARCH_CAPS_TAA_NO          (1 << 2)
#define ARCH_CAPS_TSX_CTRL        (1 << 3)

#define SCF_ist_wrmsr             (1 << 0)
#define SCF_ist_rsb               (1 << 1)
#define SCF_use_shadow            (1 << 2)

#define SPEC_CTRL_IBRS            (1 << 0)
#define SPEC_CTRL_STIBP           (1 << 1)
#define SPEC_CTRL_SSBD            (1 << 2)

#define MCU_OPT_CTRL_RNGDS_MITG_DIS (1 << 0)

#define SVM_FEATURE_SPEC_CTRL     (1 << 0)

#define XENLOG_WARNING            "Warning: "

#define IS_ENABLED(x)             (1)
#define BUILD_BUG_ON(x)           ((void)0)
#define RO_MPT_VIRT_START         0
#define PML4_ADDR(x)              (0)

struct cpu_info {
    unsigned int shadow_spec_ctrl;
    unsigned int spec_ctrl_flags;
    unsigned int last_spec_ctrl;
};

struct boot_cpu_data {
    unsigned int extended_cpuid_level;
};

extern bool cpu_has_arch_caps;
extern bool cpu_has_bug_l1tf;
extern bool cpu_has_bug_mds;
extern bool cpu_has_bug_msbds_only;
extern bool cpu_has_bug_taa;
extern bool cpu_has_hypervisor;
extern bool cpu_has_hle;
extern bool cpu_has_rtm;
extern bool cpu_has_srbds_ctrl;
extern bool cpu_has_svm_spec_ctrl;
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
extern int opt_pv32;
extern unsigned int default_xen_spec_ctrl;
extern unsigned int default_spec_ctrl_flags;
extern bool bsp_delay_spec_ctrl;
extern struct boot_cpu_data boot_cpu_data;

void rdmsrl(unsigned int msr, uint64_t *val);
void wrmsrl(unsigned int msr, uint64_t val);
unsigned long read_cr4(void);
bool boot_cpu_has(unsigned int feature);
bool check_smt_enabled(void);
bool retpoline_safe(uint64_t caps);
bool rsb_is_full_width(void);
bool should_use_eager_fpu(void);
void setup_force_cpu_cap(unsigned int feature);
void init_shadow_spec_ctrl_state(void);
void xpti_init_default(uint64_t caps);
void l1tf_calculations(uint64_t caps);
void mds_calculations(uint64_t caps);
void tsx_init(void);
void set_in_mcu_opt_ctrl(unsigned int mask, unsigned int val);
void print_details(enum ind_thunk thunk, uint64_t caps);
void warning_add(const char *msg);
unsigned int cpuid_edx(unsigned int op);
struct cpu_info *get_cpu_info(void);
void printk(const char *fmt, ...);
void barrier(void);