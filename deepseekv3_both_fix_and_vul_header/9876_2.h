#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CHANNELS_PER_STREAM 2
#define MAX_STREAMS 32
#define MAX_BUFFER_SIZE (64 * 1024)
#define N_URBS 4

struct snd_pcm_hardware {
    int rates;
};

struct snd_pcm_ops {
};

struct snd_pcm {
    void *private_data;
    char name[64];
};

struct snd_card {
};

struct snd_usb_caiaq_cb_info {
    struct snd_usb_caiaqdev *dev;
    int index;
};

struct snd_usb_caiaqdev {
    int n_audio_in;
    int n_audio_out;
    int n_streams;
    struct {
        int num_analog_audio_in;
        int num_digital_audio_in;
        int num_analog_audio_out;
        int num_digital_audio_out;
    } spec;
    struct {
        struct snd_card *card;
        int usb_id;
    } chip;
    char product_name[64];
    struct snd_pcm *pcm;
    void *sub_playback;
    void *sub_capture;
    struct snd_pcm_hardware pcm_info;
    int samplerates;
    struct snd_usb_caiaq_cb_info *data_cb_info;
    void *data_urbs_in;
    void *data_urbs_out;
};

extern struct snd_pcm_hardware snd_usb_caiaq_pcm_hardware;
extern struct snd_pcm_ops snd_usb_caiaq_ops;

#define USB_ID(vendor, product) (((vendor) << 16) | (product))
#define USB_VID_NATIVEINSTRUMENTS 0x17cc
#define USB_PID_AK1 0x0815
#define USB_PID_RIGKONTROL3 0x1915
#define USB_PID_SESSIONIO 0x1917
#define USB_PID_GUITARRIGMOBILE 0x0d8d
#define USB_PID_AUDIO2DJ 0x0415
#define USB_PID_AUDIO4DJ 0x0715
#define USB_PID_AUDIO8DJ 0x0f15

#define SNDRV_PCM_RATE_192000 (1<<12)
#define SNDRV_PCM_RATE_88200 (1<<7)
#define SNDRV_PCM_STREAM_PLAYBACK 0
#define SNDRV_PCM_STREAM_CAPTURE 1
#define SNDRV_DMA_TYPE_CONTINUOUS 1

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

static inline void debug(const char *fmt, ...) {}
static inline void log(const char *fmt, ...) {}
static inline int snd_pcm_new(struct snd_card *card, const char *name, int idx,
                             int playback_count, int capture_count, struct snd_pcm **rpcm) { return 0; }
static inline void snd_pcm_set_ops(struct snd_pcm *pcm, int direction, struct snd_pcm_ops *ops) {}
static inline void snd_pcm_lib_preallocate_pages_for_all(struct snd_pcm *pcm, int type, void *data, size_t size, size_t max) {}
static inline void *alloc_urbs(struct snd_usb_caiaqdev *dev, int direction, int *ret) { return NULL; }
static inline void free_urbs(void *urbs) {}
static inline void *snd_dma_continuous_data(int flags) { return NULL; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int max(int a, int b) { return a > b ? a : b; }