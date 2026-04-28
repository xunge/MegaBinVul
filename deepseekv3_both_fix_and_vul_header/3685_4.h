#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define ENODEV 19
#define EBUSY 16
#define SNDRV_CARDS 32

struct device {
    struct device *parent;
    struct class *class;
    void (*release)(struct device *dev);
    const void *groups;
    void *kobj;
};

struct module;
struct class;
struct attribute_group;

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    pthread_mutex_t lock;
};

struct rw_semaphore {
    pthread_rwlock_t lock;
};

struct rwlock_t {
    pthread_rwlock_t lock;
};

struct spinlock_t {
    pthread_spinlock_t lock;
};

struct wait_queue_head {
    pthread_cond_t cond;
};

struct snd_card {
    char id[32];
    void *private_data;
    struct device *dev;
    int number;
    struct module *module;
    struct list_head devices;
    struct rw_semaphore controls_rwsem;
    struct rwlock_t ctl_files_rwlock;
    struct mutex user_ctl_lock;
    struct list_head controls;
    struct list_head ctl_files;
    struct spinlock_t files_lock;
    struct list_head files_list;
#ifdef CONFIG_PM
    struct mutex power_lock;
    struct wait_queue_head power_sleep;
#endif
    struct device card_dev;
};

extern struct mutex snd_card_mutex;
extern unsigned long *snd_cards_lock;
extern int snd_ecards_limit;
extern struct class *sound_class;
extern const struct attribute_group *card_dev_attr_groups[];

int snd_BUG_ON(int condition);
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
int get_slot_from_bitmask(int idx, int (*func)(int, struct module *), struct module *module);
int test_bit(int nr, const unsigned long *addr);
void set_bit(int nr, unsigned long *addr);
void INIT_LIST_HEAD(struct list_head *list);
void init_rwsem(struct rw_semaphore *sem);
void rwlock_init(struct rwlock_t *lock);
void mutex_init(struct mutex *lock);
void spin_lock_init(struct spinlock_t *lock);
void init_waitqueue_head(struct wait_queue_head *wq_head);
int dev_err(const struct device *dev, const char *fmt, ...);
int module_slot_match(int idx, struct module *module);
int check_empty_slot(int idx, struct module *module);
size_t strlcpy(char *dest, const char *src, size_t size);
void device_initialize(struct device *dev);
void release_card_device(struct device *dev);
int kobject_set_name(void *kobj, const char *fmt, ...);
int snd_ctl_create(struct snd_card *card);
int snd_info_card_create(struct snd_card *card);
void snd_device_free_all(struct snd_card *card);
void put_device(struct device *dev);