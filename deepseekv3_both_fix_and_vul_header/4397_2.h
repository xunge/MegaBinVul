#include <stddef.h>

struct snd_timer_instance;
struct snd_timer;

#define SNDRV_TIMER_IFLG_RUNNING   (1<<0)
#define SNDRV_TIMER_IFLG_AUTO      (1<<1)
#define SNDRV_TIMER_IFLG_FAST      (1<<2)
#define SNDRV_TIMER_IFLG_CALLBACK  (1<<3)

#define SNDRV_TIMER_HW_TASKLET     (1<<0)
#define SNDRV_TIMER_HW_STOP        (1<<1)
#define SNDRV_TIMER_HW_AUTO        (1<<2)

#define SNDRV_TIMER_FLG_RESCHED    (1<<0)
#define SNDRV_TIMER_FLG_CHANGE     (1<<1)

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer_hardware {
    unsigned long resolution;
    unsigned long (*c_resolution)(struct snd_timer *timer);
    void (*start)(struct snd_timer *timer);
    void (*stop)(struct snd_timer *timer);
    unsigned int flags;
};

struct snd_timer_instance {
    struct list_head active_list;
    struct list_head ack_list;
    struct list_head slave_active_head;
    unsigned long pticks;
    unsigned long cticks;
    unsigned long ticks;
    unsigned long resolution;
    unsigned int flags;
    void (*callback)(struct snd_timer_instance *timer, unsigned long resolution, unsigned long ticks);
};

struct snd_timer {
    unsigned long lock;
    struct list_head active_list_head;
    struct list_head ack_list_head;
    struct list_head sack_list_head;
    struct snd_timer_hardware hw;
    unsigned int running;
    unsigned long sticks;
    unsigned int flags;
    void *task_queue;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_empty(list) ((list)->next == (list))
#define list_add_tail(new, head) do { \
    (new)->prev = (head)->prev; \
    (new)->next = (head); \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

#define list_del_init(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
    (entry)->next = (entry); \
    (entry)->prev = (entry); \
} while (0)

#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void spin_lock(unsigned long *lock) {}
static inline void spin_unlock(unsigned long *lock) {}
static inline void tasklet_schedule(void *task_queue) {}
static inline void snd_timer_reschedule(struct snd_timer *timer, unsigned long sticks) {}