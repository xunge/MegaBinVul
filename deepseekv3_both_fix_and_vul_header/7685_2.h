#include <linux/capability.h>
#include <linux/ptrace.h>
#include <linux/seccomp.h>
#include <linux/sched.h>
#include <linux/errno.h>

struct task_struct {
    unsigned long ptrace;
    struct seccomp {
        int mode;
    } seccomp;
};

extern struct task_struct *current;
extern int capable(int cap);
extern int seccomp_mode(struct seccomp *s);

#define PT_OPT_FLAG_SHIFT 16
#define PT_SUSPEND_SECCOMP (1 << 31)
#define CONFIG_CHECKPOINT_RESTORE 1
#define CONFIG_SECCOMP 1
#define SECCOMP_MODE_DISABLED 0
#define EINVAL 22
#define EPERM 1
#define unlikely(x) __builtin_expect(!!(x), 0)
#define IS_ENABLED(x) (x)