#include <signal.h>
#include <stddef.h>
#include <sys/types.h>

#define TTY_DRIVER_TYPE_PTY 2

struct tty_struct {
    struct {
        int type;
    } *driver;
    struct pid *session;
    struct pid *pgrp;
    void *ctrl_lock;
};

struct pid;
struct task_struct {
    struct {
        struct pid *tty_old_pgrp;
        int leader;
        struct tty_struct *tty;
    } *signal;
    struct {
        void *siglock;
    } *sighand;
};

extern struct task_struct *current;
extern struct tty_struct *get_current_tty(void);
extern void tty_vhangup_session(struct tty_struct *tty);
extern struct pid *tty_get_pgrp(struct tty_struct *tty);
extern void kill_pgrp(struct pid *pgrp, int sig, int on_exit);
extern void put_pid(struct pid *pid);
extern void tty_kref_put(struct tty_struct *tty);
extern struct tty_struct *tty_kref_get(struct tty_struct *tty);
extern void session_clear_tty(struct pid *session);
extern void spin_lock_irq(void *lock);
extern void spin_unlock_irq(void *lock);
extern void spin_lock_irqsave(void *lock, unsigned long flags);
extern void spin_unlock_irqrestore(void *lock, unsigned long flags);
extern void read_lock(void *lock);
extern void read_unlock(void *lock);
extern struct pid *task_session(struct task_struct *task);

extern void *tasklist_lock;