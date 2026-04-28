#include <stdint.h>
#include <stdlib.h>

#define KLSI_STATUSBUF_LEN 2
#define KL5KUSB105A_SIO_POLL 0x01
#define GFP_KERNEL 0
#define ENOMEM 12
#define EIO 5
#define USB_TYPE_VENDOR 0x40
#define USB_DIR_IN 0x80

typedef uint8_t u8;
typedef uint8_t __u8;
typedef uint16_t __u16;

struct device {
    struct device *dev;
};

struct usb_device {
    struct device dev;
};

struct usb_serial {
    struct usb_device *dev;
};

struct usb_serial_port {
    struct usb_serial *serial;
    struct device dev;
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int usb_control_msg(struct usb_device *dev, int pipe, __u8 request, __u8 requesttype, __u16 value, __u16 index, void *data, __u16 size, int timeout) { return 0; }
static inline int usb_rcvctrlpipe(struct usb_device *dev, int endpoint) { return 0; }
static inline __u16 get_unaligned_le16(const void *p) { return *(__u16 *)p; }
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline unsigned long klsi_105_status2linestate(__u16 status) { return 0; }