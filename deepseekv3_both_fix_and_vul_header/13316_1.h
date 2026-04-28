#include <linux/sched.h>
#include <linux/errno.h>

#define PR_SPEC_ENABLE 0
#define PR_SPEC_DISABLE 1
#define PR_SPEC_FORCE_DISABLE 2

#define SPECTRE_V2_USER_NONE 0

extern int spectre_v2_user_ibpb;
extern int spectre_v2_user_stibp;
extern struct task_struct *current;

struct task_struct;

int is_spec_ib_user_controlled(void);
int task_spec_ib_force_disable(struct task_struct *task);
void task_clear_spec_ib_disable(struct task_struct *task);
void task_update_spec_tif(struct task_struct *task);
void task_set_spec_ib_disable(struct task_struct *task);
void task_set_spec_ib_force_disable(struct task_struct *task);
void indirect_branch_prediction_barrier(void);