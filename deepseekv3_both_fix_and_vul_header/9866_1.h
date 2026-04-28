#include <stddef.h>

struct linux_binprm {
    struct mm_struct *mm;
    void *file;
    unsigned long per_clear;
};

struct task_struct {
    unsigned long flags;
    unsigned long personality;
};

struct mm_struct;

extern struct task_struct *current;
extern int de_thread(struct task_struct *);
extern void set_mm_exe_file(struct mm_struct *, void *);
extern int exec_mmap(struct mm_struct *);
extern void flush_thread(void);

#define PF_RANDOMIZE 0
#define PF_KTHREAD 0