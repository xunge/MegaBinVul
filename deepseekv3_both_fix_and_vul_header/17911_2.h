#include <stddef.h>

struct seq_file {
    void *private;
};

struct proc_maps_private {
    struct task_struct *task;
};

struct task_struct;
struct vm_area_struct;

extern void vma_stop(struct proc_maps_private *priv, struct vm_area_struct *vma);
extern void put_task_struct(struct task_struct *task);