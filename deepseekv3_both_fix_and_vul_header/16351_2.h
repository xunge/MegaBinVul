#include <sys/types.h>
#include <unistd.h>
#include <string.h>

struct tty_struct {
    int ctrl_lock;
    pid_t *session;
    pid_t *pgrp;
    char name[64];
};

struct signal_struct {
    struct tty_struct *tty;
    pid_t *tty_old_pgrp;
};

struct task_struct {
    struct signal_struct *signal;
};

extern struct task_struct *current;

void spin_lock_irqsave(int *lock, unsigned long flags);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
pid_t *get_pid(pid_t pid);
void put_pid(pid_t *pid);
pid_t task_pgrp(struct task_struct *task);
pid_t task_session(struct task_struct *task);
void tty_debug(struct tty_struct *tty, const char *fmt, ...);
void tty_kref_put(struct tty_struct *tty);
struct tty_struct *tty_kref_get(struct tty_struct *tty);