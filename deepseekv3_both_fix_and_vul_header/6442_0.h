#include <string.h>
#include <stddef.h>

struct snd_pcm_substream;
struct snd_pcm_info;
struct snd_pcm_runtime;
struct snd_pcm;
struct snd_pcm_str;

struct snd_pcm_info {
    int card;
    int device;
    int stream;
    int subdevice;
    char id[64];
    char name[80];
    int dev_class;
    int dev_subclass;
    int subdevices_count;
    int subdevices_avail;
    char subname[32];
    int sync;
};

struct snd_pcm_substream {
    struct snd_pcm *pcm;
    struct snd_pcm_str *pstr;
    int stream;
    int number;
    char name[32];
    struct snd_pcm_runtime *runtime;
    struct {
        int (*ioctl)(struct snd_pcm_substream *, int, struct snd_pcm_info *);
    } *ops;
};

struct snd_pcm {
    struct {
        int number;
    } *card;
    int device;
    char id[64];
    char name[80];
    int dev_class;
    int dev_subclass;
};

struct snd_pcm_str {
    int substream_count;
    int substream_opened;
};

struct snd_pcm_runtime {
    int sync;
};

#define SNDRV_PCM_IOCTL1_INFO 0