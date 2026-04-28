#include <stdint.h>
#include <stdio.h>

#define CONFIG_USB_OTG 1
#define USB_DT_OTG 9
#define USB_REQ_SET_FEATURE 3
#define USB_DEVICE_B_HNP_ENABLE 3
#define USB_DEVICE_A_ALT_HNP_SUPPORT 4
#define USB_CTRL_SET_TIMEOUT 5000
#define USB_OTG_HNP 1

typedef uint16_t __le16;
typedef uint8_t __u8;
typedef uint16_t __u16;

struct device {
};

struct usb_descriptor_header {
    __le16 wTotalLength;
};

struct usb_config_descriptor {
    struct usb_descriptor_header desc;
};

struct usb_bus {
    int is_b_host;
    struct usb_device *root_hub;
    unsigned otg_port;
    int b_hnp_enable;
};

struct usb_device {
    struct usb_bus *bus;
    struct device dev;
    unsigned portnum;
    unsigned char *rawdescriptors[1];
    struct usb_config_descriptor *config;
    struct usb_device *parent;
};

struct usb_otg_descriptor {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bmAttributes;
};

static inline __le16 le16_to_cpu(__le16 val) { return val; }
static int __usb_get_extra_descriptor(unsigned char *buffer, unsigned size, unsigned type, void **ptr, ...) { return 0; }
static int usb_control_msg(struct usb_device *dev, unsigned int pipe, __u8 request, __u8 requesttype, __u16 value, __u16 index, void *data, __u16 size, int timeout) { return 0; }
static int usb_sndctrlpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static void dev_info(struct device *dev, const char *fmt, ...) {}
static void dev_err(struct device *dev, const char *fmt, ...) {}