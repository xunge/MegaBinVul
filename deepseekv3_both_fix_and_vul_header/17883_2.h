#include <pthread.h>
#include <errno.h>

struct mm_struct;
struct signal_struct {
    pthread_mutex_t cred_guard_mutex;
};

struct task_struct {
    struct signal_struct *signal;
    struct mm_struct *mm;
};

#define ERR_PTR(err) ((void *)(long)(err))
#define PTRACE_MODE_READ 0
#define EACCES 13

extern struct task_struct *current;
extern struct mm_struct *get_task_mm(struct task_struct *task);
extern void mmput(struct mm_struct *mm);
extern int ptrace_may_access(struct task_struct *task, int mode);
extern int mutex_lock_killable(pthread_mutex_t *mutex);
extern void mutex_unlock(pthread_mutex_t *mutex);