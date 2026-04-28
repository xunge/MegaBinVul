#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#define SNDRV_TIMER_HW_SLAVE 0x00000001

#define SNDRV_TIMER_EVENT_RESOLUTION 0
#define SNDRV_TIMER_EVENT_TICK 1
#define SNDRV_TIMER_EVENT_START 2
#define SNDRV_TIMER_EVENT_STOP 3
#define SNDRV_TIMER_EVENT_CONTINUE 4
#define SNDRV_TIMER_EVENT_PAUSE 5
#define SNDRV_TIMER_EVENT_SUSPEND 6
#define SNDRV_TIMER_EVENT_RESUME 7
#define SNDRV_TIMER_EVENT_MSTART 8
#define SNDRV_TIMER_EVENT_MSTOP 9
#define SNDRV_TIMER_EVENT_MCONTINUE 10
#define SNDRV_TIMER_EVENT_MPAUSE 11
#define SNDRV_TIMER_EVENT_MSUSPEND 12
#define SNDRV_TIMER_EVENT_MRESUME 13
#define SNDRV_TIMER_EVENT_EARLY 14

#define SNDRV_TIMER_IFLG_AUTO 0x00000001
#define SNDRV_TIMER_IFLG_EXCLUSIVE 0x00000002
#define SNDRV_TIMER_IFLG_EARLY_EVENT 0x00000004

#define SNDRV_TIMER_PSFLG_AUTO 0x00000001
#define SNDRV_TIMER_PSFLG_EXCLUSIVE 0x00000002
#define SNDRV_TIMER_PSFLG_EARLY_EVENT 0x00000004

#define GFP_KERNEL 0

struct file {
    void *private_data;
};

struct snd_timer_user {
    struct snd_timer_instance *timeri;
    unsigned int queue_size;
    struct snd_timer_read *queue;
    struct snd_timer_tread *tqueue;
    int tread;
    unsigned int qhead;
    unsigned int qtail;
    unsigned int qused;
    unsigned int filter;
    unsigned int ticks;
};

struct snd_timer_instance {
    struct snd_timer *timer;
    unsigned int flags;
};

struct snd_timer {
    int lock;
    struct {
        unsigned int flags;
    } hw;
};

struct snd_timer_params {
    unsigned int ticks;
    unsigned int queue_size;
    unsigned int filter;
    unsigned int flags;
};

struct snd_timer_read {
    unsigned int resolution;
    unsigned int ticks;
};

struct snd_timer_tread {
    int event;
    struct {
        long tv_sec;
        long tv_nsec;
    } tstamp;
    unsigned int val;
};

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void spin_lock_irq(int *lock) {
    (void)lock;
}

static inline void spin_unlock_irq(int *lock) {
    (void)lock;
}

static inline void snd_timer_stop(struct snd_timer_instance *timeri) {
    (void)timeri;
}

static inline void snd_timer_user_append_to_tqueue(struct snd_timer_user *tu, struct snd_timer_tread *tread) {
    (void)tu;
    (void)tread;
}

#define __user