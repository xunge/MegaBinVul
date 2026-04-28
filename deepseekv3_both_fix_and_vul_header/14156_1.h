#include <linux/sched.h>
#include <linux/audit.h>
#include <stddef.h>

struct smk_audit_info {
    // dummy definition since actual structure is not provided
};
struct smack_known {
    // dummy definition since actual structure is not provided  
};

#define LSM_AUDIT_DATA_TASK 0

static inline void smk_ad_init(struct smk_audit_info *a, const char *f, int l) {}
static inline void smk_ad_setfield_u_tsk(struct smk_audit_info *a, struct task_struct *t) {}
static inline struct smack_known *smk_of_task_struct_subj(struct task_struct *t) { return NULL; }
static inline int smk_curacc(struct smack_known *sk, int a, struct smk_audit_info *ad) { return 0; }
static inline int smk_bu_task(struct task_struct *t, int a, int r) { return 0; }