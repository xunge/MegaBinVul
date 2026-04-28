#include <stddef.h>

#define SNDRV_TIMER_IFLG_RUNNING 0x00000001

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer {
    int lock;
};

struct snd_timer_instance {
    unsigned int flags;
    struct snd_timer_instance *master;
    struct snd_timer *timer;
    struct list_head active_list;
    struct list_head slave_active_head;
};

static int slave_active_lock;

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}