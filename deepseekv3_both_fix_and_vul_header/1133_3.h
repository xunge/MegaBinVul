#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define STATE_DEV_OPENED 0
#define USB_DT_CONFIG_SIZE 9
#define USB_DT_DEVICE_SIZE 18
#define USB_DT_CONFIG 2
#define USB_DT_DEVICE 1
#define EINVAL 22
#define EFAULT 14
#define PAGE_SIZE 4096
#define USB_SPEED_HIGH 3
#define USB_SPEED_FULL 2

typedef int32_t ssize_t;
typedef uint32_t u32;
typedef int64_t loff_t;
#define __user

struct usb_config_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
};

struct usb_device_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bNumConfigurations;
};

struct file {
    void *private_data;
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
} gadgetfs_driver;

extern ssize_t ep0_write(struct file *fd, const char *buf, size_t len, loff_t *ptr);
extern bool is_valid_config(struct usb_config_descriptor *config, unsigned total);
extern char *shortname;
extern int usb_gadget_probe_driver(struct usb_gadget_driver *driver);
extern void *memdup_user(const void *src, size_t len);
extern void kfree(void *ptr);
extern int copy_from_user(void *dst, const void *src, unsigned long len);
extern void spin_lock_irq(int *lock);
extern void spin_unlock_irq(int *lock);
extern void pr_debug(const char *fmt, ...);

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline uint16_t cpu_to_le16(uint16_t val) { return val; }
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(intptr_t)(x))