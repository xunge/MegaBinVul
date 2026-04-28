#include <unistd.h>
#include <sys/types.h>

struct mm_struct;

struct task_struct {
    struct {
        unsigned long mm_segment;
    } thread;
};

extern struct task_struct *current;
extern void switch_mm(struct mm_struct *prev, struct mm_struct *next, struct task_struct *tsk);
extern void set_fs(unsigned long fs);