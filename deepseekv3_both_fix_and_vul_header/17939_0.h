#include <stddef.h>

struct rq {
    int skip_clock_update;
};

struct sched_class {
    void (*put_prev_task)(struct rq *rq, struct task_struct *prev);
};

struct sched_entity {
    int on_rq;
};

struct task_struct {
    struct sched_entity se;
    struct sched_class *sched_class;
};

void update_rq_clock(struct rq *rq);