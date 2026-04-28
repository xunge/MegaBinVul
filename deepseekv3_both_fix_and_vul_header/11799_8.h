#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define SNDRV_CARDS 8
#define ENXIO 6
#define EIO 5
#define ENOENT 2
#define ENODEV 19
#define QUIRK_NO_INTERFACE (-1)

typedef uint32_t u32;

struct device {
    void *driver_data;
};

struct usb_interface {
    struct usb_host_interface *altsetting;
};

struct usb_device {
    struct {
        uint16_t idVendor;
        uint16_t idProduct;
    } descriptor;
    struct device dev;
};

struct usb_device_id {
    void *driver_info;
};

struct snd_usb_audio_quirk {
    int ifnum;
};

struct snd_usb_audio {
    struct usb_device *dev;
    atomic_int shutdown;
    atomic_int active;
    int index;
    int num_interfaces;
    void *card;
    struct usb_host_interface *ctrl_intf;
    struct usb_interface *pm_intf;
    int txfr_quirk;
};

struct usb_host_interface {
    int bInterfaceNumber;
};

struct usb_audio_driver {
    int dummy;
};

static atomic_int register_mutex;
static struct snd_usb_audio *usb_chip[SNDRV_CARDS];
static int vid[SNDRV_CARDS] = { [0 ... SNDRV_CARDS-1] = -1 };
static int pid[SNDRV_CARDS] = { [0 ... SNDRV_CARDS-1] = -1 };
static bool enable[SNDRV_CARDS] = { [0 ... SNDRV_CARDS-1] = true };
static bool ignore_ctl_error;
static struct usb_audio_driver usb_audio_driver;

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline u32 USB_ID(uint16_t vendor, uint16_t product) { return (vendor << 16) | product; }
static inline uint16_t USB_ID_VENDOR(u32 id) { return id >> 16; }
static inline uint16_t USB_ID_PRODUCT(u32 id) { return id & 0xFFFF; }

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline struct usb_host_interface *get_iface_desc(struct usb_host_interface *alts) { return alts; }
static inline int get_alias_id(struct usb_device *dev, u32 *id) { return 0; }
static inline void *get_alias_quirk(struct usb_device *dev, u32 id) { return NULL; }
static inline int snd_usb_apply_boot_quirk(struct usb_device *dev, struct usb_interface *intf, 
                                         const struct snd_usb_audio_quirk *quirk, u32 id) { return 0; }
static inline void mutex_lock(atomic_int *mutex) {}
static inline void mutex_unlock(atomic_int *mutex) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_set_drvdata(struct device *dev, void *data) {}
static inline int snd_usb_audio_create(struct usb_interface *intf, struct usb_device *dev, 
                                      int i, const struct snd_usb_audio_quirk *quirk, 
                                      u32 id, struct snd_usb_audio **chip) { return 0; }
static inline int snd_usb_create_quirk(struct snd_usb_audio *chip, struct usb_interface *intf, 
                                      struct usb_audio_driver *driver, 
                                      const struct snd_usb_audio_quirk *quirk) { return 0; }
static inline int snd_usb_create_streams(struct snd_usb_audio *chip, int ifnum) { return 0; }
static inline int snd_usb_create_mixer(struct snd_usb_audio *chip, int ifnum, bool ignore_ctl_error) { return 0; }
static inline int snd_card_register(void *card) { return 0; }
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void snd_card_free(void *card) {}
static inline int atomic_read(const atomic_int *v) { return *v; }
static inline void atomic_inc(atomic_int *v) { (*v)++; }
static inline void atomic_dec(atomic_int *v) { (*v)--; }