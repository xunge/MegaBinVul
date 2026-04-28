#include <sys/poll.h>
#include <stddef.h>

#define TTY_DO_WRITE_WAKEUP 0
#define TTY_DRIVER_RESET_TERMIOS (1 << 0)
#define POLLOUT 0x004
#define POLLIN 0x001
#define WARN_ON(condition) ((void)0)

struct tty_ldisc_ops {
    void (*flush_buffer)(struct tty_struct *);
    void (*write_wakeup)(struct tty_struct *);
    void (*hangup)(struct tty_struct *);
};

struct tty_ldisc {
    struct tty_ldisc_ops *ops;
};

struct tty_driver {
    int flags;
};

struct tty_struct {
    unsigned long flags;
    struct tty_ldisc *ldisc;
    struct tty_driver *driver;
    void *write_wait;
    void *read_wait;
    void *ldisc_mutex;
};

extern struct tty_ldisc *tty_ldisc_ref(struct tty_struct *tty);
extern void tty_ldisc_deref(struct tty_ldisc *ld);
extern void tty_driver_flush_buffer(struct tty_struct *tty);
extern void tty_ldisc_halt(struct tty_struct *tty);
extern void tty_ldisc_reinit(struct tty_struct *tty);
extern int tty_ldisc_open(struct tty_struct *tty, struct tty_ldisc *ld);
extern void tty_ldisc_enable(struct tty_struct *tty);
extern void tty_reset_termios(struct tty_struct *tty);
extern void wake_up_interruptible_poll(void *wait, int flags);
extern void mutex_lock(void *mutex);
extern void mutex_unlock(void *mutex);

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr >> nr) & 1;
}