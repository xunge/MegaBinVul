#include <stdlib.h>
#include <stddef.h>

#define SNDRV_TIMER_IFLG_SLAVE 0x00000001
#define SNDRV_TIMER_IFLG_CALLBACK 0x00000002
#define ENXIO 6
#define SNDRV_TIMER_EVENT_RESOLUTION 0

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer;
struct snd_timer_instance;

struct snd_timer_hardware {
    void (*close)(struct snd_timer *timer);
};

struct snd_timer {
    struct list_head open_list_head;
    struct snd_timer_hardware hw;
    void *lock;
    void *module;
};

struct snd_timer_instance {
    unsigned int flags;
    struct snd_timer *timer;
    struct list_head open_list;
    struct list_head slave_list_head;
    struct list_head ack_list;
    struct list_head active_list;
    struct snd_timer_instance *master;
    void (*private_free)(struct snd_timer_instance *timeri);
    char *owner;
};

static void *slave_active_lock;
static void *register_mutex;
static struct list_head snd_timer_slave_list = { &snd_timer_slave_list, &snd_timer_slave_list };

void snd_timer_stop(struct snd_timer_instance *timeri);
void _snd_timer_stop(struct snd_timer_instance *timeri, int event, int resolution);
int snd_BUG_ON(int condition);
void spin_lock_irq(void *lock);
void spin_unlock_irq(void *lock);
void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);
void udelay(unsigned long usecs);
void kfree(void *ptr);
void module_put(void *module);
void list_del(struct list_head *entry);
int list_empty(const struct list_head *head);
#define list_for_each_entry_safe(pos, n, head, member) for (pos = NULL, n = NULL; pos != NULL; pos = n)
void list_move_tail(struct list_head *list, struct list_head *head);
void list_del_init(struct list_head *entry);