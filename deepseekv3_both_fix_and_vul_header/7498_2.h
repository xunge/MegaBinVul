#include <stdlib.h>
#include <stdbool.h>

struct hid_device {
    struct {
        struct device *parent;
    } dev;
};

struct hid_device_id;
struct usb_device;
struct usb_interface;
struct device;

struct work_struct {
    void *data;
};

struct delayed_work {
    struct work_struct work;
};

struct elo_priv {
    struct usb_device *usbdev;
    struct delayed_work work;
};

struct workqueue_struct;
extern struct workqueue_struct *wq;

#define ELO_PERIODIC_READ_INTERVAL 0
#define GFP_KERNEL 0
#define HID_CONNECT_DEFAULT 0
#define ENOMEM (-1)
#define EINVAL (-2)

static int hid_is_usb(struct hid_device *hdev) { return 1; }
static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void INIT_DELAYED_WORK(struct delayed_work *dwork, void (*func)(struct work_struct *)) {}
static struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static struct usb_interface *to_usb_interface(struct device *dev) { return NULL; }
static struct usb_device *usb_get_dev(struct usb_device *udev) { return udev; }
static void hid_set_drvdata(struct hid_device *hdev, void *data) {}
static int hid_parse(struct hid_device *hdev) { return 0; }
static void hid_err(struct hid_device *hdev, const char *fmt, ...) {}
static int hid_hw_start(struct hid_device *hdev, int connect_mask) { return 0; }
static void hid_info(struct hid_device *hdev, const char *fmt, ...) {}
static void queue_delayed_work(struct workqueue_struct *wq, struct delayed_work *dwork, unsigned long delay) {}
static bool elo_broken_firmware(struct usb_device *udev) { return false; }
static void elo_work(struct work_struct *work) {}