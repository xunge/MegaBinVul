#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct snd_timer_id {
    int dev_class;
    int dev_sclass;
};

struct snd_timer_select {
    struct snd_timer_id id;
};

struct snd_timer_read {
    int dummy;
};

struct snd_timer_tread {
    int dummy;
};

struct snd_timer_user {
    struct snd_timer_instance *timeri;
    unsigned int qhead;
    unsigned int qtail;
    unsigned int qused;
    struct snd_timer_read *queue;
    struct snd_timer_tread *tqueue;
    unsigned int queue_size;
    bool tread;
};

struct snd_timer_instance {
    unsigned int flags;
    void (*callback)(struct snd_timer_instance *);
    void (*ccallback)(struct snd_timer_instance *, int);
    void *callback_data;
    void (*disconnect)(struct snd_timer_instance *);
};

struct file {
    void *private_data;
};

struct task_struct {
    int pid;
};

extern struct task_struct *current;

#define SNDRV_TIMER_CLASS_SLAVE 0
#define SNDRV_TIMER_SCLASS_APPLICATION 0
#define SNDRV_TIMER_IFLG_FAST (1 << 0)
#define ENOMEM 12
#define EFAULT 14
#define GFP_KERNEL 0
#define __user

void snd_timer_user_tinterrupt(struct snd_timer_instance *timeri);
void snd_timer_user_interrupt(struct snd_timer_instance *timeri);
void snd_timer_user_ccallback(struct snd_timer_instance *timeri, int event);
void snd_timer_user_disconnect(struct snd_timer_instance *timeri);

extern int snd_timer_close(struct snd_timer_instance *timeri);
extern int snd_timer_open(struct snd_timer_instance **timeri, const char *id, struct snd_timer_id *tid, int pid);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);