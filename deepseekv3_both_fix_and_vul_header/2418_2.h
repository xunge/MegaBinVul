#include <stdbool.h>
#include <stddef.h>

struct usb_interface_descriptor {
    int bAlternateSetting;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
};

struct usb_interface {
    struct usb_host_interface *altsetting;
    int num_altsetting;
};

#define ENODEV 19

static bool uas_is_interface(struct usb_host_interface *alt);