#include <pthread.h>

#define SNDRV_TIMER_VERSION 0x000100
#define SNDRV_TIMER_IOCTL_PVERSION 0
#define SNDRV_TIMER_IOCTL_NEXT_DEVICE 1
#define SNDRV_TIMER_IOCTL_TREAD 2
#define SNDRV_TIMER_IOCTL_GINFO 3
#define SNDRV_TIMER_IOCTL_GPARAMS 4
#define SNDRV_TIMER_IOCTL_GSTATUS 5
#define SNDRV_TIMER_IOCTL_SELECT 6
#define SNDRV_TIMER_IOCTL_INFO 7
#define SNDRV_TIMER_IOCTL_PARAMS 8
#define SNDRV_TIMER_IOCTL_STATUS 9
#define SNDRV_TIMER_IOCTL_START 10
#define SNDRV_TIMER_IOCTL_STOP 11
#define SNDRV_TIMER_IOCTL_CONTINUE 12
#define SNDRV_TIMER_IOCTL_PAUSE 13
#define SNDRV_TIMER_IOCTL_START_OLD 32
#define SNDRV_TIMER_IOCTL_STOP_OLD 33
#define SNDRV_TIMER_IOCTL_CONTINUE_OLD 34
#define SNDRV_TIMER_IOCTL_PAUSE_OLD 35

#define EBUSY 16
#define ENOTTY 25
#define EFAULT 14

struct file {
    void *private_data;
};

struct snd_timer_user {
    pthread_mutex_t ioctl_lock;
    pthread_mutex_t tread_sem;
    void *timeri;
    int tread;
};

static inline int put_user(int val, int *addr) {
    *addr = val;
    return 0;
}

static inline int get_user(int *val, int *addr) {
    *val = *addr;
    return 0;
}

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)

typedef void* argp_t;
typedef int* p_t;

#define __user

extern long __snd_timer_user_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
extern int snd_timer_user_next_device(argp_t arg);
extern int snd_timer_user_ginfo(struct file *file, argp_t arg);
extern int snd_timer_user_gparams(struct file *file, argp_t arg);
extern int snd_timer_user_gstatus(struct file *file, argp_t arg);
extern int snd_timer_user_tselect(struct file *file, argp_t arg);
extern int snd_timer_user_info(struct file *file, argp_t arg);
extern int snd_timer_user_params(struct file *file, argp_t arg);
extern int snd_timer_user_status(struct file *file, argp_t arg);
extern int snd_timer_user_start(struct file *file);
extern int snd_timer_user_stop(struct file *file);
extern int snd_timer_user_continue(struct file *file);
extern int snd_timer_user_pause(struct file *file);