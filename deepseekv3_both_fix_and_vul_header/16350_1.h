#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

struct tty_struct {
    int ctrl_lock;
    pid_t *session;
};

struct task_struct {
    struct signal_struct *signal;
    struct tty_struct *tty;
};

struct signal_struct {
    struct tty_struct *tty;
};

#define current (&(struct task_struct){0})
#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define pid_vnr(pid) (*(pid))
#define put_user(x, ptr) (*(ptr) = (x), 0)
#define __user
#define ENOTTY EIO