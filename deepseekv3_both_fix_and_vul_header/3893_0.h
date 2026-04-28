#include <linux/prctl.h>

enum ssb_mitigation {
	SPEC_STORE_BYPASS_NONE,
	SPEC_STORE_BYPASS_SECCOMP
};

enum spectre_v2_user_mitigation {
	SPECTRE_V2_USER_NONE,
	SPECTRE_V2_USER_SECCOMP
};

extern enum ssb_mitigation ssb_mode;
extern enum spectre_v2_user_mitigation spectre_v2_user;
extern enum spectre_v2_user_mitigation spectre_v2_user_ibpb;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;

struct task_struct;

void ssb_prctl_set(struct task_struct *task, int option);
void ib_prctl_set(struct task_struct *task, int option);