#include <limits.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct rw_semaphore {
    long dummy;
};

struct device;

struct snd_ctl_elem_info;

struct snd_ctl_elem_id {
    unsigned int iface;
    unsigned int device;
    unsigned int subdevice;
    char name[44];
    unsigned int index;
    unsigned int numid;
};

struct snd_card {
    struct rw_semaphore controls_rwsem;
    struct list_head controls;
    unsigned int controls_count;
    unsigned int last_numid;
    struct device *dev;
};

struct snd_kcontrol {
    struct list_head list;
    struct snd_ctl_elem_id id;
    unsigned int count;
    int (*info)(struct snd_kcontrol *, struct snd_ctl_elem_info *);
};

#define EINVAL 22
#define EBUSY 16
#define ENOMEM 12
#define SNDRV_CTL_EVENT_MASK_ADD 1

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

void down_write(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);
int snd_ctl_find_id(struct snd_card *card, struct snd_ctl_elem_id *id);
int snd_ctl_find_hole(struct snd_card *card, unsigned int count);
void snd_ctl_notify(struct snd_card *card, unsigned int mask, struct snd_ctl_elem_id *id);
void snd_ctl_free_one(struct snd_kcontrol *kcontrol);
void dev_err(struct device *dev, const char *fmt, ...);
int snd_BUG_ON(int cond);