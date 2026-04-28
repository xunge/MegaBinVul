#include <stddef.h>

struct usb_interface;
struct dvb_usb_device {
    struct {
        const char *name;
    } *desc;
};

void *usb_get_intfdata(struct usb_interface *intf);
void usb_set_intfdata(struct usb_interface *intf, void *data);
void dvb_usb_exit(struct dvb_usb_device *d);
void info(const char *fmt, ...);