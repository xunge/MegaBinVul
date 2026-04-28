#include <stdlib.h>
#include <string.h>

struct device {
    int dummy;
};

struct urb {
    int interval;
};

struct usb_serial {
    struct device *dev;
};

struct usb_serial_port {
    struct usb_serial *serial;
    struct urb *interrupt_out_urb;
    struct urb *interrupt_in_urb;
    int interrupt_out_size;
    struct device dev;
    struct {
        int drain_delay;
    } port;
};

struct cypress_private {
    int comm_is_ok;
    void *lock;
    void *write_fifo;
    unsigned int cmd_ctrl;
    unsigned int line_control;
    unsigned int termios_initialized;
    unsigned int rx_flags;
    int pkt_fmt;
    int write_urb_interval;
    int read_urb_interval;
};

#define CYPRESS_BUF_SIZE 1024
#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12

static int interval;
static int packet_format_1;
static int packet_format_2;

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void spin_lock_init(void *lock) {}
static int kfifo_alloc(void *fifo, int size, int flags) { return 0; }
static int is_frwd(struct device *dev) { return 0; }
static void usb_reset_configuration(struct device *dev) {}
static void usb_set_serial_port_data(struct usb_serial_port *port, void *data) {}
static void dev_err(struct device *dev, const char *fmt, ...) {}
static void dev_dbg(struct device *dev, const char *fmt, ...) {}