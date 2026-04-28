#include <pthread.h>
#include <stdlib.h>

struct snd_use_lock {
    int dummy;
};

struct snd_seq_queue {
    pthread_mutex_t timer_mutex;
    struct snd_seq_timer *timer;
    struct snd_use_lock use_lock;
    struct snd_seq_prioq *tickq;
    struct snd_seq_prioq *timeq;
};

struct snd_seq_timer;
struct snd_seq_prioq;

void snd_seq_timer_stop(struct snd_seq_timer *timer);
void snd_seq_timer_close(struct snd_seq_queue *q);
void snd_use_lock_sync(struct snd_use_lock *lock);
void snd_seq_prioq_delete(struct snd_seq_prioq **prioq);
void snd_seq_timer_delete(struct snd_seq_timer **timer);

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock
#define kfree free