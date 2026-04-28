#include <time.h>
#include <stdio.h>

struct task_struct {
    struct task_struct *group_leader;
};

typedef struct {
    int dummy;
} rwlock_t;

extern rwlock_t tasklist_lock;
extern unsigned long badness(struct task_struct *p, long uptime);
extern void do_posix_clock_monotonic_gettime(struct timespec *ts);
extern void read_lock(rwlock_t *lock);
extern void read_unlock(rwlock_t *lock);