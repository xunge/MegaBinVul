#include <stdlib.h>
#include <stddef.h>

#define BUG_ON(cond) ((cond) ? (void)0 : abort())
#define unlikely(x) (x)
#define CONFIG_SCHED_STACK_END_CHECK
#define SCHED_PROFILING 1
#define PREEMPT_DISABLED 0
#define sched_count 0

struct task_struct;
struct rq;

int task_stack_end_corrupted(struct task_struct *t);
int in_atomic_preempt_off(void);
void __schedule_bug(struct task_struct *prev);
void preempt_count_set(int val);
void rcu_sleep_check(void);
void profile_hit(int type, void *ip);
struct rq *this_rq(void);
void schedstat_inc(struct rq *rq, int count);