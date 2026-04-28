#include <stdbool.h>
#include <stddef.h>

struct io_wqe {
    int lock;
};

struct io_worker {
    void *creds;
    void *restore_files;
    void *mm;
};

struct task_struct {
    void *files;
};

extern void revert_creds(void *creds);
extern void __acquire(int *lock);
extern void spin_unlock_irq(int *lock);
extern void task_lock(struct task_struct *task);
extern void task_unlock(struct task_struct *task);
extern void __set_current_state(int state);
extern void set_fs(unsigned long fs);
extern void unuse_mm(void *mm);
extern void mmput(void *mm);

extern struct task_struct *current;
#define TASK_RUNNING 0
#define KERNEL_DS 0