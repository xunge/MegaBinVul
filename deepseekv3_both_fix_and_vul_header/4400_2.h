#include <stdlib.h>

struct file {
    void *private_data;
};

struct snd_timer_user {
    void *queue;
    void *tqueue;
    void *timeri;
    int ioctl_lock;
};

struct snd_timer_instance;
struct inode;

void mutex_lock(int *lock);
void mutex_unlock(int *lock);
void kfree(void *ptr);
int snd_timer_close(struct snd_timer_instance *timeri);