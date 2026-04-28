#include <pthread.h>
#include <errno.h>

struct snd_ctl_elem_id {
    int dummy;
};

struct snd_kcontrol_volatile {
    unsigned int access;
    int dummy;
};

struct snd_kcontrol {
    struct snd_kcontrol_volatile *vd;
    int (*get)(struct snd_kcontrol *, struct snd_ctl_elem_value *);
    int dummy;
};

struct snd_card {
    pthread_rwlock_t controls_rwsem;
};

struct snd_ctl_elem_value {
    struct snd_ctl_elem_id id;
};

#define SNDRV_CTL_ELEM_ACCESS_READ 0x00000001
#define ENOENT 2
#define EPERM 1

static void down_read(pthread_rwlock_t *lock) {
    pthread_rwlock_rdlock(lock);
}

static void up_read(pthread_rwlock_t *lock) {
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