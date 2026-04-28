#include <stdint.h>
#include <stddef.h>

struct device {
    // Minimal device structure definition
    const char *name;
};

struct urb {
    void *context;
    unsigned char *transfer_buffer;
    int status;
    int actual_length;
    struct {
        struct device *dev;
    } *dev;
};

struct usb_serial_port {
    struct device dev;
    int port_number;
    struct {
        unsigned int rx;
    } icount;
};

struct edgeport_port {
    struct usb_serial_port *port;
    int lsr_event;
    uint8_t lsr_mask;
    int close_pending;
    int ep_lock;
    int ep_read_urb_state;
};

enum {
    EDGE_READ_URB_RUNNING,
    EDGE_READ_URB_STOPPING,
    EDGE_READ_URB_STOPPED
};

#define GFP_ATOMIC 0
#define __func__ __FUNCTION__

#define ECONNRESET 104
#define ENOENT 2
#define ESHUTDOWN 108
#define EPIPE 32

void dev_dbg(const struct device *dev, const char *fmt, ...);
void dev_err(const struct device *dev, const char *fmt, ...);
void usb_serial_debug_data(struct device *dev, const char *function, int length, unsigned char *data);
void handle_new_lsr(struct edgeport_port *edge_port, int flag, uint8_t lsr, uint8_t data);
void edge_tty_recv(struct usb_serial_port *port, unsigned char *data, int length);
int usb_submit_urb(struct urb *urb, int flags);
void spin_lock(int *lock);
void spin_unlock(int *lock);