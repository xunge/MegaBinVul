#include <stddef.h>

extern unsigned long dac_mmap_min_addr;
extern unsigned long mmap_min_addr;

#define PF_SUPERPRIV 0x00000002
#define CAP_SYS_RAWIO 17
#define SECURITY_CAP_AUDIT 1

struct file;
struct cred;
struct task_struct {
    unsigned long flags;
};
extern struct task_struct *current;

int cap_capable(struct task_struct *tsk, const struct cred *cred, int cap, int audit);
const struct cred *current_cred(void);