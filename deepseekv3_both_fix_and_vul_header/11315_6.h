#include <signal.h>
#include <stddef.h>
#include <sys/types.h>

struct pid;
struct task_struct {
    struct task_struct *group_leader;
    pid_t pid;
};

extern struct task_struct *current;
extern struct task_struct *find_task_by_vpid(pid_t nr);
extern int same_thread_group(struct task_struct *p1, struct task_struct *p2);
extern struct pid *task_pid(struct task_struct *task);

#define sigev_notify_thread_id _sigev_un._tid