#include <pthread.h>

struct snd_ctl_elem_id {
    int dummy;
};

struct snd_ctl_elem_value {
    struct snd_ctl_elem_id id;
};

struct snd_kcontrol_volatile {
    unsigned int access;
    struct snd_ctl_file *owner;
};

struct snd_kcontrol {
    struct snd_kcontrol_volatile *vd;
    int (*put)(struct snd_kcontrol *, struct snd_ctl_elem_value *);
};

struct snd_card {
    pthread_rwlock_t controls_rwsem;
};

struct snd_ctl_file {
    int dummy;
};

#define SNDRV_CTL_ELEM_ACCESS_WRITE 0x00000001
#define SNDRV_CTL_EVENT_MASK_VALUE 0x00000001
#define ENOENT 2
#define EPERM 1

static inline void down_read(pthread_rwlock_t *lock) {
    pthread_rwlock_rdlock(lock);
}

static inline void up_read(pthread_rwlock_t *lock) {
    pthread_rwlock_unlock(lock);
}

static struct snd_kcontrol *snd_ctl_find_id(struct snd_card *card, struct snd_ctl_elem_id *id) {
    return NULL;
}

static unsigned int snd_ctl_get_ioff(struct snd_kcontrol *kctl, struct snd_ctl_elem_id *id) {
    return 0;
}

static void snd_ctl_build_ioff(struct snd_ctl_elem_id *id, struct snd_kcontrol *kctl, unsigned int index_offset) {
}

static void snd_ctl_notify(struct snd_card *card, int mask, struct snd_ctl_elem_id *id) {
}