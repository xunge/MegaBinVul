#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define KERN_ERR
#define printk(...) printf(__VA_ARGS__)

typedef int (*uwbd_func)(void*);

struct task_struct {
    pid_t pid;
};

struct uwb_rc {
    struct {
        struct task_struct *task;
        pid_t pid;
    } uwbd;
};

static int uwbd(void *data) {
    return 0;
}

static struct task_struct *kthread_run(uwbd_func func, void *data, const char *name) {
    pid_t pid = fork();
    if (pid == 0) {
        exit(func(data));
    }
    struct task_struct *task = malloc(sizeof(struct task_struct));
    if (task) {
        task->pid = pid;
    }
    return task;
}