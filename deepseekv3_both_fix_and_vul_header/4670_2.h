#include <time.h>
#include <signal.h>
#include <string.h>

#define SNDRV_TIMER_EVENT_RESOLUTION 0
#define SNDRV_TIMER_EVENT_TICK 1

struct snd_timer_instance {
    void *callback_data;
};

struct snd_timer_user {
    unsigned long filter;
    unsigned long last_resolution;
    int qused;
    int qtail;
    int queue_size;
    struct snd_timer_tread *tqueue;
    void *qlock;
    void *fasync;
    void *qchange_sleep;
};

struct snd_timer_tread {
    int event;
    struct timespec tstamp;
    unsigned long val;
};

extern int timer_tstamp_monotonic;

void spin_lock(void *lock);
void spin_unlock(void *lock);
void kill_fasync(void **fasync, int sig, int band);
void wake_up(void *sleep);
void ktime_get_ts(struct timespec *ts);
void getnstimeofday(struct timespec *tv);
void snd_timer_user_append_to_tqueue(struct snd_timer_user *tu, struct snd_timer_tread *r);