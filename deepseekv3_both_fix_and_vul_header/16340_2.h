#include <stddef.h>

struct task_struct {
    struct files_struct *files;
};

struct files_struct;

void task_lock(struct task_struct *tsk);
void task_unlock(struct task_struct *tsk);
void put_files_struct(struct files_struct *files);