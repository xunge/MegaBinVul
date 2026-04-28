#include <stddef.h>

struct task_struct;
struct rq;
struct sched_class;

struct task_struct {
    const struct sched_class *sched_class;
    struct {
        int on_rq;
    } se;
};

struct rq {
    struct task_struct *curr;
    int skip_clock_update;
};

struct sched_class {
    void (*check_preempt_curr)(struct rq *, struct task_struct *, int);
};

#define for_each_class(class) \
    for (class = NULL; class != NULL; class = NULL)

void resched_task(struct task_struct *);
int test_tsk_need_resched(struct task_struct *);