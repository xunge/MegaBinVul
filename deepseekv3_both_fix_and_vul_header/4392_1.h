#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_NR_RATES 1024
#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define USB_DIR_IN 0x80
#define SNDRV_PCM_STREAM_CAPTURE 1
#define SNDRV_PCM_STREAM_PLAYBACK 0

typedef uint16_t __le16;

struct snd_usb_audio {
    void *dev;
};

struct snd_usb_audio_quirk {
    void *data;
};

struct audioformat {
    int nr_rates;
    unsigned *rate_table;
    int endpoint;
    int iface;
    int altset_idx;
    int protocol;
    int datainterval;
    int maxpacksize;
    int rate_max;
};

struct usb_host_interface {
    struct usb_interface_descriptor *desc;
    struct usb_endpoint_descriptor *endpoint;
    int extralen;
};

struct usb_interface_descriptor {
    unsigned char bInterfaceNumber;
    unsigned char bNumEndpoints;
    unsigned char bInterfaceProtocol;
};

struct usb_endpoint_descriptor {
    __le16 wMaxPacketSize;
};

struct usb_interface {
    struct usb_host_interface *altsetting;
    int num_altsetting;
};

struct usb_driver;

static inline struct usb_interface_descriptor *get_iface_desc(struct usb_host_interface *alts)
{
    return alts->desc;
}

static inline struct usb_endpoint_descriptor *get_endpoint(struct usb_host_interface *alts, int idx)
{
    return &alts->endpoint[idx];
}

static inline void *kmemdup(const void *src, size_t len, int gfp)
{
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline void kfree(const void *objp)
{
    free((void*)objp);
}

static inline void usb_audio_err(struct snd_usb_audio *chip, const char *fmt, ...) {}

static inline int snd_usb_add_audio_stream(struct snd_usb_audio *chip, int stream, struct audioformat *fp)
{
    return 0;
}

static inline unsigned int snd_usb_parse_datainterval(struct snd_usb_audio *chip, struct usb_host_interface *alts)
{
    return 0;
}

static inline void snd_usb_init_pitch(struct snd_usb_audio *chip, int iface, struct usb_host_interface *alts, struct audioformat *fp) {}

static inline void snd_usb_init_sample_rate(struct snd_usb_audio *chip, int iface, struct usb_host_interface *alts, struct audioformat *fp, int rate) {}

static inline int usb_set_interface(void *dev, int iface, int alternate)
{
    return 0;
}

static inline uint16_t le16_to_cpu(uint16_t val)
{
    return val;
}