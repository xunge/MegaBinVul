#include <stddef.h>

struct task_struct {
    int ptrace;
    struct mm_struct *mm;
    struct task_struct *parent;
};

struct mm_struct {
    void *core_state;
};

#define likely(x) (x)
#define unlikely(x) (x)

extern struct task_struct *current;