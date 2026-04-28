#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define __user
#define O_NONBLOCK 04000
#define EAGAIN 11
#define ENODEV 19
#define ERESTARTSYS 512
#define EFAULT 14
#define TASK_INTERRUPTIBLE 1

typedef int spinlock_t;
typedef int wait_queue_t;
typedef int mutex_t;
typedef long ssize_t;
typedef long loff_t;

struct file {
    int f_flags;
    void *private_data;
};

struct snd_timer_user {
    int tread;
    spinlock_t qlock;
    int qused;
    int qhead;
    int queue_size;
    wait_queue_t qchange_sleep;
    int disconnected;
    mutex_t ioctl_lock;
    struct snd_timer_tread *tqueue;
    struct snd_timer_read *queue;
};

struct snd_timer_tread {};
struct snd_timer_read {};

extern void *current;

#define spin_lock_irq(lock) (void)0
#define spin_unlock_irq(lock) (void)0
#define mutex_lock(lock) (void)0
#define mutex_unlock(lock) (void)0
#define set_current_state(state) (void)0
#define init_waitqueue_entry(wait, task) (void)0
#define add_wait_queue(queue, wait) (void)0
#define remove_wait_queue(queue, wait) (void)0
#define schedule() (void)0
#define signal_pending(task) 0
#define copy_to_user(to, from, size) 0