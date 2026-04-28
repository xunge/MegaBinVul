#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define EM28XX_MAXBOARDS 4
#define PRIMARY_TS 0
#define SECONDARY_TS 1
#define EM28XX_USB_AUDIO_VENDOR 0
#define EM28XX_USB_AUDIO_CLASS 1
#define EM28XX_NODECODER 0
#define EM28XX_NOSENSOR 0
#define ENOMEM 12
#define ENODEV 19
#define GFP_KERNEL 0
#define USB_CLASS_AUDIO 1
#define USB_SPEED_UNKNOWN 0
#define USB_SPEED_LOW 1
#define USB_SPEED_FULL 2
#define USB_SPEED_HIGH 3
#define TUNER_ABSENT 0

struct usb_interface;
struct usb_device;
struct usb_device_id;

struct usb_interface {
    struct {
        struct {
            int bInterfaceNumber;
            int bInterfaceClass;
            int bNumEndpoints;
        } desc;
    } *altsetting;
    int num_altsetting;
    void *dev;
};

struct usb_device {
    struct {
        uint16_t idVendor;
        uint16_t idProduct;
    } descriptor;
    char *manufacturer;
    char *product;
    int speed;
    struct {
        struct {
            int bNumInterfaces;
        } desc;
        struct usb_interface **interface;
    } *config;
};

struct usb_device_id {
    int driver_info;
};

struct mutex {
    int dummy;
};

struct kref {
    int count;
};

struct em28xx {
    int devno;
    int model;
    int alt;
    bool is_audio_only;
    bool has_video;
    int ifnum;
    int ts;
    char name[28];
    struct em28xx *dev_next;
    int usb_audio_type;
    int num_alt;
    unsigned int *alt_max_pkt_size_isoc;
    unsigned int *dvb_max_pkt_size_isoc;
    bool analog_xfer_bulk;
    bool dvb_xfer_bulk;
    struct {
        int decoder;
        bool has_dual_ts;
        bool has_ir_i2c;
        char *ir_codes;
    } board;
    int em28xx_sensor;
    int tuner_type;
    struct usb_interface *intf;
    bool is_webcam;
    bool analog_ep_bulk;
    bool analog_ep_isoc;
    bool dvb_ep_bulk;
    bool dvb_ep_isoc;
    bool dvb_ep_bulk_ts2;
    bool dvb_ep_isoc_ts2;
    int dvb_max_pkt_size_isoc_ts2;
    int dvb_alt_isoc;
    struct {
        int type;
    } *input[1];
    struct mutex lock;
    struct kref ref;
};

static unsigned long em28xx_devused[EM28XX_MAXBOARDS];
static int em28xx_bcount;
static int card[EM28XX_MAXBOARDS];
static int disable_usb_speed_check;
static int usb_xfer_mode;

static inline int test_and_set_bit(int nr, unsigned long *addr) {
    int oldbit = (addr[nr / (sizeof(long)*8)] >> (nr % (sizeof(long)*8))) & 1;
    addr[nr / (sizeof(long)*8)] |= 1UL << (nr % (sizeof(long)*8));
    return oldbit;
}

static inline int find_first_zero_bit(const unsigned long *addr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (!((addr[i / (sizeof(long)*8)] >> (i % (sizeof(long)*8))) & 1))
            return i;
    }
    return size;
}

static inline void clear_bit(int nr, unsigned long *addr) {
    addr[nr / (sizeof(long)*8)] &= ~(1UL << (nr % (sizeof(long)*8)));
}

static inline uint16_t le16_to_cpu(uint16_t val) {
    return val;
}

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void kfree(void *ptr) {
    free(ptr);
}

static void dev_err(void *dev, const char *fmt, ...) {}
static void dev_info(void *dev, const char *fmt, ...) {}

static struct usb_device *interface_to_usbdev(struct usb_interface *intf) {
    return NULL;
}

static struct usb_device *usb_get_dev(struct usb_device *udev) {
    return udev;
}

static void usb_put_dev(struct usb_device *udev) {}

static void usb_set_intfdata(struct usb_interface *intf, void *data) {}

static void mutex_init(struct mutex *lock) {
    lock->dummy = 0;
}

static void kref_init(struct kref *ref) {
    ref->count = 1;
}

static int em28xx_init_dev(struct em28xx *dev, struct usb_device *udev,
              struct usb_interface *intf, int nr) { return 0; }

static int em28xx_duplicate_dev(struct em28xx *dev) { return 0; }

static void em28xx_check_usb_descriptor(struct em28xx *dev,
                    struct usb_device *udev,
                    struct usb_interface *intf,
                    int i, int ep,
                    bool *has_vendor_audio,
                    bool *has_video,
                    bool *has_dvb) {}

static void em28xx_write_reg(struct em28xx *dev, int reg, int val) {}

static void request_modules(struct em28xx *dev) {}

static void mdelay(unsigned int msec) {
    usleep(msec * 1000);
}

#define INPUT(n) (dev->input[n])