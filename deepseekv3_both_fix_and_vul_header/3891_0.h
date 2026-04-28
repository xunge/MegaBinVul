#include <linux/errno.h>

struct task_struct;

#define PR_SPEC_ENABLE 0
#define PR_SPEC_DISABLE 1
#define PR_SPEC_FORCE_DISABLE 2

#define SPECTRE_V2_USER_NONE 0
#define SPECTRE_V2_USER_STRICT 1
#define SPECTRE_V2_USER_STRICT_PREFERRED 2

extern int spectre_v2_user;
extern int spectre_v2_user_ibpb;
extern int spectre_v2_user_stibp;

void task_clear_spec_ib_disable(struct task_struct *task);
void task_set_spec_ib_disable(struct task_struct *task);
void task_set_spec_ib_force_disable(struct task_struct *task);
void task_update_spec_tif(struct task_struct *task);