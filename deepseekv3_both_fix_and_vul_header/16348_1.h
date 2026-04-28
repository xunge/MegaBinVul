#include <stddef.h>
#include <signal.h>
#include <sys/types.h>

struct tty_struct;
struct task_struct;
struct pid;
struct files_struct;

#define TTY_SOFT_SAK
#define PIDTYPE_SID 0
#define SIGKILL 9
#define SEND_SIG_PRIV 0

extern void tty_hangup(struct tty_struct *tty);
extern void tty_ldisc_flush(struct tty_struct *tty);
extern void tty_driver_flush_buffer(struct tty_struct *tty);
extern void tty_notice(struct tty_struct *tty, const char *fmt, ...);
extern int iterate_fd(struct files_struct *files, unsigned int nr, int (*f)(const void *, void *, unsigned int), const void *p);
extern int this_tty(const void *t, void *file, unsigned fd);
extern void group_send_sig_info(int sig, int priv, struct task_struct *p, int type);
extern void read_lock(void *lock);
extern void read_unlock(void *lock);
extern void task_lock(struct task_struct *p);
extern void task_unlock(struct task_struct *p);
extern int task_pid_nr(struct task_struct *p);

#define do_each_pid_task(pid, type, task) \
    for (task = NULL; task != NULL; task = NULL)

#define while_each_pid_task(pid, type, task) \
    (0)

#define do_each_thread(g, t) \
    for (t = NULL; t != NULL; t = NULL)

#define while_each_thread(g, t) \
    (0)