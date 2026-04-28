#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

struct device {
    const char *name;
};

struct usb_endpoint_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
};

struct usb_interface {
    struct device dev;
    void *cur_altsetting;
    int minor;
};

struct usb_device_id {
    uint16_t match_flags;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice_lo;
    uint16_t bcdDevice_hi;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t bInterfaceNumber;
};

struct usb_device {
    uint8_t dummy;
};

struct usb_host_interface {
    struct {
        uint8_t bNumEndpoints;
    } desc;
    struct {
        struct usb_endpoint_descriptor desc;
    } endpoint[8];
};

struct lego_usb_tower {
    struct usb_device *udev;
    int open_count;
    char *read_buffer;
    size_t read_buffer_length;
    size_t read_packet_length;
    pthread_spinlock_t read_buffer_lock;
    unsigned long packet_timeout_jiffies;
    unsigned long read_last_arrival;
    pthread_cond_t read_wait;
    pthread_cond_t write_wait;
    char *interrupt_in_buffer;
    struct usb_endpoint_descriptor *interrupt_in_endpoint;
    void *interrupt_in_urb;
    int interrupt_in_running;
    int interrupt_in_done;
    char *interrupt_out_buffer;
    struct usb_endpoint_descriptor *interrupt_out_endpoint;
    void *interrupt_out_urb;
    int interrupt_out_busy;
    int interrupt_in_interval;
    int interrupt_out_interval;
    int minor;
    pthread_mutex_t lock;
};

struct tower_get_version_reply {
    uint8_t major;
    uint8_t minor;
    uint16_t build_no;
};

static int packet_timeout;
static int read_buffer_size;
static int write_buffer_size;
static int interrupt_in_interval;
static int interrupt_out_interval;

static void *tower_class;
static int LEGO_USB_TOWER_MINOR_BASE;
#define LEGO_USB_TOWER_REQUEST_GET_VERSION 0x30
#define USB_MAJOR 180
#define GFP_KERNEL 0
#define ENOMEM 12
#define USB_TYPE_VENDOR 0x40
#define USB_DIR_IN 0x80
#define USB_RECIP_DEVICE 0x00

static void *interface_to_usbdev(struct usb_interface *interface) { return NULL; }
static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void mutex_init(pthread_mutex_t *mutex) { pthread_mutex_init(mutex, NULL); }
static void spin_lock_init(pthread_spinlock_t *lock) { pthread_spin_init(lock, 0); }
static unsigned long msecs_to_jiffies(unsigned int msecs) { return msecs; }
static unsigned long jiffies = 0;
static void init_waitqueue_head(pthread_cond_t *cond) { pthread_cond_init(cond, NULL); }
static int usb_endpoint_xfer_int(struct usb_endpoint_descriptor *epd) { return epd->bmAttributes & 0x03; }
static int usb_endpoint_dir_in(struct usb_endpoint_descriptor *epd) { return epd->bEndpointAddress & 0x80; }
static void dev_err(struct device *dev, const char *fmt, ...) {}
static uint16_t usb_endpoint_maxp(struct usb_endpoint_descriptor *epd) { return epd->wMaxPacketSize; }
static void *usb_alloc_urb(int iso_packets, int mem_flags) { return NULL; }
static void usb_set_intfdata(struct usb_interface *interface, void *data) {}
static int usb_register_dev(struct usb_interface *interface, void *class) { return 0; }
static void dev_info(struct device *dev, const char *fmt, ...) {}
static int usb_control_msg(void *dev, unsigned int pipe, uint8_t request, uint8_t requesttype,
                          uint16_t value, uint16_t index, void *data, uint16_t size, int timeout) { return 0; }
static unsigned int usb_rcvctrlpipe(void *dev, unsigned int endpoint) { return 0; }
static uint16_t le16_to_cpu(uint16_t x) { return x; }
static void tower_delete(struct lego_usb_tower *dev) {}