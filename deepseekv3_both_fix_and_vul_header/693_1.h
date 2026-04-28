#include <stddef.h>

struct thread_struct {
    int load_fp;
    void *fp_state;
};

struct task_struct {
    struct thread_struct thread;
};

extern struct task_struct *current;
extern int tm_active_with_fp(struct task_struct *tsk);
extern void load_fp_state(void *fp_state);