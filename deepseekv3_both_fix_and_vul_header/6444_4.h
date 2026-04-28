#include <errno.h>
#include <sys/ioctl.h>
#include <stddef.h>

#define SNDRV_CTL_IOCTL_PCM_NEXT_DEVICE 1
#define SNDRV_CTL_IOCTL_PCM_INFO 2
#define SNDRV_CTL_IOCTL_PCM_PREFER_SUBDEVICE 3
#define SND_CTL_SUBDEV_PCM 0
#define ENOIOCTLCMD 515

#define __user

struct mutex {
    int dummy;
};

struct snd_pcm_substream {
    int number;
    struct snd_pcm_substream *next;
};

struct snd_pcm_str {
    unsigned int substream_count;
    struct snd_pcm_substream *substream;
};

struct snd_pcm {
    struct mutex open_mutex;
    struct snd_pcm_str streams[2];
};

struct snd_card;
struct snd_ctl_file {
    int preferred_subdevice[1];
};

struct snd_pcm_info {
    int device;
    int stream;
    unsigned int subdevice;
};

extern struct mutex register_mutex;

static inline int get_user(int val, int *ptr) { return 0; }
static inline int put_user(int val, int *ptr) { return 0; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

extern int snd_pcm_next(struct snd_card *card, int device);
extern struct snd_pcm *snd_pcm_get(struct snd_card *card, unsigned int device);
extern int snd_pcm_info_user(struct snd_pcm_substream *substream, struct snd_pcm_info *info);