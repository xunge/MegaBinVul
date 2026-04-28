#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define __init
#define PRIx64 "llx"
#define CONFIG_INDIRECT_THUNK 0
#define CONFIG_SHADOW_PAGING 0
#define CONFIG_HVM 0
#define CONFIG_PV 0

enum ind_thunk {
    THUNK_NONE,
    THUNK_RETPOLINE,
    THUNK_LFENCE,
    THUNK_JMP
};

#define MSR_ARCH_CAPABILITIES 0x10a
#define ARCH_CAPS_RDCL_NO (1 << 0)
#define ARCH_CAPS_EIBRS (1 << 1)
#define ARCH_CAPS_RSBA (1 << 2)
#define ARCH_CAPS_RRSBA (1 << 3)
#define ARCH_CAPS_SKIP_L1DFL (1 << 4)
#define ARCH_CAPS_SSB_NO (1 << 5)
#define ARCH_CAPS_MDS_NO (1 << 6)
#define ARCH_CAPS_TAA_NO (1 << 7)
#define ARCH_CAPS_SBDR_SSDP_NO (1 << 8)
#define ARCH_CAPS_FBSDP_NO (1 << 9)
#define ARCH_CAPS_PSDP_NO (1 << 10)
#define ARCH_CAPS_FB_CLEAR (1 << 11)
#define ARCH_CAPS_PBRSB_NO (1 << 12)
#define ARCH_CAPS_GDS_NO (1 << 13)
#define ARCH_CAPS_TSX_CTRL (1 << 14)
#define ARCH_CAPS_FB_CLEAR_CTRL (1 << 15)
#define ARCH_CAPS_GDS_CTRL (1 << 16)

#define X86_FEATURE_SSB_NO (1 << 0)
#define X86_FEATURE_IBRS_ALWAYS (1 << 1)
#define X86_FEATURE_STIBP_ALWAYS (1 << 2)
#define X86_FEATURE_IBRS_FAST (1 << 3)
#define X86_FEATURE_IBRS_SAME_MODE (1 << 4)
#define X86_FEATURE_BTC_NO (1 << 5)
#define X86_FEATURE_IBPB_RET (1 << 6)
#define X86_FEATURE_IBPB_BRTYPE (1 << 7)
#define X86_FEATURE_SRSO_NO (1 << 8)
#define X86_FEATURE_IBPB (1 << 9)
#define X86_FEATURE_IBRSB (1 << 10)
#define X86_FEATURE_IBRS (1 << 11)
#define X86_FEATURE_AMD_STIBP (1 << 12)
#define X86_FEATURE_STIBP (1 << 13)
#define X86_FEATURE_AMD_SSBD (1 << 14)
#define X86_FEATURE_SSBD (1 << 15)
#define X86_FEATURE_INTEL_PSFD (1 << 16)
#define X86_FEATURE_PSFD (1 << 17)
#define X86_FEATURE_L1D_FLUSH (1 << 18)
#define X86_FEATURE_MD_CLEAR (1 << 19)
#define X86_FEATURE_SRBDS_CTRL (1 << 20)
#define X86_FEATURE_VIRT_SSBD (1 << 21)
#define X86_FEATURE_SBPB (1 << 22)
#define X86_FEATURE_SC_MSR_HVM (1 << 23)
#define X86_FEATURE_SC_RSB_HVM (1 << 24)
#define X86_FEATURE_IBPB_ENTRY_HVM (1 << 25)
#define X86_FEATURE_SC_MSR_PV (1 << 26)
#define X86_FEATURE_SC_RSB_PV (1 << 27)
#define X86_FEATURE_IBPB_ENTRY_PV (1 << 28)

#define SPEC_CTRL_IBRS (1 << 0)
#define SPEC_CTRL_STIBP (1 << 1)
#define SPEC_CTRL_SSBD (1 << 2)
#define SPEC_CTRL_PSFD (1 << 3)

struct cpuinfo_x86 {
    unsigned int cpuid_level;
    unsigned int extended_cpuid_level;
};

extern struct cpuinfo_x86 boot_cpu_data;
extern bool cpu_has_arch_caps;
extern uint64_t default_xen_spec_ctrl;
extern bool opt_ibpb_ctxt_switch;
extern bool opt_l1d_flush;
extern bool opt_md_clear_pv;
extern bool opt_md_clear_hvm;
extern bool opt_fb_clear_mmio;
extern bool opt_div_scrub;
extern bool opt_branch_harden;
extern bool opt_pv_l1tf_hwdom;
extern bool opt_pv_l1tf_domu;
extern bool opt_xpti_hwdom;
extern bool opt_xpti_domu;
extern bool opt_eager_fpu;
extern bool opt_srb_lock;
extern uint8_t opt_tsx;
extern bool cpu_has_bug_l1tf;
extern unsigned int l1d_maxphysaddr;
extern unsigned int paddr_bits;
extern uint64_t l1tf_safe_maddr;
extern bool amd_virt_spec_ctrl;
extern bool cpu_has_srbds_ctrl;

static inline unsigned int cpufeat_mask(unsigned int feature)
{
    return feature;
}

static inline bool boot_cpu_has(unsigned int feature)
{
    return false;
}

static inline void cpuid_count(unsigned int op, unsigned int count,
                              unsigned int *eax, unsigned int *ebx,
                              unsigned int *ecx, unsigned int *edx)
{
    *eax = *ebx = *ecx = *edx = 0;
}

static inline void cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx,
                        unsigned int *ecx, unsigned int *edx)
{
    *eax = *ebx = *ecx = *edx = 0;
}

static inline void rdmsrl(unsigned int msr, uint64_t *val)
{
    *val = 0;
}

static inline bool xpti_pcid_enabled(void)
{
    return false;
}

static inline bool IS_ENABLED(int config)
{
    return false;
}

static inline int printk(const char *fmt, ...)
{
    return 0;
}