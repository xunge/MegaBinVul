#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct device {
    // minimal device structure definition
    int dummy;
};

struct module {
    // minimal module structure definition
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct snd_timer_instance;

struct snd_timer_hw {
    int (*open)(struct snd_timer_instance *timer);
};

struct snd_card {
    struct device card_dev;
};

struct snd_timer {
    struct list_head open_list_head;
    unsigned int num_instances;
    unsigned int max_instances;
    struct snd_card *card;
    struct module *module;
    struct snd_timer_hw hw;
};

struct snd_timer_instance {
    struct list_head open_list;
    unsigned int slave_class;
    unsigned int slave_id;
    unsigned int flags;
    char *owner;
    struct snd_timer *timer;
};

struct snd_timer_id {
    int dev_class;
    int dev_sclass;
    int device;
};

extern struct mutex register_mutex;
extern struct list_head snd_timer_slave_list;

#define SNDRV_TIMER_CLASS_SLAVE 0
#define SNDRV_TIMER_SCLASS_NONE 0
#define SNDRV_TIMER_SCLASS_OSS_SEQUENCER 1
#define SNDRV_TIMER_IFLG_SLAVE (1<<0)
#define SNDRV_TIMER_IFLG_EXCLUSIVE (1<<1)

#define ENODEV 19
#define EBUSY 16
#define EINVAL 22
#define ENOMEM 12

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

extern struct snd_timer_instance *snd_timer_instance_new(char *owner, struct snd_timer *timer);
extern int snd_timer_check_slave(struct snd_timer_instance *timeri);
extern int snd_timer_check_master(struct snd_timer_instance *timeri);
extern void snd_timer_close_locked(struct snd_timer_instance *timeri, struct device **dev);
extern struct snd_timer *snd_timer_find(struct snd_timer_id *tid);
extern void snd_timer_request(struct snd_timer_id *tid);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);
extern void kfree(const void *objp);
extern void module_put(struct module *module);
extern void get_device(struct device *dev);
extern void put_device(struct device *dev);