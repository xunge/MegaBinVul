#include <stdbool.h>
#include <stddef.h>

#define EINVAL 22
#define ENOMEM 12
#define SNDRV_CTL_EVENT_MASK_ADD 1

struct list_head {
    struct list_head *next, *prev;
};

struct rw_semaphore {
    int dummy;
};

struct snd_ctl_elem_id {
    unsigned int numid;
    unsigned int index;
    unsigned int iface;
    unsigned int device;
    unsigned int subdevice;
    char name[44];
    unsigned int name_len;
};

struct snd_card {
    struct list_head controls;
    unsigned int controls_count;
    unsigned int last_numid;
    struct rw_semaphore controls_rwsem;
};

struct snd_kcontrol {
    struct list_head list;
    unsigned int count;
    struct snd_ctl_elem_id id;
    int (*info)(struct snd_kcontrol *, void *);
    void *private_data;
};

#define snd_BUG_ON(cond) (cond)

void down_write(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);
void list_add_tail(struct list_head *new, struct list_head *head);
struct snd_kcontrol *snd_ctl_find_id(struct snd_card *card, struct snd_ctl_elem_id *id);
int snd_ctl_remove(struct snd_card *card, struct snd_kcontrol *kcontrol);
int snd_ctl_find_hole(struct snd_card *card, unsigned int count);
void snd_ctl_notify(struct snd_card *card, unsigned int mask, struct snd_ctl_elem_id *id);
void snd_ctl_free_one(struct snd_kcontrol *kcontrol);