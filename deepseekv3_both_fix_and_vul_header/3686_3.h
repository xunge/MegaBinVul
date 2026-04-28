#include <stddef.h>
#include <sys/types.h>

#define EFAULT 14
#define EINVAL 22
#define ENOENT 2
#define ENXIO 6
#define EPERM 1
#define ENOMEM 12

struct snd_ctl_file {
    struct snd_card *card;
};

struct snd_ctl_tlv {
    unsigned int numid;
    unsigned int length;
    unsigned int *tlv;
};

struct snd_kcontrol_volatile {
    unsigned int access;
    void *owner;
};

struct snd_ctl_elem_id {
    unsigned int numid;
};

struct snd_kcontrol {
    struct snd_ctl_elem_id id;
    struct {
        int (*c)(struct snd_kcontrol *, int, unsigned int, unsigned int *);
        unsigned int *p;
    } tlv;
    struct snd_kcontrol_volatile *vd;
};

struct snd_card {
    void *controls_rwsem;
};

#define SNDRV_CTL_ELEM_ACCESS_TLV_READ (1 << 0)
#define SNDRV_CTL_ELEM_ACCESS_TLV_WRITE (1 << 1)
#define SNDRV_CTL_ELEM_ACCESS_TLV_COMMAND (1 << 2)
#define SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK (1 << 3)

#define SNDRV_CTL_EVENT_MASK_TLV (1 << 0)

static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}

static struct snd_kcontrol *snd_ctl_find_numid(struct snd_card *card, unsigned int numid) { return NULL; }
static void snd_ctl_notify(struct snd_card *card, int mask, struct snd_ctl_elem_id *id) {}

#define __user