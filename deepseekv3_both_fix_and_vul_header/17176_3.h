#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>

#define __user
#define current (struct task_struct *)0
#define put_user(x, ptr) (*(ptr) = (x), 0)

enum pid_type {
    PIDTYPE_PID,
    PIDTYPE_PGID,
    PIDTYPE_SID,
    PIDTYPE_MAX
};

struct pid;
struct task_struct;
struct waitid_info;

struct wait_opts {
    enum pid_type wo_type;
    struct pid *wo_pid;
    int wo_flags;
    struct waitid_info *wo_info;
    int wo_stat;
    struct rusage *wo_rusage;
};

extern struct pid *find_get_pid(pid_t nr);
extern struct pid *get_task_pid(struct task_struct *task, enum pid_type type);
extern long do_wait(struct wait_opts *wo);
extern void put_pid(struct pid *pid);