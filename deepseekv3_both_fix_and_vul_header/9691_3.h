#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

typedef struct spinlock {
    pthread_mutex_t lock;
} spinlock_t;

typedef struct wait_queue_head {
    pthread_cond_t cond;
    pthread_mutex_t mutex;
} wait_queue_head_t;

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    unsigned long i_ino;
};

struct fasync_struct {
    int magic;
};

struct pid {
    int nr;
};

struct task_struct {
    pid_t pid;
};

struct tty_struct {
    void *private_data;
    struct dentry *f_path_dentry;
    struct inode *d_inode;
    struct fasync_struct *fasync;
    wait_queue_head_t read_wait;
    int minimum_to_wake;
    spinlock_t ctrl_lock;
    struct pid *pgrp;
};

struct file {
    void *private_data;
    struct path f_path;
};

enum pid_type {
    PIDTYPE_PID,
    PIDTYPE_PGID
};

#define N_TTY_BUF_SIZE 4096
#define current ((struct task_struct *)0)

int tty_paranoia_check(struct tty_struct *tty, struct inode *inode, const char *str);
int fasync_helper(int fd, struct file *filp, int on, struct fasync_struct **fapp);
struct pid *task_pid(struct task_struct *task);
int __f_setown(struct file *filp, struct pid *pid, enum pid_type type, int force);
void lock_kernel(void);
void unlock_kernel(void);
int waitqueue_active(wait_queue_head_t *q);
void spin_lock_irqsave(spinlock_t *lock, unsigned long flags);
void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);