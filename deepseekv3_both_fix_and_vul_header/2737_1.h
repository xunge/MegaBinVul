#include <stdbool.h>

#define ESRCH 3
#define PT_PTRACED 0x00000001
#define JOBCTL_LISTENING 0x00000002
#define __TASK_TRACED 0x00000010
#define TASK_TRACED 0x00000010

struct task_struct {
    long state;
    struct task_struct *parent;
    unsigned int ptrace;
    struct sighand_struct *sighand;
    unsigned long jobctl;
};

struct sighand_struct {
    int siglock;
};

extern struct {
    int lock;
} tasklist_lock;
extern struct task_struct *current;

#define read_lock(lock) do {} while (0)
#define read_unlock(lock) do {} while (0)
#define spin_lock_irq(lock) do {} while (0)
#define spin_unlock_irq(lock) do {} while (0)
#define WARN_ON(condition) do {} while (0)
#define WARN_ON_ONCE(condition) do {} while (0)

static inline bool task_is_stopped(struct task_struct *task) { return false; }
static inline bool task_is_traced(struct task_struct *task) { return false; }
static inline bool ptrace_freeze_traced(struct task_struct *task) { return false; }
static inline bool wait_task_inactive(struct task_struct *task, long state) { return false; }