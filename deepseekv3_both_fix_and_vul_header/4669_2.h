#include <time.h>
#include <signal.h>
#include <sys/poll.h>

#define SNDRV_TIMER_EVENT_START 0
#define SNDRV_TIMER_EVENT_PAUSE 1

struct snd_timer_instance {
    void *callback_data;
};

struct snd_timer_user {
    struct timespec tstamp;
    unsigned int filter;
    int tread;
    void *qlock;
    struct fasync_struct *fasync;
    void *qchange_sleep;
};

struct snd_timer_tread {
    int event;
    struct timespec tstamp;
    unsigned long val;
};

struct fasync_struct;

void spin_lock_irqsave(void *lock, unsigned long flags);
void spin_unlock_irqrestore(void *lock, unsigned long flags);
void snd_timer_user_append_to_tqueue(struct snd_timer_user *tu, struct snd_timer_tread *r1);
void kill_fasync(struct fasync_struct **, int, int);
void wake_up(void *);