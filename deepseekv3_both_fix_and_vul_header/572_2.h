#include <string.h>
#include <stdint.h>

struct file;
struct device;

struct v4l2_capability {
    char driver[32];
    char card[32];
    char bus_info[32];
    uint32_t device_caps;
    uint32_t capabilities;
};

struct usb_device {
    char *product;
    struct device *dev;
};

struct zr364xx_camera {
    struct usb_device *udev;
};

#define DRIVER_DESC "zr364xx"
#define V4L2_CAP_VIDEO_CAPTURE 0x00000001
#define V4L2_CAP_READWRITE 0x00000002
#define V4L2_CAP_STREAMING 0x00000004
#define V4L2_CAP_DEVICE_CAPS 0x00000008

static inline const char *dev_name(const struct device *dev) { return ""; }
static inline struct zr364xx_camera *video_drvdata(struct file *file) { return NULL; }
static inline char *strscpy(char *dest, const char *src, size_t count) { return dest; }