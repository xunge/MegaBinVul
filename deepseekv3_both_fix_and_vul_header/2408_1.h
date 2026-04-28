struct usb_serial {
    void *port[1];
};

struct usb_serial_port;

struct usbcons_info {
    struct usb_serial_port *port;
};
extern struct usbcons_info usbcons_info;

void usb_serial_console_exit(void);
void usb_serial_put(struct usb_serial *serial);