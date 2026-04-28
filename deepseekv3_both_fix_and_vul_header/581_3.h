#include <string.h>
#include <stdio.h>
#include <errno.h>

struct line6_properties {
    const char *id;
    const char *name;
    int capabilities;
    int altsetting;
};

struct usb_device {
    struct {
        unsigned char bNumConfigurations;
    } descriptor;
};

struct usb_interface {
    struct {
        struct {
            unsigned char bInterfaceNumber;
        } desc;
    } *cur_altsetting;
    void *dev;
};

struct usb_device_id;

struct snd_card {
    char id[32];
    char driver[32];
    char shortname[32];
    char longname[80];
    void *private_data;
    void (*private_free)(struct snd_card *);
};

struct work_struct {
    void *data;
    void (*func)(void *);
};

struct usb_line6 {
    struct snd_card *card;
    const struct line6_properties *properties;
    struct usb_device *usbdev;
    void *ifcdev;
    struct work_struct startup_work;
};

#define LINE6_CAP_CONTROL 0x01
#define WARN_ON(condition) (condition)
#define THIS_MODULE NULL
#define SNDRV_DEFAULT_IDX1 0
#define SNDRV_DEFAULT_STR1 "default"
#define EINVAL 22
#define ENODEV 19

int snd_card_new(void *dev, int idx, const char *xid, void *module, size_t size, struct snd_card **card);
void usb_set_intfdata(struct usb_interface *interface, struct usb_line6 *line6);
void usb_get_dev(struct usb_device *usbdev);
int usb_set_interface(struct usb_device *usbdev, int interface_number, int altsetting);
struct usb_device *interface_to_usbdev(struct usb_interface *interface);
const char *dev_name(void *dev);
void dev_info(void *dev, const char *fmt, ...);
void dev_err(void *dev, const char *fmt, ...);
void INIT_DELAYED_WORK(void *work, void *func);
void line6_startup_work(struct work_struct *work);
void line6_destruct(struct snd_card *card);
void line6_disconnect(struct usb_interface *interface);
int line6_init_cap_control(struct usb_line6 *line6);
void line6_get_usb_properties(struct usb_line6 *line6);