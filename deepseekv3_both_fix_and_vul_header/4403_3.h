#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer_instance {
    int slave_class;
    int slave_id;
    struct list_head open_list;
    struct list_head slave_list_head;
    struct list_head active_list;
    struct snd_timer_instance *master;
    struct snd_timer *timer;
    unsigned int flags;
    struct list_head *next;
};

struct snd_timer {
    int lock;
};

struct list_head snd_timer_slave_list;
int slave_active_lock;

#define SNDRV_TIMER_IFLG_RUNNING (1 << 0)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((head)->next), \
         n = (typeof(*pos)*)(pos->next); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)(pos->next))

#define list_move_tail(list, head) do {} while (0)
#define list_add_tail(list, head) do {} while (0)
#define spin_lock_irq(lock) do {} while (0)
#define spin_unlock_irq(lock) do {} while (0)
#define spin_lock(lock) do {} while (0)
#define spin_unlock(lock) do {} while (0)