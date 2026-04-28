#include <stdbool.h>
#include <stddef.h>

struct rq {
    struct {
        struct cfs_rq *leaf_cfs_rq_list;
    } cfs;
    struct task_struct *curr;
};

struct cfs_rq {
    struct task_group *tg;
    struct cfs_rq *next;
};

struct task_group {
    struct sched_entity **se;
};

struct sched_entity;

struct sched_class;

struct rq_flags {
    unsigned long flags;
};

struct task_struct {
    const struct sched_class *sched_class;
};

extern struct rq *cpu_rq(int cpu);
extern void rq_lock_irqsave(struct rq *rq, struct rq_flags *rf);
extern void rq_unlock_irqrestore(struct rq *rq, struct rq_flags *rf);
extern void update_rq_clock(struct rq *rq);
extern bool throttled_hierarchy(struct cfs_rq *cfs_rq);
extern bool update_cfs_rq_load_avg(unsigned long long now, struct cfs_rq *cfs_rq);
extern void update_tg_load_avg(struct cfs_rq *cfs_rq, int force);
extern bool skip_blocked_update(struct sched_entity *se);
extern void update_load_avg(struct cfs_rq *cfs_rq, struct sched_entity *se, int update_flags);
extern bool cfs_rq_has_blocked(struct cfs_rq *cfs_rq);
extern void update_rt_rq_load_avg(unsigned long long now, struct rq *rq, int update);
extern void update_dl_rq_load_avg(unsigned long long now, struct rq *rq, int update);
extern void update_irq_load_avg(struct rq *rq, unsigned long long running);
extern bool others_have_blocked(struct rq *rq);
extern bool cfs_rq_is_decayed(struct cfs_rq *cfs_rq);
extern void list_del_leaf_cfs_rq(struct cfs_rq *cfs_rq);
extern unsigned long long cfs_rq_clock_task(struct cfs_rq *cfs_rq);
extern unsigned long long rq_clock_task(struct rq *rq);
extern struct cfs_rq *cfs_rq_of(struct sched_entity *se);

#define for_each_leaf_cfs_rq(rq, cfs_rq) \
    for (cfs_rq = (rq)->cfs.leaf_cfs_rq_list; cfs_rq; cfs_rq = cfs_rq->next)

#define for_each_leaf_cfs_rq_safe(rq, cfs_rq, pos) \
    for (cfs_rq = (rq)->cfs.leaf_cfs_rq_list, pos = cfs_rq ? cfs_rq->next : NULL; \
         cfs_rq; cfs_rq = pos, pos = pos ? pos->next : NULL)

extern const struct sched_class rt_sched_class;
extern const struct sched_class dl_sched_class;
extern unsigned long jiffies;