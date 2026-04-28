#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>

#define L_TOSTOP(tty) 0
#define O_OPOST(tty) 0
#define TASK_INTERRUPTIBLE 1
#define TASK_RUNNING 0
#define TTY_DO_WRITE_WAKEUP 0
#define ERESTARTSYS EINTR

struct n_tty_data {
    pthread_mutex_t output_lock;
};

struct tty_struct {
    struct tty_operations *ops;
    struct n_tty_data *disc_data;
    struct tty_struct *link;
    int count;
    void *fasync;
    pthread_rwlock_t termios_rwsem;
    pthread_cond_t write_wait;
    unsigned long flags;
};

struct tty_operations {
    ssize_t (*write)(struct tty_struct *, const unsigned char *, size_t);
    void (*flush_chars)(struct tty_struct *);
};

struct file {
    unsigned int f_flags;
    struct file_operations *f_op;
};

struct file_operations {
    ssize_t (*write)(struct file *, const unsigned char *, size_t);
};

#define DECLARE_WAITQUEUE(wait, current) int wait = 0
#define current (pthread_self())
#define signal_pending(x) (0)
#define tty_hung_up_p(x) (0)
#define set_current_state(x) do {} while(0)
#define __set_current_state(x) do {} while(0)
#define add_wait_queue(x, y) do {} while(0)
#define remove_wait_queue(x, y) do {} while(0)
#define set_bit(x, y) do {} while(0)
#define down_read(x) pthread_rwlock_rdlock(x)
#define up_read(x) pthread_rwlock_unlock(x)
#define mutex_lock(x) pthread_mutex_lock(x)
#define mutex_unlock(x) pthread_mutex_unlock(x)
#define schedule() sched_yield()

extern ssize_t redirected_tty_write(struct file *, const unsigned char *, size_t);
extern ssize_t tty_check_change(struct tty_struct *);
extern void process_echoes(struct tty_struct *);
extern ssize_t process_output_block(struct tty_struct *, const unsigned char *, size_t);
extern int process_output(int, struct tty_struct *);