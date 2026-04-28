#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

struct file {
    void *private_data;
};

struct usb_yurex {
    void *interface;
    pthread_mutex_t io_mutex;
    pthread_spinlock_t lock;
    long long bbu;
};

#define __user
#define ENODEV 19
#define EFAULT 14
#define loff_t off_t
#define ssize_t ssize_t
#define size_t size_t

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define spin_lock_irqsave(lock, flags) pthread_spin_lock(lock)
#define spin_unlock_irqrestore(lock, flags) pthread_spin_unlock(lock)
#define copy_to_user(dest, src, size) memcpy(dest, src, size)