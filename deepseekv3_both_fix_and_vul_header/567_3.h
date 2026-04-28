#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int dummy;
} spinlock_t;

typedef struct {
    int dummy;
} mutex_t;

typedef struct {
    int dummy;
} wait_queue_head_t;

struct device {
    int dummy;
};

struct file {
    struct file_operations *f_op;
};

struct list_head {
    struct list_head *next, *prev;
};

struct file_operations {
    int dummy;
};

struct snd_monitor_file {
    struct file_operations *disconnected_f_op;
    struct file *file;
    struct list_head shutdown_list;
    struct list_head list;
};

struct snd_card {
    spinlock_t files_lock;
    int shutdown;
    struct list_head files_list;
    int number;
    bool registered;
    struct device card_dev;
    wait_queue_head_t power_sleep;
};

extern int EINVAL;
extern spinlock_t shutdown_lock;
extern struct list_head shutdown_files;
extern mutex_t snd_card_mutex;
extern struct snd_card *snd_cards[];
extern unsigned long snd_cards_lock[];
extern struct file_operations snd_shutdown_f_ops;
extern void (*snd_mixer_oss_notify_callback)(struct snd_card *, int);

void spin_lock(spinlock_t *lock);
void spin_unlock(spinlock_t *lock);
void mutex_lock(mutex_t *lock);
void mutex_unlock(mutex_t *lock);
void list_add(struct list_head *new, struct list_head *head);
void clear_bit(int nr, volatile unsigned long *addr);
void wake_up(wait_queue_head_t *q);
void fops_get(struct file_operations *fops);
void device_del(struct device *dev);
void snd_device_disconnect_all(struct snd_card *card);
void snd_info_card_disconnect(struct snd_card *card);

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((head)->next); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)(pos->member.next))

#define IS_ENABLED(x) 0
#define CONFIG_SND_MIXER_OSS 0
#define SND_MIXER_OSS_NOTIFY_DISCONNECT 0
#define CONFIG_PM 0