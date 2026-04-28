#include <sys/resource.h>

#define RLIM_NLIMITS RLIMIT_NLIMITS
#define EINVAL 22
#define EPERM 1
#define CAP_SYS_RESOURCE 24
#define RLIMIT_NOFILE 7
#define RLIMIT_CPU 0
#define RLIM_INFINITY (~0UL)

struct task_struct {
    struct signal_struct *signal;
    struct task_struct *group_leader;
};

struct signal_struct {
    struct rlimit rlim[RLIM_NLIMITS];
};

extern int sysctl_nr_open;
extern int capable(int cap);
extern int security_task_setrlimit(struct task_struct *tsk, unsigned int resource, struct rlimit *new_rlim);
extern void task_lock(struct task_struct *tsk);
extern void task_unlock(struct task_struct *tsk);
extern void update_rlimit_cpu(struct task_struct *tsk, unsigned long rlim_cur);

#define IS_ENABLED(x) 1