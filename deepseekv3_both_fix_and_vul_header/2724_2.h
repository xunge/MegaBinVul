#include <stdlib.h>
#include <pthread.h>

struct cred;
struct signal_struct {
    pthread_mutex_t cred_guard_mutex;
};
struct task_struct {
    struct signal_struct *signal;
};
extern struct task_struct *current;

struct linux_binprm {
    struct cred *cred;
    char *interp;
    char *filename;
};

void free_arg_pages(struct linux_binprm *bprm);
void mutex_unlock(pthread_mutex_t *lock);
void abort_creds(struct cred *cred);
void kfree(const void *objp);