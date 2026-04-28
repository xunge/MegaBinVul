#include <stdlib.h>
#include <unistd.h>

struct binder_task_work_cb {
    void *twork;
    void *file;
};

struct task_struct {
    void *files;
};

extern struct task_struct *current;

#define GFP_KERNEL 0
#define TWA_RESUME 0

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void init_task_work(void *twork, void (*func)(void *));
void task_work_add(struct task_struct *task, void *twork, int flags);
void filp_close(void *file, void *files);
void __close_fd_get_file(int fd, void **file);
void binder_do_fd_close(void *arg);