#include <stddef.h>

struct device {
    struct device *dev;
};

struct usbip_device {
    int side;
    int tcp_socket;
};

struct urb {
    unsigned int pipe;
    int transfer_buffer_length;
    int actual_length;
    void *transfer_buffer;
    struct device *dev;
};

#define USBIP_STUB 0
#define SDEV_EVENT_ERROR_TCP 0
#define VDEV_EVENT_ERROR_TCP 0
#define EPIPE 32
#define USB_DIR_IN 0x80

static inline int usb_pipein(unsigned int pipe) { return (pipe & USB_DIR_IN) != 0; }
static inline int usb_pipeout(unsigned int pipe) { return !usb_pipein(pipe); }

int usbip_recv(int sockfd, void *buff, size_t len);
void usbip_event_add(struct usbip_device *ud, unsigned long event);
void dev_err(const struct device *dev, const char *fmt, ...);