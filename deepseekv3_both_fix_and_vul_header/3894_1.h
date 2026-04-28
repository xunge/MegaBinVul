#include <stdbool.h>

enum spectre_v2_user_mitigation {
    SPECTRE_V2_USER_NONE,
    SPECTRE_V2_USER_STRICT,
    SPECTRE_V2_USER_STRICT_PREFERRED,
    SPECTRE_V2_USER_PRCTL,
    SPECTRE_V2_USER_SECCOMP
};

enum mds_mitigations {
    MDS_MITIGATION_OFF,
    MDS_MITIGATION_FULL,
    MDS_MITIGATION_VMWERV
};

enum taa_mitigations {
    TAA_MITIGATION_OFF,
    TAA_MITIGATION_VERW,
    TAA_MITIGATION_UCODE_NEEDED,
    TAA_MITIGATION_TSX_DISABLED
};

struct mutex {
    int dummy;
};

extern enum spectre_v2_user_mitigation spectre_v2_user;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;
extern enum mds_mitigations mds_mitigation;
extern enum taa_mitigations taa_mitigation;
extern struct mutex spec_ctrl_mutex;

#define X86_BUG_MSBDS_ONLY 0
#define MDS_MSG_SMT ""
#define TAA_MSG_SMT ""

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void update_stibp_strict(void);
void update_indir_branch_cond(void);
void update_mds_branch_idle(void);
bool sched_smt_active(void);
bool boot_cpu_has(int bug);
void pr_warn_once(const char *msg);