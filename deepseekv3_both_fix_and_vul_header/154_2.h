#include <stddef.h>

struct timer_list {
    // Minimal stub for timer_list
    void *data;
};

struct completion {
    // Minimal stub for completion
    int done;
};

struct sas_task;
struct sas_task_slow {
    struct sas_task *task;
    struct timer_list timer;
    struct completion completion;
};

struct sas_task {
    unsigned long task_state_lock;
    unsigned long task_state_flags;
    struct sas_task_slow *slow_task;
};

#define SAS_TASK_STATE_DONE    0x1
#define SAS_TASK_STATE_ABORTED 0x2

#define spin_lock_irqsave(lock, flags) ((void)(flags))
#define spin_unlock_irqrestore(lock, flags) ((void)(flags))
#define complete(comp) ((void)0)
#define from_timer(ptr, tptr, member) ((ptr) = (typeof(ptr))((char *)(tptr) - offsetof(typeof(*ptr), member)))