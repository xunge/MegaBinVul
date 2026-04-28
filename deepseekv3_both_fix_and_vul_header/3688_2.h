#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <pthread.h>

struct list_head {
    struct list_head *next, *prev;
};

struct snd_ctl_elem_id {
    unsigned int iface;
    unsigned int device;
    unsigned int subdevice;
    char name[44];
    unsigned int index;
    unsigned int numid;
};

struct snd_card {
    struct list_head controls;
    unsigned int controls_count;
    unsigned int last_numid;
    pthread_rwlock_t controls_rwsem;
    void *dev;
};

struct snd_kcontrol {
    struct list_head list;
    struct snd_ctl_elem_id id;
    unsigned int count;
    void *info;
};

#define SNDRV_CTL_EVENT_MASK_ADD 1
#define snd_BUG_ON(cond) (cond)
#define dev_err(dev, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

int snd_ctl_find_id(struct snd_card *card, struct snd_ctl_elem_id *id);
int snd_ctl_find_hole(struct snd_card *card, unsigned int count);
void snd_ctl_notify(struct snd_card *card, unsigned int mask, struct snd_ctl_elem_id *id);
void snd_ctl_free_one(struct snd_kcontrol *kcontrol);

static inline void down_write(pthread_rwlock_t *lock) {
    pthread_rwlock_wrlock(lock);
}

static inline void up_write(pthread_rwlock_t *lock) {
    pthread_rwlock_unlock(lock);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}