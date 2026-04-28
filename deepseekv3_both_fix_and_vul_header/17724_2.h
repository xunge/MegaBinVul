#include <stdlib.h>
#include <string.h>

#define SNDRV_CARDS 4
#define ENODEV 19
#define ENOENT 2
#define ENOMEM 12
#define GFP_KERNEL 0
#define SNDRV_DEV_LOWLEVEL 1
#define SNDRV_PCM_STREAM_CAPTURE 0

struct go7007 {
    void *dev;
    char *name;
    void *snd_context;
    struct {
        void *v4l2_dev;
    } v4l2_dev;
};

struct snd_card {
    char driver[32];
    char shortname[32];
    char longname[80];
};

struct snd_pcm {
    void *private_data;
};

struct go7007_snd {
    void *lock;
    unsigned int hw_ptr;
    unsigned int w_idx;
    unsigned int avail;
    int capturing;
    struct snd_card *card;
    struct snd_pcm *pcm;
    void *substream;
};

struct snd_device_ops {
    int dummy;
};

struct snd_pcm_ops {
    int dummy;
};

static int dev_index[SNDRV_CARDS];
static int enable[SNDRV_CARDS];
static char *card_id[SNDRV_CARDS];
static struct snd_device_ops go7007_snd_device_ops;
static struct snd_pcm_ops go7007_snd_capture_ops;

#define THIS_MODULE NULL
#define spin_lock_init(lock) ((void)0)
#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)
#define snd_card_new(dev, idx, id, module, size, card) (-1)
#define snd_device_new(card, type, dev, ops) (-1)
#define snd_pcm_new(card, name, idx1, idx2, streams, pcm) (-1)
#define strscpy(dest, src, size) strncpy(dest, src, size)
#define snd_pcm_set_ops(pcm, stream, ops) ((void)0)
#define snd_card_register(card) (-1)
#define snd_card_free(card) ((void)0)
#define v4l2_device_get(dev) ((void)0)