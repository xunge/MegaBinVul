#include <stddef.h>

#define asmlinkage
#define __sched

struct rq {
    struct task_struct *curr;
    int nr_running;
    int skip_clock_update;
    int nr_switches;
    void *lock;
};

struct task_struct {
    long state;
    unsigned long nivcsw;
    unsigned long nvcsw;
    unsigned int flags;
    int preempt_count;
};

#define PF_WQ_WORKER 0
#define TASK_RUNNING 0
#define PREEMPT_ACTIVE 0
#define DEQUEUE_SLEEP 0

#define smp_processor_id() 0
#define cpu_rq(cpu) ((struct rq *)0)
#define preempt_disable()
#define preempt_enable_no_resched()
#define preempt_count() 0
#define need_resched() 0
#define raw_spin_lock_irq(lock)
#define raw_spin_unlock_irq(lock)
#define unlikely(x) x
#define likely(x) x
#define WARN_ON_ONCE(x)
#define sched_feat(x) 0

void rcu_note_context_switch(int cpu);
void release_kernel_lock(struct task_struct *task);
void schedule_debug(struct task_struct *task);
void hrtick_clear(struct rq *rq);
int signal_pending_state(long state, struct task_struct *task);
struct task_struct *wq_worker_sleeping(struct task_struct *task, int cpu);
void try_to_wake_up_local(struct task_struct *task);
void deactivate_task(struct rq *rq, struct task_struct *task, int flags);
void pre_schedule(struct rq *rq, struct task_struct *task);
void idle_balance(int cpu, struct rq *rq);
void put_prev_task(struct rq *rq, struct task_struct *task);
struct task_struct *pick_next_task(struct rq *rq);
void clear_tsk_need_resched(struct task_struct *task);
void sched_info_switch(struct task_struct *prev, struct task_struct *next);
void perf_event_task_sched_out(struct task_struct *prev, struct task_struct *next);
void context_switch(struct rq *rq, struct task_struct *prev, struct task_struct *next);
void post_schedule(struct rq *rq);
int reacquire_kernel_lock(struct task_struct *task);
int test_tsk_need_resched(struct task_struct *task);