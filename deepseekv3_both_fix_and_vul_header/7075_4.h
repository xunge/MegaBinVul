#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct rw_semaphore {
    int dummy;
};

struct snd_ctl_elem_value {
    char data[128];
};

struct snd_card {
    struct rw_semaphore controls_rwsem;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define EFAULT 14
#define SNDRV_CTL_POWER_D0 0
#define __user

void down_read(struct rw_semaphore *sem) {}
void up_read(struct rw_semaphore *sem) {}

static void *memdup_user(const void *src, size_t len) { return malloc(len); }
static void snd_power_lock(struct snd_card *card) {}
static int snd_power_wait(struct snd_card *card, int state) { return 0; }
static void snd_power_unlock(struct snd_card *card) {}
static int snd_ctl_elem_read(struct snd_card *card, struct snd_ctl_elem_value *control) { return 0; }
static int copy_to_user(void *dst, const void *src, size_t len) { return 0; }
#define kfree free