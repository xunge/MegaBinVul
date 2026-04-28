#include <stdint.h>
#include <stddef.h>

#define UAC_HEADER 1
#define UAC_VERSION_1 0x00
#define UAC_VERSION_2 0x20
#define USB_CLASS_AUDIO 0x01
#define EINVAL 22

struct device;

struct usb_device {
    struct device *dev;
};

struct usb_interface_descriptor {
    uint8_t bInterfaceProtocol;
};

struct usb_host_interface {
    void *extra;
    int extralen;
    struct usb_interface_descriptor *desc;
};

struct usb_interface {
    struct usb_host_interface *altsetting;
    struct usb_interface_assoc_descriptor *intf_assoc;
};

struct usb_interface_assoc_descriptor {
    uint8_t bInterfaceCount;
    uint8_t bFirstInterface;
    uint8_t bFunctionClass;
    uint8_t bFunctionProtocol;
};

struct uac1_ac_header_descriptor {
    uint8_t bLength;
    uint8_t bInCollection;
    uint8_t baInterfaceNr[];
};

struct snd_usb_audio {
    struct usb_device *dev;
};

extern void dev_err(struct device *dev, const char *fmt, ...);
extern void dev_warn(struct device *dev, const char *fmt, ...);
extern void dev_info(struct device *dev, const char *fmt, ...);
extern struct usb_interface *usb_ifnum_to_if(struct usb_device *dev, unsigned ifnum);
extern void *snd_usb_find_csint_desc(void *buffer, int buflen, void *after, uint8_t descriptor);
extern struct usb_interface_descriptor *get_iface_desc(struct usb_host_interface *host_iface);
extern int snd_usb_create_stream(struct snd_usb_audio *chip, int ctrlif, int intf);