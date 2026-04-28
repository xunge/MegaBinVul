#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

struct seq_file {
    void *private;
    unsigned long version;
};

struct mm_struct {
    unsigned long map_count;
    struct vm_area_struct *mmap;
    void *mmap_sem;
};

struct vm_area_struct {
    struct vm_area_struct *vm_next;
    unsigned long vm_start;
};

struct task_struct;
struct pid;

enum pid_type {
    PIDTYPE_PID
};

struct proc_maps_private {
    struct task_struct *task;
    struct vm_area_struct *tail_vma;
    struct pid *pid;
};

struct task_struct *get_pid_task(struct pid *pid, enum pid_type type);
struct mm_struct *mm_for_maps(struct task_struct *task);
struct vm_area_struct *get_gate_vma(struct task_struct *task);
struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
void up_read(void *sem);
void mmput(struct mm_struct *mm);