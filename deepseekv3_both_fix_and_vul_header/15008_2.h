#include <stddef.h>
#include <signal.h>

struct mm_struct {
    int core_waiters;
};

struct task_struct {
    struct mm_struct *mm;
    struct task_struct *parent;
    struct completion *vfork_done;
    int ptrace;
};

struct completion;

extern struct task_struct *current;
extern struct task_struct init_task;
extern struct rwlock tasklist_lock;
extern void complete(struct completion *);
extern void force_sig_specific(int, struct task_struct *);
extern void __ptrace_unlink(struct task_struct *);
extern struct task_struct *next_thread(struct task_struct *);

#define do_each_thread(g, t) \
    for (g = t = &init_task; (t = next_thread(t)) != &init_task; )
#define while_each_thread(g, t) \
    while ((t = next_thread(t)) != g)

#define unlikely(x) (x)
#define SIGKILL 9
#define read_lock(lock) 
#define read_unlock(lock) 
#define write_lock_irq(lock) 
#define write_unlock_irq(lock)