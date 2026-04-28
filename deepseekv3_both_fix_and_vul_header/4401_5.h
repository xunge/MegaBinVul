#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

struct file {
    void *private_data;
};

struct snd_timer_select {
    struct {
        int dev_class;
        int dev_sclass;
    } id;
};

struct snd_timer_read {
    // dummy structure
};

struct snd_timer_tread {
    // dummy structure
};

struct snd_timer_instance {
    int flags;
    void (*callback)(void);
    void (*ccallback)(void);
    void *callback_data;
};

struct snd_timer_user {
    struct snd_timer_instance *timeri;
    pthread_mutex_t tread_sem;
    int tread;
    size_t queue_size;
    struct snd_timer_read *queue;
    struct snd_timer_tread *tqueue;
};

#define SNDRV_TIMER_CLASS_SLAVE 0
#define SNDRV_TIMER_SCLASS_APPLICATION 0
#define SNDRV_TIMER_IFLG_FAST 0
#define GFP_KERNEL 0
#define ENOMEM (-1)
#define EFAULT (-1)

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock

struct task_struct {
    int pid;
};

extern struct task_struct *current;

int snd_timer_close(struct snd_timer_instance *timeri);
int snd_timer_open(struct snd_timer_instance **timeri, const char *str, void *id, int pid);
int copy_from_user(void *dst, const void *src, size_t size);
void *kmalloc(size_t size, int flags);
void kfree(void *ptr);

void snd_timer_user_tinterrupt(void);
void snd_timer_user_interrupt(void);
void snd_timer_user_ccallback(void);

#define __user