#include <stdbool.h>

#define __init
#define X86_BUG_SPECTRE_V2 0
#define X86_VENDOR_AMD 0
#define X86_FEATURE_LFENCE_RDTSC 0
#define X86_FEATURE_RETPOLINE_AMD 0
#define X86_FEATURE_RETPOLINE 0
#define X86_FEATURE_PTI 0
#define X86_FEATURE_SMEP 0
#define X86_FEATURE_RSB_CTXSW 0
#define X86_FEATURE_IBPB 0
#define X86_FEATURE_USE_IBPB 0
#define X86_FEATURE_IBRS 0
#define X86_FEATURE_USE_IBRS_FW 0
#define IS_ENABLED(x) false
#define CONFIG_RETPOLINE 0

enum spectre_v2_mitigation_cmd {
    SPECTRE_V2_CMD_NONE,
    SPECTRE_V2_CMD_AUTO,
    SPECTRE_V2_CMD_FORCE,
    SPECTRE_V2_CMD_RETPOLINE_AMD,
    SPECTRE_V2_CMD_RETPOLINE_GENERIC,
    SPECTRE_V2_CMD_RETPOLINE
};

enum spectre_v2_mitigation {
    SPECTRE_V2_NONE,
    SPECTRE_V2_RETPOLINE_AMD,
    SPECTRE_V2_RETPOLINE_MINIMAL_AMD,
    SPECTRE_V2_RETPOLINE_GENERIC,
    SPECTRE_V2_RETPOLINE_MINIMAL
};

struct cpuinfo_x86 {
    int x86_vendor;
} boot_cpu_data;

bool boot_cpu_has_bug(int bug);
bool boot_cpu_has(int feature);
bool is_skylake_era(void);
bool retp_compiler(void);
void setup_force_cpu_cap(int feature);
int pr_err(const char *fmt, ...);
int pr_info(const char *fmt, ...);

extern enum spectre_v2_mitigation spectre_v2_enabled;
extern const char * const spectre_v2_strings[];