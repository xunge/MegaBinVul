#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define RAZER_USB_REPORT_LEN 90
#define HID_REQ_GET_REPORT 0x01
#define USB_TYPE_CLASS 0x01
#define USB_RECIP_INTERFACE 0x01
#define USB_DIR_IN 0x80
#define USB_CTRL_SET_TIMEOUT 5000
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define KERN_WARNING "4"
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef uint8_t __u8;
typedef uint16_t __u16;

struct usb_device;
struct razer_report {
    uint8_t data_size;
    uint8_t arguments[80];
};

extern int razer_send_control_msg(struct usb_device *usb_dev, struct razer_report* request_report, unsigned int report_index, unsigned long wait_min, unsigned long wait_max);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int usb_control_msg(struct usb_device *dev, unsigned int pipe, __u8 request, __u8 requesttype, __u16 value, __u16 index, void *data, __u16 size, int timeout);
extern unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint);
extern int printk(const char *fmt, ...);
extern int WARN_ONCE(int condition, const char *fmt, ...);