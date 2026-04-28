#include <stddef.h>
#include <stdint.h>

#define X86_BUG_SPECTRE_V2 0
#define PR_SPEC_NOT_AFFECTED 0
#define PR_SPEC_ENABLE 1
#define PR_SPEC_DISABLE 2
#define PR_SPEC_PRCTL 3
#define PR_SPEC_FORCE_DISABLE 4

#define SPECTRE_V2_USER_NONE 0
#define SPECTRE_V2_USER_STRICT 1
#define SPECTRE_V2_USER_STRICT_PREFERRED 2
#define SPECTRE_V2_USER_PRCTL 3
#define SPECTRE_V2_USER_SECCOMP 4

struct task_struct;
extern int boot_cpu_has_bug(int bug);
extern int spectre_v2_user_ibpb;
extern int spectre_v2_user_stibp;
extern int spectre_v2_user;
extern int task_spec_ib_force_disable(struct task_struct *task);
extern int task_spec_ib_disable(struct task_struct *task);