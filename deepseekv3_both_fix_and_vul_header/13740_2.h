#include <stddef.h>

struct usb_interface;
struct usb_device;

struct adu_device {
    struct usb_device *udev;
    int mtx;
    int open_count;
};

static int adutux_mutex;
static int adu_class;

static struct adu_device* usb_get_intfdata(struct usb_interface *interface);
static void usb_deregister_dev(struct usb_interface *interface, int *class);
static void usb_set_intfdata(struct usb_interface *interface, void *data);
static void mutex_lock(int *mutex);
static void mutex_unlock(int *mutex);
static void adu_delete(struct adu_device *dev);