#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MIDI_MAX_ENDPOINTS 2
#define GFP_KERNEL 0
#define ENOMEM (-1)
#define ENXIO (-2)

enum {
    QUIRK_MIDI_STANDARD_INTERFACE,
    QUIRK_MIDI_US122L,
    QUIRK_MIDI_FIXED_ENDPOINT,
    QUIRK_MIDI_YAMAHA,
    QUIRK_MIDI_ROLAND,
    QUIRK_MIDI_MIDIMAN,
    QUIRK_MIDI_NOVATION,
    QUIRK_MIDI_RAW_BYTES,
    QUIRK_MIDI_EMAGIC,
    QUIRK_MIDI_CME,
    QUIRK_MIDI_AKAI,
    QUIRK_MIDI_FTDI,
    QUIRK_MIDI_CH345
};

struct snd_card;
struct usb_interface;
struct usb_device {
    struct {
        uint16_t idVendor;
        uint16_t idProduct;
    } descriptor;
    struct {
        int dev;
    } dev;
};

struct list_head {
    struct list_head *next, *prev;
};

struct snd_usb_audio_quirk {
    int type;
    void *data;
};

struct snd_usb_midi_endpoint_info {
    uint16_t out_cables;
    uint16_t in_cables;
};

struct snd_usb_midi_protocol_ops {
    // protocol operations
};

struct snd_usb_midi {
    struct usb_device *dev;
    struct snd_card *card;
    struct usb_interface *iface;
    const struct snd_usb_audio_quirk *quirk;
    const struct snd_usb_midi_protocol_ops *usb_protocol_ops;
    int disc_lock;
    int disc_rwsem;
    int mutex;
    unsigned int usb_id;
    int error_timer;
    struct list_head list;
};

extern const struct snd_usb_midi_protocol_ops snd_usbmidi_standard_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_maudio_broken_running_status_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_122l_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_midiman_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_novation_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_raw_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_emagic_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_cme_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_akai_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_ftdi_ops;
extern const struct snd_usb_midi_protocol_ops snd_usbmidi_ch345_broken_sysex_ops;

#define USB_ID(vendor, product) (((vendor) << 16) | (product))

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void spin_lock_init(int *lock) {}
static inline void init_rwsem(int *sem) {}
static inline void mutex_init(int *mutex) {}
static inline void setup_timer(int *timer, void (*func)(unsigned long), unsigned long data) {}
static inline int hweight16(uint16_t w) { return __builtin_popcount(w); }
static inline struct usb_device *interface_to_usbdev(struct usb_interface *iface) { return (struct usb_device *)iface; }
static inline void usb_set_interface(struct usb_device *dev, int ifnum, int alt) {}
static inline int usb_control_msg(struct usb_device *dev, int pipe, uint8_t request, uint8_t requesttype, uint16_t value, uint16_t index, void *data, uint16_t size, int timeout) { return 0; }
static inline int usb_sndctrlpipe(struct usb_device *dev, int endpoint) { return 0; }
static inline void dev_err(void *dev, const char *fmt, ...) {}
static inline void usb_autopm_get_interface_no_resume(struct usb_interface *iface) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}

void snd_usbmidi_error_timer(unsigned long data) {}
int snd_usbmidi_get_ms_info(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoints) { return 0; }
int snd_usbmidi_detect_endpoints(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoint, int num_endpoints) { return 0; }
int snd_usbmidi_detect_yamaha(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoint) { return 0; }
int snd_usbmidi_detect_roland(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoint) { return 0; }
int snd_usbmidi_detect_per_port_endpoints(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoints) { return 0; }
int snd_usbmidi_create_rawmidi(struct snd_usb_midi *umidi, int out_ports, int in_ports) { return 0; }
int snd_usbmidi_create_endpoints_midiman(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoint) { return 0; }
int snd_usbmidi_create_endpoints(struct snd_usb_midi *umidi, struct snd_usb_midi_endpoint_info *endpoints) { return 0; }
void snd_usbmidi_free(struct snd_usb_midi *umidi) {}