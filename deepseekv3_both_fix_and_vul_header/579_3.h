#include <stdlib.h>
#include <string.h>

#define LINE6_CAP_PCM 0x01
#define LINE6_IMPULSE_DEFAULT_PERIOD 0
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

struct line6_pcm_properties {
    unsigned int ep_audio_r;
    unsigned int ep_audio_w;
    unsigned int capabilities;
};

struct snd_pcm {
    void *private_data;
    void (*private_free)(struct snd_pcm *pcm);
};

struct device;

struct usb_line6 {
    struct line6_pcm_properties *properties;
    void *usbdev;
    void *ifcdev;
    void *card;
    void *line6pcm;
};

struct snd_line6_pcm {
    struct snd_pcm *pcm;
    struct line6_pcm_properties *properties;
    unsigned int volume_playback[2];
    unsigned int volume_monitor;
    struct usb_line6 *line6;
    unsigned int max_packet_size_in;
    unsigned int max_packet_size_out;
    struct {
        int lock;
    } out, in;
    unsigned int impulse_period;
    int state_mutex;
};

struct line6_control {
    int dummy;
};

static struct line6_control line6_controls[1];

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

extern int snd_line6_new_pcm(struct usb_line6 *line6, struct snd_pcm **pcm);
extern int line6_create_audio_out_urbs(struct snd_line6_pcm *line6pcm);
extern int line6_create_audio_in_urbs(struct snd_line6_pcm *line6pcm);
extern void line6_cleanup_pcm(struct snd_pcm *pcm);
extern void *kzalloc(size_t size, int flags);
extern void mutex_init(int *mutex);
extern void spin_lock_init(int *lock);
extern int usb_maxpacket(void *dev, int pipe, int is_out);
extern int usb_rcvisocpipe(void *dev, int ep);
extern int usb_sndisocpipe(void *dev, int ep);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern int snd_ctl_add(void *card, void *control);
extern void *snd_ctl_new1(struct line6_control *control, struct snd_line6_pcm *line6pcm);