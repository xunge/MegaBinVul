#include <string.h>
#include <stdlib.h>

struct snd_ctl_elem_value {
    int dummy;
};

struct snd_card {
    void *card;
    void *controls_rwsem;
};

struct snd_ctl_file {
    struct snd_card *card;
};

#define __user
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define EFAULT 14
#define SNDRV_CTL_POWER_D0 0

static inline void *memdup_user(const void __user *src, size_t len) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline int copy_to_user(void __user *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
    return 0;
}

static inline void snd_power_lock(struct snd_card *card) {}
static inline int snd_power_wait(struct snd_card *card, int state) { return 0; }
static inline void snd_power_unlock(struct snd_card *card) {}
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline int snd_ctl_elem_write(struct snd_card *card, struct snd_ctl_file *file, struct snd_ctl_elem_value *control) { return 0; }
#define kfree free