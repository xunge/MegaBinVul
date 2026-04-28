#include <stddef.h>

struct usb_interface {
    struct {
        void *extra;
        size_t extralen;
    } *altsetting;
    struct {
        int dev;
    } dev;
};

struct usb_cdc_union_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
    unsigned short bControlInterface;
    unsigned short bSubordinateInterface0;
};

#define USB_DT_CS_INTERFACE 0x24
#define USB_CDC_UNION_TYPE 0x06

void dev_err(struct usb_interface *intf, const char *format, ...);
void dev_dbg(struct usb_interface *intf, const char *format, ...);