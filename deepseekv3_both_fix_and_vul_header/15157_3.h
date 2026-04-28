#include <pthread.h>

struct mutex {
    pthread_mutex_t lock;
};

struct task_struct {
    struct mutex cred_guard_mutex;
    struct mm_struct *mm;
};

struct mm_struct;

extern struct task_struct *current;
#define PTRACE_MODE_READ 1

extern int mutex_lock_killable(struct mutex *);
extern void mutex_unlock(struct mutex *);
extern struct mm_struct *get_task_mm(struct task_struct *);
extern void mmput(struct mm_struct *);
extern int ptrace_may_access(struct task_struct *, int);