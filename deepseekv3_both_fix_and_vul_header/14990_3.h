#include <stddef.h>
#include <stdint.h>

#define RLIM_NLIMITS 16
#define RLIMIT_NOFILE 7
#define RLIMIT_CPU 0
#define RLIM_INFINITY (~0UL)
#define NR_OPEN 1024
#define CAP_SYS_RESOURCE 24
#define EINVAL 22
#define EFAULT 14
#define EPERM 1
#define CPUCLOCK_PROF 0

#define asmlinkage
#define __user

struct rlimit {
    unsigned long rlim_cur;
    unsigned long rlim_max;
};

typedef unsigned long cputime_t;

struct task_struct {
    struct signal_struct *signal;
    struct sighand_struct *sighand;
    struct task_struct *group_leader;
};

struct signal_struct {
    struct rlimit rlim[RLIM_NLIMITS];
    cputime_t it_prof_expires;
};

struct sighand_struct {
    unsigned long siglock;
};

extern struct task_struct *current;
extern void task_lock(struct task_struct *);
extern void task_unlock(struct task_struct *);
extern int capable(int);
extern unsigned long copy_from_user(void *, const void *, unsigned long);
extern unsigned long cputime_to_secs(cputime_t);
extern cputime_t secs_to_cputime(unsigned long);
extern void set_process_cpu_timer(struct task_struct *, int, cputime_t *, void *);
extern int security_task_setrlimit(unsigned int, struct rlimit *);

extern void read_lock(void *);
extern void read_unlock(void *);
extern void spin_lock_irq(unsigned long *);
extern void spin_unlock_irq(unsigned long *);

extern void *tasklist_lock;