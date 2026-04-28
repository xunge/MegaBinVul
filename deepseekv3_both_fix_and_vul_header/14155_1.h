#include <string.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12

struct task_struct;
struct smack_known {
    char *smk_known;
};

static inline struct smack_known *smk_of_task_struct_subj(struct task_struct *p) { return NULL; }
static inline char *kstrdup(const char *s, int gfp) { return strdup(s); }