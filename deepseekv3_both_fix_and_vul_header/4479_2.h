#include <stdlib.h>
#include <string.h>

struct urb {
    void *context;
};

struct usb_serial_port {
    struct usb_serial *serial;
    int dev;
    struct urb *interrupt_in_urb;
};

struct usb_serial {
    struct usb_serial_port *port[2];
};

struct mct_u232_private {
    struct urb *read_urb;
    int lock;
};

#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void spin_lock_init(int *lock) {}
static inline void usb_set_serial_port_data(struct usb_serial_port *port, void *data) {}
static inline void dev_err(int *dev, const char *msg) {}