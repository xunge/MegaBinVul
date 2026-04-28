#include <stddef.h>

struct usb_device;
struct usb_interface;
struct usb_host_interface {
    struct {
        int bInterfaceNumber;
        int bAlternateSetting;
    } desc;
};
struct usb_interface {
    struct usb_host_interface *altsetting;
};

#define ENODEV 19

extern struct usb_host_interface *uas_find_uas_alt_setting(struct usb_interface *intf);
extern int usb_set_interface(struct usb_device *udev, int interface, int alternate);