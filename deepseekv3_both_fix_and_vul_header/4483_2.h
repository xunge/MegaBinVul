#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12

struct device {
    const char *name;
};

struct usb_serial_port {
    void *read_urb;
    void *write_urb;
};

struct usb_serial_type {
    int num_ports;
};

struct usb_serial_interface {
    struct device dev;
};

struct usb_serial {
    struct usb_serial_type *type;
    struct usb_serial_port **port;
    struct usb_serial_interface *interface;
    int num_port_pointers;
};

struct digi_serial {
    void *ds_serial_lock;
    int ds_oob_port_num;
    struct usb_serial_port *ds_oob_port;
};

static inline void spin_lock_init(void *lock) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline int digi_port_init(struct usb_serial_port *port, int num) { return 0; }
static inline void usb_set_serial_data(struct usb_serial *serial, void *data) {}