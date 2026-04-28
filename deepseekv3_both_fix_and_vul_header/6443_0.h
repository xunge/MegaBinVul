#include <stdint.h>

#define ENXIO 6

struct snd_pcm_substream;

#define SNDRV_PCM_IOCTL1_INFO 0
#define SNDRV_PCM_IOCTL1_RESET 1
#define SNDRV_PCM_IOCTL1_CHANNEL_INFO 2
#define SNDRV_PCM_IOCTL1_FIFO_SIZE 3

int snd_pcm_lib_ioctl_reset(struct snd_pcm_substream *substream, void *arg);
int snd_pcm_lib_ioctl_channel_info(struct snd_pcm_substream *substream, void *arg);
int snd_pcm_lib_ioctl_fifo_size(struct snd_pcm_substream *substream, void *arg);