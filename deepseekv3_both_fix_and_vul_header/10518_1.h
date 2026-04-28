#include <stddef.h>

struct tty_struct;
struct usb_serial_port;
struct usb_serial {
    struct usb_serial_port *port[2];
};

struct usb_serial_port {
    struct usb_serial *serial;
    struct {
        int dummy;
    } port;
};

void tty_port_tty_set(void *port, struct tty_struct *tty);
int usb_serial_generic_open(struct tty_struct *tty, struct usb_serial_port *port);