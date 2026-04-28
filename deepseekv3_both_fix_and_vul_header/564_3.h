#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_LENGTH 64
#define GFP_KERNEL 0
#define ENOMEM 12
#define ENODEV 19
#define HID_REQ_GET_REPORT 0x01
#define USB_TYPE_CLASS (0x01 << 5)
#define USB_RECIP_INTERFACE 0x01
#define USB_DIR_IN 0x80
#define BAND_FM 0
#define VFL_TYPE_RADIO 1
#define V4L2_CAP_TUNER 0x02
#define V4L2_CAP_RADIO 0x04

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;

struct device {
    const char *name;
};

struct usb_interface {
    struct device dev;
};

struct usb_device {
    int dummy;
};

struct usb_device_id {
    uint16_t idVendor;
    uint16_t idProduct;
};

struct v4l2_device {
    const char *name;
    void (*release)(struct v4l2_device *);
};

struct v4l2_file_operations {
    int dummy;
};

struct v4l2_ioctl_ops {
    int dummy;
};

struct video_device {
    char name[32];
    struct v4l2_device *v4l2_dev;
    const struct v4l2_file_operations *fops;
    const struct v4l2_ioctl_ops *ioctl_ops;
    struct mutex *lock;
    void (*release)(struct video_device *);
    uint32_t device_caps;
};

struct mutex {
    int dummy;
};

struct raremono_device {
    struct usb_device *usbdev;
    struct usb_interface *intf;
    struct v4l2_device v4l2_dev;
    struct video_device vdev;
    struct mutex lock;
    unsigned char *buffer;
};

static const struct v4l2_file_operations usb_raremono_fops = {0};
static const struct v4l2_ioctl_ops usb_raremono_ioctl_ops = {0};

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe, __u8 request,
                                 __u8 requesttype, __u16 value, __u16 index,
                                 void *data, __u16 size, int timeout) { return 0; }
static inline uint16_t get_unaligned_be16(const void *p) { return 0; }
static inline void msleep(unsigned int msecs) { usleep(msecs * 1000); }
static inline void dev_info(const struct device *dev, const char *fmt, ...) {}
static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
static inline int v4l2_device_register(struct device *dev, struct v4l2_device *v4l2_dev) { return 0; }
static inline void mutex_init(struct mutex *lock) {}
static inline void strscpy(char *dest, const char *src, size_t count) { strncpy(dest, src, count); }
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void video_set_drvdata(struct video_device *vdev, void *data) {}
static inline int video_register_device(struct video_device *vdev, int type, int nr) { return 0; }
static inline const char *video_device_node_name(struct video_device *vdev) { return ""; }
static inline void v4l2_device_unregister(struct v4l2_device *v4l2_dev) {}
static inline void kfree(void *ptr) { free(ptr); }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void video_device_release_empty(struct video_device *vdev) {}
static inline void raremono_device_release(struct v4l2_device *v4l2_dev) {}
static inline void raremono_cmd_main(struct raremono_device *radio, int band, int freq) {}