#include <stdbool.h>

enum spectre_v2_user_mitigation {
    SPECTRE_V2_USER_NONE,
    SPECTRE_V2_USER_STRICT,
    SPECTRE_V2_USER_PRCTL,
    SPECTRE_V2_USER_SECCOMP,
    SPECTRE_V2_USER_STRICT_PREFERRED
};

enum spectre_v2_user_cmd {
    SPECTRE_V2_USER_CMD_NONE,
    SPECTRE_V2_USER_CMD_FORCE,
    SPECTRE_V2_USER_CMD_AUTO,
    SPECTRE_V2_USER_CMD_PRCTL,
    SPECTRE_V2_USER_CMD_PRCTL_IBPB,
    SPECTRE_V2_USER_CMD_SECCOMP,
    SPECTRE_V2_USER_CMD_SECCOMP_IBPB
};

enum cpu_smt_ctrl {
    CPU_SMT_FORCE_DISABLED,
    CPU_SMT_NOT_SUPPORTED
};

enum retbleed_mitigation {
    RETBLEED_MITIGATION_UNRET,
    RETBLEED_MITIGATION_IBPB
};

#define __init
#define IS_ENABLED(x) (x)
#define CONFIG_SMP 1
#define CONFIG_SECCOMP 1
#define X86_FEATURE_IBPB 1
#define X86_FEATURE_STIBP 2
#define X86_FEATURE_USE_IBPB 3
#define X86_FEATURE_AMD_STIBP_ALWAYS_ON 4

extern enum cpu_smt_ctrl cpu_smt_control;
extern enum retbleed_mitigation retbleed_mitigation;
extern bool boot_cpu_has(int feature);
extern void setup_force_cpu_cap(int feature);
extern enum spectre_v2_user_cmd spectre_v2_parse_user_cmdline(void);
extern bool spectre_v2_in_ibrs_mode(int mode);
extern void static_branch_enable(bool *branch);
extern bool static_key_enabled(const bool *key);
extern int spectre_v2_enabled;
extern enum spectre_v2_user_mitigation spectre_v2_user_ibpb;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;
extern bool switch_mm_always_ibpb;
extern bool switch_mm_cond_ibpb;
extern const char *spectre_v2_user_strings[];
extern void pr_info(const char *fmt, ...);