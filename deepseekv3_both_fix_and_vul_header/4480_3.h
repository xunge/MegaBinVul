#include <stdbool.h>
#include <stddef.h>

struct tty_struct;
struct device;

struct urb {
    void *transfer_buffer;
    size_t transfer_buffer_length;
};

struct usb_serial_port {
    struct usb_serial *serial;
    struct urb *interrupt_in_urb;
    unsigned int interrupt_in_endpointAddress;
    struct device *dev;
};

struct usb_serial {
    struct device *dev;
};

struct cypress_private {
    bool comm_is_ok;
    unsigned long lock;
    unsigned long bytes_in;
    unsigned long bytes_out;
    unsigned int cmd_count;
    unsigned int rx_flags;
    struct {
        int dummy;
    } tmp_termios;
    unsigned int read_urb_interval;
};

#define GFP_KERNEL 0
#define EIO 5

static inline void *usb_get_serial_port_data(struct usb_serial_port *port) { return NULL; }
static inline void usb_clear_halt(struct device *dev, int endpoint) {}
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void cypress_send(struct usb_serial_port *port) {}
static inline void cypress_set_termios(struct tty_struct *tty, struct usb_serial_port *port, void *termios) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void usb_fill_int_urb(struct urb *urb, struct device *dev, int pipe,
                                  void *buffer, size_t length,
                                  void (*callback)(struct urb *), void *context,
                                  int interval) {}
static inline int usb_rcvintpipe(struct device *dev, unsigned int endpoint) { return 0; }
static inline int usb_submit_urb(struct urb *urb, int flags) { return 0; }
static inline void cypress_read_int_callback(struct urb *urb) {}
static inline void cypress_set_dead(struct usb_serial_port *port) {}