#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define STATE_DEV_OPENED 0
#define USB_DT_CONFIG_SIZE 9
#define USB_DT_DEVICE_SIZE 18
#define PAGE_SIZE 4096
#define EINVAL 22
#define EFAULT 14
#define USB_DT_CONFIG 2
#define USB_DT_DEVICE 1
#define USB_SPEED_HIGH 3
#define USB_SPEED_FULL 2

typedef int32_t ssize_t;
typedef uint32_t u32;
typedef int64_t loff_t;

struct file {
    void *private_data;
};

struct usb_config_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t bMaxPower;
};

struct usb_device_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
};

struct dev_data {
    int lock;
    int state;
    void *buf;
    struct usb_config_descriptor *config;
    struct usb_config_descriptor *hs_config;
    struct usb_device_descriptor *dev;
    bool gadget_registered;
};

struct usb_gadget_driver {
    int max_speed;
};

struct usb_gadget_driver gadgetfs_driver;

#define __user
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define pr_debug(fmt, ...)

static void spin_lock_irq(int *lock) {}
static void spin_unlock_irq(int *lock) {}
static int copy_from_user(void *dst, const void *src, size_t len) { return 0; }
static void *memdup_user(const void *src, size_t len) { return NULL; }
static void kfree(void *ptr) {}
static int is_valid_config(void *config, unsigned total) { return 1; }
static uint16_t le16_to_cpu(uint16_t val) { return val; }
static uint16_t cpu_to_le16(uint16_t val) { return val; }
static int usb_gadget_probe_driver(struct usb_gadget_driver *driver) { return 0; }
static ssize_t ep0_write(struct file *fd, const void *buf, size_t len, void *ptr) { return 0; }