#include <stddef.h>

#define ENXIO 6
#define EINVAL 22

#define SNDRV_TIMER_IFLG_SLAVE 0x00000001
#define SNDRV_TIMER_IFLG_RUNNING 0x00000002
#define SNDRV_TIMER_IFLG_START 0x00000004
#define SNDRV_TIMER_FLG_RESCHED 0x00000001
#define SNDRV_TIMER_FLG_CHANGE 0x00000002
#define SNDRV_TIMER_EVENT_RESOLUTION 0x00000001

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer;
struct snd_timer_instance {
    unsigned int flags;
    struct snd_timer *timer;
    struct list_head ack_list;
    struct list_head active_list;
};

struct snd_timer {
    unsigned long lock;
    unsigned int running;
    unsigned int flags;
    struct {
        void (*stop)(struct snd_timer *);
        void (*start)(struct snd_timer *);
    } hw;
};

static unsigned long slave_active_lock;

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void list_del_init(struct list_head *entry) {}

int snd_BUG_ON(int condition);
void snd_timer_reschedule(struct snd_timer *timer, int ticks);
void snd_timer_notify1(struct snd_timer_instance *timeri, int event);