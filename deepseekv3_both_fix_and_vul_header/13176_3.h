#include <assert.h>
#include <stddef.h>

struct sched_rt_entity {
    struct rt_rq *rt_rq;
};

struct rt_rq {
    struct sched_rt_entity *rt_se;
};

struct rq {
    struct rt_rq rt;
};

struct task_struct {
    struct sched_rt_entity rt;
};

#define BUG_ON(cond) assert(!(cond))

static inline struct rt_rq *group_rt_rq(struct sched_rt_entity *rt_se) {
    return rt_se->rt_rq;
}

static inline struct task_struct *rt_task_of(struct sched_rt_entity *rt_se) {
    return (struct task_struct*)((char*)rt_se - offsetof(struct task_struct, rt));
}

static struct sched_rt_entity *pick_next_rt_entity(struct rt_rq *rt_rq) {
    return rt_rq->rt_se;
}