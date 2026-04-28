#include <linux/prctl.h>
#include <linux/errno.h>

struct task_struct;
enum spectre_v2_user_mitigation {
    SPECTRE_V2_USER_NONE,
    SPECTRE_V2_USER_STRICT,
    SPECTRE_V2_USER_STRICT_PREFERRED
};

extern enum spectre_v2_user_mitigation spectre_v2_user_ibpb;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;

void task_clear_spec_ib_disable(struct task_struct *task);
void task_set_spec_ib_disable(struct task_struct *task);
void task_set_spec_ib_force_disable(struct task_struct *task);
void task_update_spec_tif(struct task_struct *task);