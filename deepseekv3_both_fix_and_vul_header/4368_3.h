#include <stdlib.h>
#include <string.h>

#define AIPTEK_PROGRAMMABLE_DELAY_50     50
#define AIPTEK_PROGRAMMABLE_DELAY_400    400
#define AIPTEK_PROGRAMMABLE_DELAY_25     25
#define AIPTEK_PROGRAMMABLE_DELAY_100    100
#define AIPTEK_PROGRAMMABLE_DELAY_200    200
#define AIPTEK_PROGRAMMABLE_DELAY_300    300

#define AIPTEK_POINTER_EITHER_MODE       0
#define AIPTEK_COORDINATE_ABSOLUTE_MODE  1
#define AIPTEK_TOOL_BUTTON_PEN_MODE      2
#define AIPTEK_TILT_DISABLE              0
#define AIPTEK_MOUSE_LEFT_BUTTON         0
#define AIPTEK_MOUSE_MIDDLE_BUTTON       1
#define AIPTEK_MOUSE_RIGHT_BUTTON        2
#define AIPTEK_STYLUS_UPPER_BUTTON       3
#define AIPTEK_STYLUS_LOWER_BUTTON       4

#define AIPTEK_TILT_MIN                  -128
#define AIPTEK_TILT_MAX                  127
#define AIPTEK_WHEEL_MIN                 0
#define AIPTEK_WHEEL_MAX                 63

#define AIPTEK_PACKET_LENGTH             8
#define MSC_SERIAL                       0
#define URB_NO_TRANSFER_DMA_MAP          1

static int programmableDelay;
static int jitterDelay;

struct device {
    struct device *parent;
    void *kobj;
};

struct usb_device {
    struct device dev;
};

struct usb_interface {
    struct device dev;
    struct {
        struct {
            struct {
                int bInterfaceNumber;
                int bNumEndpoints;
            } desc;
            struct {
                struct {
                    int bEndpointAddress;
                    int bInterval;
                } desc;
            } endpoint[1];
        } altsetting[1];
    };
};

struct usb_device_id {};
struct usb_endpoint_descriptor {};

struct input_dev {
    char *name;
    char *phys;
    struct device dev;
    void *evbit;
    void *absbit;
    void *relbit;
    void *mscbit;
    void *keybit;
    int (*open)(struct input_dev *);
    void (*close)(struct input_dev *);
    void *p;
};

struct urb {
    struct usb_device *dev;
    unsigned char *transfer_buffer;
    unsigned long transfer_dma;
    unsigned int transfer_flags;
};

struct aiptek_settings {
    int pointerMode;
    int coordinateMode;
    int toolMode;
    int xTilt;
    int yTilt;
    int mouseButtonLeft;
    int mouseButtonMiddle;
    int mouseButtonRight;
    int stylusButtonUpper;
    int stylusButtonLower;
    int jitterDelay;
    int programmableDelay;
};

struct aiptek_features {
    char usbPath[64];
};

struct aiptek {
    struct usb_device *usbdev;
    struct usb_interface *intf;
    struct input_dev *inputdev;
    struct urb *urb;
    unsigned char *data;
    unsigned long data_dma;
    int ifnum;
    int inDelay;
    int endDelay;
    int previousJitterable;
    int lastMacro;
    struct aiptek_settings curSetting;
    struct aiptek_settings newSetting;
    struct aiptek_features features;
};

static const int eventTypes[] = { 1, 3, 2, 4 };
static const int absEvents[] = { 0, 1, 24, 26, 27, 8 };
static const int relEvents[] = { 0, 1, 8 };
static const int buttonEvents[] = { 0x110, 0x111, 0x112, 0x14a, 0x14b, 0x14c };
static const int macroKeyEvents[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

static struct {
    int dummy;
} aiptek_attribute_group;

static int aiptek_open(struct input_dev *inputdev) { return 0; }
static void aiptek_close(struct input_dev *inputdev) {}
static void aiptek_irq(struct urb *urb) {}
static int aiptek_program_tablet(struct aiptek *aiptek) { return 0; }

#define GFP_KERNEL 0
#define GFP_ATOMIC 0
#define ENOMEM 12
#define EINVAL 22
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define __set_bit(nr, addr) ((void)(nr), ((void)(addr)))
#define dev_warn(dev, fmt, ...) ((void)(dev))
#define dev_err(dev, fmt, ...) ((void)(dev))
#define dev_info(dev, fmt, ...) ((void)(dev))
#define interface_to_usbdev(intf) ((struct usb_device *)NULL)
#define usb_alloc_coherent(dev, size, flags, dma) malloc(size)
#define usb_free_coherent(dev, size, addr, dma) free(addr)
#define usb_alloc_urb(iso_packets, flags) malloc(sizeof(struct urb))
#define usb_free_urb(urb) free(urb)
#define input_allocate_device() ((struct input_dev *)malloc(128))
#define input_free_device(dev) free(dev)
#define input_register_device(dev) 0
#define input_set_drvdata(dev, data) ((void)((dev)->p = (data)))
#define input_set_abs_params(dev, abs, min, max, fuzz, flat) ((void)0)
#define input_abs_get_max(dev, abs) 0
#define usb_make_path(dev, buf, size) strcpy(buf, "usb-path")
#define usb_to_input_id(dev, id) ((void)0)
#define usb_rcvintpipe(dev, endpoint) 0
#define usb_fill_int_urb(urb, dev, pipe, buf, len, complete, context, interval) ((void)0)
#define usb_set_intfdata(intf, data) ((void)0)
#define sysfs_create_group(kobj, grp) 0
#define sysfs_remove_group(kobj, grp) ((void)0)
#define kzalloc(size, flags) calloc(1, size)
#define kfree(ptr) free(ptr)
#define strlcat(dst, src, size) strncat(dst, src, size - strlen(dst) - 1)