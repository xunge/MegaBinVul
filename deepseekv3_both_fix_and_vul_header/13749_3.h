#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ENODEV 19
#define EINVAL 22
#define ENOMEM 12
#define EBUSY 16

#define GFP_KERNEL 0
#define ACM_NR 16
#define ACM_NW 16
#define SINGLE_RX_URB 1
#define NO_UNION_NORMAL 2
#define IGNORE_DEVICE 4
#define NO_CAP_LINE 8
#define SEND_ZERO_PACKET 16
#define CLEAR_HALT_CONDITIONS 32
#define NO_DATA_INTERFACE 64
#define CDC_DATA_INTERFACE_TYPE 0x0A
#define USB_CDC_CAP_LINE 0x02
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)
#define URB_ZERO_PACKET (1 << 1)

typedef uint8_t u8;

struct device {
    int dummy;
};

struct usb_interface_descriptor {
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
};

struct usb_endpoint_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
    struct usb_host_endpoint *endpoint;
    unsigned char *extra;
    int extralen;
};

struct usb_host_endpoint {
    struct usb_endpoint_descriptor desc;
    unsigned char *extra;
    int extralen;
};

struct usb_interface {
    struct device dev;
    struct usb_host_interface *altsetting;
    struct usb_host_interface *cur_altsetting;
};

struct usb_device {
    int dummy;
};

struct usb_device_id {
    unsigned long driver_info;
};

struct usb_cdc_union_desc {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDescriptorSubType;
    uint8_t bMasterInterface0;
    uint8_t bSlaveInterface0;
};

struct usb_cdc_call_mgmt_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDescriptorSubType;
    uint8_t bmCapabilities;
    uint8_t bDataInterface;
};

struct usb_cdc_acm_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDescriptorSubType;
    uint8_t bmCapabilities;
};

struct usb_cdc_country_functional_desc {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDescriptorSubType;
    uint8_t iCountryCodeRelDate;
    uint16_t wCountyCode0;
};

struct usb_cdc_parsed_header {
    struct usb_cdc_union_desc *usb_cdc_union_desc;
    struct usb_cdc_call_mgmt_descriptor *usb_cdc_call_mgmt_descriptor;
    struct usb_cdc_acm_descriptor *usb_cdc_acm_descriptor;
    struct usb_cdc_country_functional_desc *usb_cdc_country_functional_desc;
};

struct usb_cdc_line_coding {
    uint32_t dwDTERate;
    uint8_t bCharFormat;
    uint8_t bParityType;
    uint8_t bDataBits;
};

struct urb {
    unsigned int transfer_flags;
    void *transfer_dma;
};

struct tty_port {
    const void *ops;
};

struct tty_port_operations {
    int dummy;
};

struct usb_driver {
    int dummy;
};

struct tty_driver {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

struct mutex {
    int dummy;
};

struct spinlock {
    int dummy;
};

struct usb_anchor {
    int dummy;
};

struct acm_rb {
    struct acm *instance;
    int index;
    uintptr_t dma;
    u8 *base;
};

struct acm_wb {
    struct urb *urb;
    struct acm *instance;
};

struct acm {
    struct tty_port port;
    struct usb_device *dev;
    struct usb_interface *control;
    struct usb_interface *data;
    unsigned long quirks;
    int ctrl_caps;
    int writesize;
    unsigned int ctrlsize;
    unsigned int readsize;
    unsigned int minor;
    unsigned int rx_buflimit;
    struct spinlock write_lock;
    struct spinlock read_lock;
    struct mutex mutex;
    struct usb_anchor delayed;
    struct urb *ctrlurb;
    u8 *ctrl_buffer;
    uintptr_t ctrl_dma;
    struct acm_rb *read_buffers;
    struct urb *read_urbs[ACM_NR];
    unsigned long read_urbs_free;
    struct acm_wb wb[ACM_NW];
    struct work_struct work;
    struct wait_queue_head wioctl;
    struct usb_cdc_line_coding line;
    u8 *country_codes;
    unsigned int country_code_size;
    int country_rel_date;
    u8 *notification_buffer;
    unsigned int nb_index;
    unsigned int nb_size;
    int combined_interfaces;
    int bInterval;
    struct usb_endpoint_descriptor *in;
    struct usb_endpoint_descriptor *out;
};

static struct usb_driver acm_driver;
static struct tty_driver *acm_tty_driver;
static const struct tty_port_operations acm_port_ops;

static void acm_softint(struct work_struct *work) {}
static void acm_read_bulk_callback(struct urb *urb) {}
static void acm_write_bulk(struct urb *urb) {}
static void acm_ctrl_irq(struct urb *urb) {}

struct device_attribute {
    int dummy;
};

static struct device_attribute dev_attr_bmCapabilities;
static struct device_attribute dev_attr_wCountryCodes;
static struct device_attribute dev_attr_iCountryCodeRelDate;