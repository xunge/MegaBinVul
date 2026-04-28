#include <stdbool.h>

enum spectre_v2_mitigation_cmd {
    SPECTRE_V2_CMD_NONE,
    SPECTRE_V2_CMD_AUTO,
    SPECTRE_V2_CMD_FORCE
};

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
    SPECTRE_V2_USER_CMD_PRCTL,
    SPECTRE_V2_USER_CMD_PRCTL_IBPB,
    SPECTRE_V2_USER_CMD_AUTO,
    SPECTRE_V2_USER_CMD_SECCOMP,
    SPECTRE_V2_USER_CMD_SECCOMP_IBPB
};

enum spectre_v2_enabled {
    SPECTRE_V2_IBRS_ENHANCED
};

#define CONFIG_SMP 1
#define CONFIG_SECCOMP 1

#define IS_ENABLED(x) (x)
#define boot_cpu_has(x) false
#define setup_force_cpu_cap(x)
#define static_branch_enable(x)
#define static_key_enabled(x) false
#define pr_info(fmt, ...)

extern enum spectre_v2_user_cmd spectre_v2_parse_user_cmdline(enum spectre_v2_mitigation_cmd v2_cmd);
extern const char *spectre_v2_user_strings[];
extern struct static_key switch_mm_always_ibpb;
extern struct static_key switch_mm_cond_ibpb;
extern enum spectre_v2_user_mitigation spectre_v2_user_ibpb;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;
extern enum spectre_v2_user_mitigation spectre_v2_user;
extern enum spectre_v2_enabled spectre_v2_enabled;
extern int cpu_smt_control;
#define CPU_SMT_FORCE_DISABLED 0
#define CPU_SMT_NOT_SUPPORTED 1

#define X86_FEATURE_IBPB 0
#define X86_FEATURE_STIBP 0
#define X86_FEATURE_USE_IBPB 0
#define X86_FEATURE_AMD_STIBP_ALWAYS_ON 0

struct static_key {
    bool enabled;
};

#define __init