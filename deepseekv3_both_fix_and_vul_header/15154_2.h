#include <stddef.h>

struct mm_struct {
    void *mmap_sem;
    struct mm_struct *mm;
};

struct task_struct {
    struct mm_struct *mm;
};

extern struct task_struct *current;

#define PTRACE_MODE_READ 0

struct mm_struct *get_task_mm(struct task_struct *task);
int ptrace_may_access(struct task_struct *task, int mode);
void mmput(struct mm_struct *mm);
void down_read(void *sem);